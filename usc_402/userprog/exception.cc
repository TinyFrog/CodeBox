


// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user cadode explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include <stdio.h>
#include <iostream>
#include "../network/post.h"
#include "network.h"
#include "stdlib.h"
#include "list.h"
#include <ctime>
#define CREATE_LOCK      'a'
#define ACQUIRE          'b'
#define RELEASE          'c'
#define DESTROY_LOCK     'd'
#define CREATE_CV        'e'
#define SIGNAL           'f'
#define WAIT             'g'
#define BROADCAST	 'h'
#define DESTROY_CV	 'i'
#define CREATE_MONITOR   'j'
#define RETRIEVE_MONITOR 'k'
#define SET_MONITOR      'l'
#define START_SIMULATION 'm'

typedef unsigned char byte;

using namespace std;

void network_thread(int tid);
struct MessageEntry{
	int ntID;
	int time;
	string message;
	char *RT;
	char *argument1;
	char *argument2;
};
struct TimeStamp{
	int ntID;
	int time;
};
struct ntConditionEntry{

	List *waitQueue;
	int lock;
	int deleteCounter; 
};  

struct ntLockEntry{

	List *waitQueue;
	int state;
	int owner;
	int deleteCounter;
}; 

struct ntMonitorEntry{

	int value;
}; 

/* might have mailbox # in next project*/
struct ReplyEntry{

	int machineId;
	int	mailboxNum;

};


int getTimeStamp(){
                  timeval tim;
             gettimeofday(&tim, NULL);
             double t1=tim.tv_sec%1000+(tim.tv_usec/1000000.0);
	     int ts= t1*10000;
	     return ts;	

}



#ifdef NETWORK

PacketHeader outPktHdr, inPktHdr;
MailHeader outMailHdr, inMailHdr;

char *data = new char[MaxMailSize];
char buffer[MaxMailSize];

char *requestType;
time_t myTimeStamp;
int myID;    //used by userprog and get modified at each send to his network thread 
//hahahaha

void sendPacket(char *data){

	outPktHdr.to = netname;		
	outMailHdr.to = currentThread->mailBox+1;
	outMailHdr.from = currentThread->mailBox;
	outMailHdr.length = strlen(data) + 1;

	bool success = postOffice->Send(outPktHdr, outMailHdr, data); 

	if ( !success ) {
		printf("The postOffice Send failed. You must not have the other Nachos running. Terminating Nachos.\n");
		interrupt->Halt();
	}

}

void sendToReg(char *data, int mb){

	//printf("SEND TO SERVER!\n");
	outPktHdr.to = 0;		
	outMailHdr.to = 0;
	outMailHdr.from = mb;
	outMailHdr.length = strlen(data) + 1;

	bool success = postOffice->Send(outPktHdr, outMailHdr, data); 

	// printf("BACK!!!!!!!!\n");
	if ( !success ) {
		printf("The postOffice Send failed. You must not have the other Nachos running. Terminating Nachos.\n");
		interrupt->Halt();
	}

}






#endif

int myexp ( int count ) {
	int i, val=1;
	for (i=0; i<count; i++ ) {
		val = val * 10;
	}
	return val;
}
void itoa( char arr[], int size, int val ) {
	int i, max, dig, subval, loc;
	for (i=0; i<size; i++ ) {
		arr[i] = '\0';
	}

	for ( i=1; i<=2; i++ ) {
		if (( val / myexp(i) ) == 0 ) {
			max = i-1;
			break;
		}
	}

	subval = 0;
	loc = 0;
	for ( i=max; i>=0; i-- ) {
		dig = 48 + ((val-subval) / myexp(i));
		subval = (dig-48) * myexp(max);
		arr[loc] = dig;
		loc++;
	}

	return;
}

int copyin(unsigned int vaddr, int len, char *buf) {
	// Copy len bytes from the current thread's virtual address vaddr.
	// Return the number of bytes so read, or -1 if an error occors.
	// Errors can generally mean a bad virtual address was passed in.
	bool result;
	int n=0;			// The number of bytes copied in
	int *paddr = new int;

	while ( n >= 0 && n < len) {
		result = machine->ReadMem( vaddr, 1, paddr );
		while(!result) // FALL 09 CHANGES
		{
			result = machine->ReadMem( vaddr, 1, paddr ); // FALL 09 CHANGES: TO HANDLE PAGE FAULT IN THE ReadMem SYS CALL
		}	

		buf[n++] = *paddr;

		if ( !result ) {
			//translation failed
			return -1;
		}

		vaddr++;
	}

	delete paddr;
	return len;
}

int copyout(unsigned int vaddr, int len, char *buf) {
	// Copy len bytes to the current thread's virtual address vaddr.
	// Return the number of bytes so written, or -1 if an error
	// occors.  Errors can generally mean a bad virtual address was
	// passed in.
	bool result;
	int n=0;			// The number of bytes copied in

	while ( n >= 0 && n < len) {
		// Note that we check every byte's address
		result = machine->WriteMem( vaddr, 1, (int)(buf[n++]) );

		if ( !result ) {
			//translation failed
			return -1;
		}

		vaddr++;
	}

	return n;
}

void Create_Syscall(unsigned int vaddr, int len) {
	// Create the file with the name in the user buffer pointed to by
	// vaddr.  The file name is at most MAXFILENAME chars long.  No
	// way to return errors, though...
	char *buf = new char[len+1];	// Kernel buffer to put the name in

	if (!buf) return;

	if( copyin(vaddr,len,buf) == -1 ) {
		printf("%s","Bad pointer passed to Create\n");
		delete buf;
		return;
	}

	buf[len]='\0';

	fileSystem->Create(buf,0);
	delete[] buf;
	return;
}

int Open_Syscall(unsigned int vaddr, int len) {
	// Open the file with the name in the user buffer pointed to by
	// vaddr.  The file name is at most MAXFILENAME chars long.  If
	// the file is opened successfully, it is put in the address
	// space's file table and an id returned that can find the file
	// later.  If there are any errors, -1 is returned.
	char *buf = new char[len+1];	// Kernel buffer to put the name in
	OpenFile *f;			// The new open file
	int id;				// The openfile id

	if (!buf) {
		printf("%s","Can't allocate kernel buffer in Open\n");
		return -1;
	}

	if( copyin(vaddr,len,buf) == -1 ) {
		printf("%s","Bad pointer passed to Open\n");
		delete[] buf;
		return -1;
	}

	buf[len]='\0';

	f = fileSystem->Open(buf);
	delete[] buf;

	if ( f ) {
		if ((id = currentThread->space->fileTable.Put(f)) == -1 )
			delete f;
		return id;
	}
	else
		return -1;
}

void Write_Syscall(unsigned int vaddr, int len, int id) {
	// Write the buffer to the given disk file.  If ConsoleOutput is
	// the fileID, data goes to the synchronized console instead.  If
	// a Write arrives for the synchronized Console, and no such
	// console exists, create one. For disk files, the file is looked
	// up in the current address space's open file table and used as
	// the target of the write.

	char *buf;		// Kernel buffer for output
	OpenFile *f;	// Open file for output

	if ( id == ConsoleInput) return;

	if ( !(buf = new char[len]) ) {
		printf("%s","Error allocating kernel buffer for write!\n");
		return;
	} else {
		if ( copyin(vaddr,len,buf) == -1 ) {
			printf("%s","Bad pointer passed to to write: data not written\n");
			delete[] buf;
			return;
		}
	}

	if ( id == ConsoleOutput) {
		for (int ii=0; ii<len; ii++) {
			printf("%c",buf[ii]);
		}

	} else {
		if ( (f = (OpenFile *) currentThread->space->fileTable.Get(id)) ) {
			f->Write(buf, len);
		} else {
			printf("%s","Bad OpenFileId passed to Write\n");
			len = -1;
		}
	}

	delete[] buf;
}

int Read_Syscall(unsigned int vaddr, int len, int id) {
	// Write the buffer to the given disk file.  If ConsoleOutput is
	// the fileID, data goes to the synchronized console instead.  If
	// a Write arrives for the synchronized Console, and no such
	// console exists, create one.    We reuse len as the number of bytes
	// read, which is an unnessecary savings of space.
	char *buf;		// Kernel buffer for input
	OpenFile *f;	// Open file for output

	if ( id == ConsoleOutput) return -1;

	if ( !(buf = new char[len]) ) {
		printf("%s","Error allocating kernel buffer in Read\n");
		return -1;
	}

	if ( id == ConsoleInput) {
		//Reading from the keyboard
		scanf("%s", buf);

		if ( copyout(vaddr, len, buf) == -1 ) {
			printf("%s","Bad pointer passed to Read: data not copied\n");
		}
	} else {
		if ( (f = (OpenFile *) currentThread->space->fileTable.Get(id)) ) {
			len = f->Read(buf, len);
			if ( len > 0 ) {
				//Read something from the file. Put into user's address space
				if ( copyout(vaddr, len, buf) == -1 ) {
					printf("%s","Bad pointer passed to Read: data not copied\n");
				}
			}
		} else {
			printf("%s","Bad OpenFileId passed to Read\n");
			len = -1;
		}
	}

	delete[] buf;
	return len;
}

void Close_Syscall(int fd) {
	// Close the file associated with id fd.  No error reporting.
	OpenFile *f = (OpenFile *) currentThread->space->fileTable.Remove(fd);

	if ( f ) {
		delete f;
	} else {
		printf("%s","Tried to close an unopen file\n");
	}
}


void Yield_Syscall(){
	currentThread->Yield();
}



#ifdef NETWORK

void StartSimulation_Syscall(){
	requestType="m";
	sprintf(data,"%s",requestType);
	//ask SHAOBO
	/*
	outPktHdr.to = netname;		//mahcine ID
	outMailHdr.to = currentThread->mailBox+1;  //mailbox NO
	outMailHdr.from = currentThread->mailBox;*/


	outPktHdr.to = netname;		//mahcine ID
	outMailHdr.to = currentThread->mailBox+1;  //mailbox NO
	outMailHdr.from = currentThread->mailBox;
	outMailHdr.length = strlen(data) + 1;


	//printf("before SEND %d \n",currentThread->mailBox+1);

	bool success = postOffice->Send(outPktHdr, outMailHdr, data); 

	//printf("after SEND\n");
	if ( !success ) {
		printf("The postOffice Send failed. You must not have the other Nachos running. Terminating Nachos.\n");
		interrupt->Halt();
	}


	postOffice->Receive(currentThread->mailBox,&inPktHdr,&inMailHdr,buffer);


	printf("UP starts!->its net Thread num: %d\n", inMailHdr.from);
	return;



}


int CreateLock_Syscall(int vaddr, int len){

	/* should rv be local variable or global variable?? */
	int rv;

	char *lockNameBuf = new char[len];	

	if(!lockNameBuf) 
		return -1;

	/* Get the Lock Name...wierd character appears sometimes.*/
	if( copyin(vaddr,len,lockNameBuf) == -1 ) {
		printf("%s","Wrong name passed to Create\n");
		delete lockNameBuf;
		return -1;
	}

	lockNameBuf[len] = '\0';
	printf("what's in the lockName-%s\n",lockNameBuf);

	requestType = "a";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%s",myTimeStamp,myID,requestType,lockNameBuf);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);
	printf("uerprog %d Got LOCK INDEX \"%s\" from NT\n",netname*100+currentThread->mailBox,buffer);
	fflush(stdout);

	rv =atoi(buffer);

	/* a way to clear the buffer */
	buffer[0] = '\0';
	return rv;

}


void DestroyLock_Syscall(int LockID) {


	requestType = "d";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d",myTimeStamp,myID,requestType,LockID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox+1, &inPktHdr, &inMailHdr, buffer);

	if(strcmp("notyet",buffer)==0)
		printf("The Lock cannot be deleted now! Someone else doesnt want it die!\n");
	if(strcmp("deleted",buffer)==0)
		printf("DESTROY LOCK from NT SUCCESSFULLY\n");


	fflush(stdout);

	buffer[0] = '\0';

}

void AcquireLock_Syscall(int LockID){

	requestType = "b";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d",myTimeStamp,myID,requestType,LockID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);


	printf("ACQUIRE LOCK from NT SUCCESSFULLY\n");
	fflush(stdout);

	buffer[0] = '\0';

}

void ReleaseLock_Syscall(int LockID){

	requestType = "c";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d",myTimeStamp,myID,requestType,LockID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	if(strcmp(buffer,"denied") == 0){

		printf("I CANNOT release this Lock. The lock owner is not me!\n");

	}else if(strcmp(buffer,"nosuchlock")==0){

		printf("No such Lock!!\n");

	}else{

		printf("RELEASE LOCK from NT SUCCESSFULLY\n");
		fflush(stdout);

	}

	buffer[0] = '\0';

}

int CreateCondition_Syscall(unsigned int vaddr,int len){

	int rv;
	char *cvNameBuf = new char[len];	

	if(!cvNameBuf) 
		return -1;

	if( copyin(vaddr,len,cvNameBuf) == -1 ) {
		printf("%s","Wrong name passed to Create\n");
		delete cvNameBuf;
		return -1;
	}


	/* just to get rid of the wierd char at the end of buffer */
	cvNameBuf[len] = '\0';
	printf("what's in the cvName--%s\n",cvNameBuf);

	requestType = "e";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%s",myTimeStamp,myID,requestType,cvNameBuf);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);
	printf("Got CV_INDEX \"%s\" from NT\n",buffer);

	rv =atoi(buffer);

	/* a way to clear the buffer */
	buffer[0] = '\0';

	return rv;

}


void WaitCondition_Syscall(int ConID, int LockID) {

	requestType = "g";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d,%d",myTimeStamp,myID,requestType,ConID,LockID);

	sendPacket(data);

	printf("start WAITing \n");

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	printf("WAIT finished, be signaled from NT SUCCESSFULLY\n");
	fflush(stdout);

	buffer[0] = '\0';

}


void SignalCondition_Syscall(int ConID, int LockID) {


	requestType = "f";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d,%d",myTimeStamp,myID,requestType,ConID,LockID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	printf("SIGNAL from NT SUCCESSFULLY\n");
	fflush(stdout);
	buffer[0] = '\0';

}


void BroadcastCondition_Syscall(int ConID, int LockID) {

	requestType = "h";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox;
	sprintf(data,"%d,%d,%s,%d,%d",myTimeStamp,myID,requestType,ConID,LockID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	printf("BROADCAST from NT SUCCESSFULLY\n");
	fflush(stdout);
	buffer[0] = '\0';

}


void DestroyCondition_Syscall(int ConID) {

	requestType = "i";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d",myTimeStamp,myID,requestType,ConID);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	if(strcmp("notyet",buffer)==0)
		printf("The Condition cannot be deleted now! Someone else doesnt want it die!\n");
	if(strcmp("deleted",buffer)==0)
		printf("DESTROY CONDITION from NT SUCCESSFULLY\n");

	fflush(stdout);

	buffer[0] = '\0';

}

int CreateMonitor_Syscall(int vaddr, int len){
	int mid;

	char *monitorNameBuf = new char[len];	

	if(!monitorNameBuf) 
		return -1;

	if( copyin(vaddr,len,monitorNameBuf) == -1 ) {
		printf("%s","Wrong name passed to Create\n");
		delete monitorNameBuf;
		return -1;
	}

	monitorNameBuf[len] = '\0';

	requestType = "j";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%s",myTimeStamp,myID,requestType,monitorNameBuf);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	mid = atoi(buffer);

	printf("CREATE MONITOR from NT SUCCESSFULLY\n");
	fflush(stdout);

	return mid;
}


int RetrieveMonitor_Syscall(int mid){

	int mValue;
	requestType = "k";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d",myTimeStamp,myID,requestType,mid);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	mValue = atoi(buffer);

	printf("The retrieve value for Monitor-%d is %d\n",mid,mValue);

	printf("RETRIEVE MONITOR from NT SUCCESSFULLY\n");
	fflush(stdout);

	return mValue;


}

void SetMonitor_Syscall(int mid, int mValue){
	requestType = "l";
	myTimeStamp=getTimeStamp();
	myID=netname*100+currentThread->mailBox+1;
	sprintf(data,"%d,%d,%s,%d,%d",myTimeStamp,myID,requestType,mid,mValue);

	sendPacket(data);

	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);

	printf("SET MONITOR from NT SUCCESSFULLY\n");
	fflush(stdout);

}


#endif 


/* defined by Super . SB*/
void kernel_thread(int vaddr){


	//	printf("access to kernel_thread \n");

	machine->WriteRegister(PCReg, vaddr);
	machine->WriteRegister(NextPCReg, vaddr+4);


	int pid= currentThread->getParentProcess()->getPID();
	int newBottomOfStackVaddr = currentThread->space->IncrementStackSpace(pid);

	machine->WriteRegister(StackReg, newBottomOfStackVaddr);

	/*
	update the thread:startVPN here.
	the return value of currentThread->space->IncrementStackSpace() is virtual address 
	not the vaddr page num
	maybe divRoundUp is needed.

	*/

	/*  

	this currentThread,, is already the new thread.

	*/

	int sVPN = divRoundUp( (newBottomOfStackVaddr - 1024),PageSize);

	//printf("Is this vpn %d the one printf before??\n",sVPN);

	currentThread->startVPN = sVPN;


	currentThread->space->RestoreState();

	machine->Run();


}


void Fork_Syscall(int vaddr){

	PLock->Acquire();
	printf("Fork_Syscall is invoked!!!!!!!!!!!!!!!!!!!!!!!!\n");

	Thread *t = new Thread("Thread");
	t->space = currentThread->space;

	Process *p = currentThread->getParentProcess();
	t -> setParentProcess(p);
	p->ChildThreadCounter++;

	t->Fork((VoidFunctionPtr)kernel_thread,vaddr);
	PLock->Acquire();
}

void Exit_Syscall(int status ){
	PLock->Acquire();
	Process *p = currentThread->getParentProcess();
	//int tid = currentThread->getTID();
	//int ctc = p->removeThread(tid);  // the left thread after the remove action
	p->ChildThreadCounter--;
	int ctc= p->ChildThreadCounter;

	AddrSpace* temp = p->getAddrSpace();


	if(ctc==0){//mean this is the last thread in this process, delete process
		printf("\n---------------------------------------------\n");
		printf("Stop last thread and its parent process, get RESULT: %d! ",status);
		printf("\n---------------------------------------------\n");
		//need add this!!!!!!!
		ProcessTable->Remove(p->getPID());

		temp->DeleteSpace();
		delete temp;
		//p->~Process();// delete all lock and thread from table


		//need lock
		processCounter--;// now is global ,could also for processTable

		//Lock->Acquire();  this is for the processtable 
		if(processCounter==0){
			printf("No more processes are working\n halt nachos!\n");

			/*
			#ifdef NETWORK
			postOffice->finish();
			#endif
			*/
			currentThread->Finish();
			PLock->Release();

			interrupt->Halt();
#ifdef NETWORK
			postOffice->finish();
#endif
		}

		//Lock->Release();
		PLock->Release();	
		currentThread->Finish();


	}
	else{
		printf("\n--------------------------------------\n");
		printf("Stop one thread, get RESULT :%d! ",status);
		printf("\n--------------------------------------\n");
		if(currentThread!=p->MainThread)
			temp->DecreaseStackSpace(currentThread->startVPN);
		PLock->Release();   
		currentThread->Finish();
	}
	//  PLock->Release();

}





void exec_thread(int tid){

	printf("UP THread ID:%d\n", tid);

	//Thread *NTthread= new Thread("NW");
	/* NTthread -> setParentProcess(currentThread->getParentProcess());
	(p->ChildThreadCounter)++;*/

	// NTthread -> Fork((VoidFunctionPtr) network_thread, (int) tid+1);



	currentThread->mailBox=tid;	
	currentThread -> space ->InitRegisters(); // set the initial register valuesf
	currentThread -> space ->RestoreState(); // load page table register
	currentThread->startVPN = currentThread->space->getFirstThreadStartVPN();


	// printf("this is the starting vpn for current thread's stack %d\n",currentThread->startVPN);
	machine->Run();

}

void network_thread(int tid){

	currentThread->mailBox=tid;
	TimeStamp* ts;       
	ntLockEntry* sle; 
	MessageEntry *me;
	ntConditionEntry* sce;
	ntMonitorEntry* sme;
	ReplyEntry* re;

	//for time stamp
	//time_t myTimeStamp;

	/*
	me = new MessageEntry;
	me -> ntID=currentThread->mailBox;
	me -> time = -1;                          //initialize to -1
	*/


	PacketHeader outPktHdr, inPktHdr;
	MailHeader outMailHdr, inMailHdr;
	char *ack ="";
	char buffer[MaxMailSize];

	char *charID;
	int ID;
	char *requestType;
	char *arg1;
	char *arg2; /* may be used when Wait or Signal */
	char *charTimeStamp; /* this is to grab the time stamp */
	int timeStamp;
	int smallestTS;    /*the smallest timestamp in timestamp table8*/
	/* some basic data defination */

	Table *ntLockTable = new Table(50);
	Table *ntConditionTable = new Table(50);
	Table *ntMonitorTable = new Table(50);
	List* TimeStampList = new List;  /*the time stamp table which contains paris of ID and timestamp*/
	List* QueuedMessages= new List;
	List* ProcessableMSG= new List;
	List* idList= new List;



	//	string message[50];

	string lockName[50];
	string conditionName[50];
	string monitorName[50];

	int lockNameNumber= 0; 	/*I think it's stupid to implement by a counter, but I cannot figure out any better way*/
	int conditionNameNumber = 0;
	int monitorNameNumber = 0;

	int lockIndex;
	int conditionIndex;
	int monitorIndex;

	int monitorValue;

	bool isExisted;

	int *waitQueuePointer; /* just used when waitQueue->Append & waitQueue->Remove for both Lock & CV */


	/* Wait for the first message from the other machine */


	//printf("HERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);
	//printf("HERR+++++++++++++++++++++++RR\n");
	if(inPktHdr.from == netname && inMailHdr.from == currentThread->mailBox-1 && buffer[0]=='m') {

		//printf("HERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
		if(tt!=0){

			requestType="n";
			sprintf(data,"%s,%d",requestType,tt);  // need the num of totalThread

			sendToReg(data,tid);

		}

		requestType="m";
		sprintf(data,"%s,%d,%d",requestType,outPktHdr.from,currentThread->mailBox);  // need the num of currentThread

		//printf("Got here!\n");
		sendToReg(data,tid);

	}



	//wait for reponse
	postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);
	//printf("thread %d receive a message :----->   %s\n",netname*100+currentThread->mailBox,buffer);
	char *b= strtok(buffer,",");
	byte _b=*b;
	int tMachine= (int)_b;

	printf("TOTAL instance I KNOW: %d\n",tMachine);

	char *info = strtok(NULL,",");

	byte *_info=(byte* )info;

	int counter=0;
	for(int i=0;i<tMachine;i++){
		byte _infomid = _info[counter];
		int mid = (int)_infomid;

		byte _infol=_info[counter+1];
		byte _infor=_info[counter+2];

		int sum = (int)(_infol<<8|_infor);	


		//save this...........................	
		//int rmid=(int)_info;
		printf("Machine ID: %d, total Threads: %d\n",mid,sum);

		for(int k=0;k<sum;k++){
			int id = 2*(k+1)-1;
			int tempid = mid*100+id;
			printf("add to list %d\n", tempid);
			idList->Append((void*)tempid);
		}


		counter+=3;
	}

	//printf("List size %d\n", idList->Size());	

	//start the UP
	//printf("NETWORK THREAD mailbox:%d\n",currentThread->mailBox);
	char *data="Start";
	outPktHdr.to = netname;		//mahcine ID
	outMailHdr.to = currentThread->mailBox-1;  //mailbox NO
	outMailHdr.from = currentThread->mailBox;
	outMailHdr.length = strlen(data) + 1;
	//postOffice->Send(outPktHdr,outMailHdr,data);

	ListElement *tir = idList->first;
	int myC=0;
	while(tir!=NULL){
		TimeStamp *tempts=new TimeStamp;
		tempts->ntID=(int)tir->item;
		tempts->time=-1;
		TimeStampList->Append(tempts);
		myC++;
		//  printf("net thread ID : %d is add to the timestamp table now the size is %d\n ", (int)tir->item,myC);
		//  delete tempts;
		tir=tir->next;
	}

	ListElement *check = TimeStampList->first;
	while(check!=NULL){
		//printf("IN the stamps ->%d\n",((TimeStamp *)check->item)->ntID);
		check=check->next;
	}





	postOffice->Send(outPktHdr,outMailHdr,data);



	while(true){
	  		char buffer[40];
		//printf("network %d Wait for a request to come...........................................\n",netname*100+currentThread->mailBox);
		postOffice->Receive(currentThread->mailBox, &inPktHdr, &inMailHdr, buffer);
		char currentMSG[40];
		sprintf(currentMSG,"%s",buffer);
		//printf("STRLEN: %d",strlen(buffer));
		//memcpy(currentMSG,buffer,20);

		//printf("GETMSG:the receive message is  %s,   MY ID : %d\n", buffer,currentThread->mailBox);
		//	printf("buffer : %s \n", buffer);
		charTimeStamp = strtok (buffer,",");
		timeStamp=atoi(charTimeStamp);
		charID =strtok(NULL,",");
		ID = atoi(charID);

		//printf("@ receive ID: %d\n", ID);

		requestType = strtok(NULL,",");

		if(requestType!=NULL)
			arg1 = strtok(NULL,",");	   
		if(arg1!=NULL)
			arg2 = strtok(NULL,",");

		//iterate through the timestamp table, find the match network thread and update the timestamp
		ListElement *temp1= TimeStampList->first;
		while(temp1!=NULL){
			if(((TimeStamp *)temp1->item)->ntID==ID){

				((TimeStamp *)temp1->item)->time=timeStamp;
				//printf("thread %d Update TimeStamp for % with the value %d-\n",netname*100+currentThread->mailBox,((TimeStamp *)temp1->item)->ntID,timeStamp);
				break;
			}

			temp1=temp1->next;
		}
		//delete temp1;
		//if send from my userprog, then this step does not do anything








		if(requestType!=NULL){
			//add the message to the message queue when its not a "simple reply" message
			MessageEntry *temp2 =new MessageEntry;

			temp2->ntID=ID;

			temp2->time=timeStamp;
			temp2->message=currentMSG;   // need to convert char* to string?
			temp2->RT=requestType;
			if(arg1!=NULL)
				temp2->argument1=arg1;
			if(arg2!=NULL)
				temp2->argument2=arg2;
			//printf("move a new message into msg queue,time %d, id  %d  , requesttype %s  \n",timeStamp,ID,requestType);
			QueuedMessages->SortedInsert((void *)temp2,timeStamp);
			//delete temp2;
		}



		//extract the smallest value from the timestamp table;
		ListElement *temp3 =TimeStampList->first;
		smallestTS=((TimeStamp *)temp3->item)->time;
		while(temp3!=NULL){
			if(smallestTS > ((TimeStamp *)temp3->item) ->time)
				smallestTS=((TimeStamp *)temp3->item) ->time;

			temp3=temp3->next;
		}
		//printf("the smallest time stamp in table of net thread %d is %d\n",netname*100+currentThread->mailBox,smallestTS);
		//delete temp3;

		//find all the queued  messages that has the equal or less timestamp value compare to the smallest timestamp
		ListElement *temp4=QueuedMessages->first;
		while(temp4!=NULL){
		  // printf("find a message with timestapme %d in thread %d\n", ((MessageEntry *)temp4->item) ->time,netname*100+currentThread->mailBox);
		  if(((MessageEntry *)temp4->item) ->time<=smallestTS){
		    ProcessableMSG->SortedInsert(temp4->item,((MessageEntry *)temp4->item)->time*10+((MessageEntry *)temp4->item) ->ntID  );
		    temp4=temp4->next;
		     QueuedMessages->Remove();
		     //printf("insert an item %s to processable message for network thread %d \n",((MessageEntry *)temp4->item)->message.c_str(),netname*100+currentThread->mailBox);
		
		  }
		  else{
		  temp4=temp4->next;
		  }
	
		}
		//delete temp4;
		
		//printf("i'm here++++++++++++++++++++++++\n");

		//printf("Got \"%s\" from %d, box %d\n",buffer,inPktHdr.from,inMailHdr.from);
		//printf("request type  = %s\n",requestType);
		//printf("arg1 = %s\n",arg1);

		fflush(stdout);
		/*
		printf("hello\n");
		ListElement *check= ProcessableMSG->first;
		while(check!= NULL){
			printf("CHECK PROCESSABLE: time: %d, message: %s\n",((MessageEntry *)temp4->item)->time,((MessageEntry *)temp4->item)->message);
			check= check->next;

		}
		*/ 





		if(requestType!=NULL){

			ListElement *stemp=TimeStampList->first;
			while(stemp!=NULL){
				outPktHdr.to = (((TimeStamp *)stemp->item)->ntID)/100;		
				outMailHdr.to =  (((TimeStamp *)stemp->item)->ntID)%100;
				if(ID!=(netname*100+currentThread->mailBox)){          //meaning that this message send from other network thread
				  //printf("sending timestamp of %d to all other network!! \n",netname*100+currentThread->mailBox);
					myTimeStamp=getTimeStamp();
					sprintf(buffer,"%d,%d",myTimeStamp,netname*100+currentThread->mailBox);
					outMailHdr.length = strlen(buffer) + 1;
					//printf("this is to reply this message to all other nt threads with my time stamp and ID, %s\n",buffer);
					//if(((TimeStamp *)stemp->item)->ntID != netname*100 + currentThread->mailBox)
						bool success = postOffice->Send(outPktHdr, outMailHdr, buffer); 

				}
				else{  //msg send from my UP

				  //					printf("the msg is generated by %d, current thread id is %d\n",((TimeStamp *)stemp->item)->ntID,netname*100+currentThread->mailBox);


					outMailHdr.length = strlen(currentMSG) + 1;

					//printf("forward %s to %d!\n",currentMSG,((TimeStamp *)stemp->item)->ntID);
					if(((TimeStamp *)stemp->item)->ntID != netname*100 + currentThread->mailBox)	
						bool success = postOffice->Send(outPktHdr, outMailHdr, currentMSG); 
				}


				buffer[0]='\0';




				stemp=stemp->next;

			}
			//delete stemp;
		}


		/*
		ListElement *check = ProcessableMSG->first;
		while(check!=NULL){
			printf(" +++++++++++ %d ++++++++++++++++++ NTID: %d,   Stamps %d,  \n",currentThread->mailBox,((MessageEntry *)check->item)->ntID,((MessageEntry *)check->item)->time);
			check=check->next;
			}
		*/






			ListElement *temp5 = ProcessableMSG->first;
			if(temp5==NULL)
			  {
			    //printf("network %d has no processable messages!!\n",netname*100+currentThread->mailBox);
			  }
			while(temp5!=NULL){  //process the messages in the processable msg queue
			  //  printf("net thread %d process some msge!!!!\n",netname*100+currentThread->mailBox);
				requestType=((MessageEntry *)temp5->item)->RT;
				
				if(((MessageEntry *)temp5->item)->argument1!=NULL)
					arg1=((MessageEntry *)temp5->item)->argument1;
				if(((MessageEntry *)temp5->item)->argument2!=NULL)
					arg2=((MessageEntry *)temp5->item)->argument2;	    

				outPktHdr.to = netname;		//mahcine ID,the same
				outMailHdr.to = currentThread->mailBox-1;
				switch(*requestType){

				case CREATE_LOCK:

					printf("nt %d PROCESS A CREATE_LOCK request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					isExisted = false;

					for(int i = 0; i < lockNameNumber; i++){
						if(strcmp(arg1,(char*)lockName[i].c_str())==0){
							printf("OOPs,this lock has already been created before.Index is %d ,here you go!\n",i);
							isExisted = true;
							lockIndex = i;

							sle = (ntLockEntry*)ntLockTable->Get(lockIndex);
							sle->deleteCounter++;

							break;

						}

					}
					//Is the lockName already existed ?????

					if(!isExisted){

						printf("Lock name:[%s] is not existed in nt database. We CREATE a new one.\n",arg1);
						sle = new ntLockEntry;
						sle->state = FREE;
						sle->owner = ((MessageEntry *)temp5->item)->ntID;  /* Is there any circumstance that one client create a lock but is not the lock owner?  */
						sle->waitQueue = new List; /* must initialize !! */
						sle->deleteCounter = 1; /* start from 1 */

						lockIndex = ntLockTable->Put((void*) sle);
						/* put this name into the array */
						lockName[lockIndex] = arg1;
						//printf("the lock name in ARRAY is %s\n",lockName[lockIndex].c_str());
						lockNameNumber++;
					}

					/*
					The return value from Table-Put is integer,
					Conversion is needed to make it into char.
					*/
					itoa(ack,3,lockIndex);
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox)
					{
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;  //mailbox NO,one less than nt thraed
						outMailHdr.length = strlen(ack) + 1;

						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}
					break;

				

					break;

				case RELEASE:
					/*
					suppose A release the lock
					B is the next owner of the lock

					*/

					//printf("PROCESS A RELEASE request by nt   %d !!\n",netname*100+currentThread->mailBox);
				  printf("nt %d PROCESS A RELEASE request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					lockIndex = atoi(arg1);

					sle = (ntLockEntry*)ntLockTable->Get(lockIndex);

					/* the client is not the current lock owner */
					if(sle->owner != (netname*100+currentThread->mailBox)){
						/*
						printf("sle->owner = %d\n",sle->owner);
						printf("lockIndex = %d\n",lockIndex);
						printf("A stupid client-%d wanna release a lock has nothing to do with him!!!\n",inPktHdr.from);
						ack = "denied";
						if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox)k
						{
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;  //mailbox NO,one less than nt thraed
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
						//break;
						}
						*/
					}


					/* ackowledge the client-A that RELEASE has successfully done */

					ack = "done";

					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox)
					{
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;  //mailbox NO,one less than nt thraed
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}

					if(!sle->waitQueue->IsEmpty()){

						/* next one get the lock */
						re = (ReplyEntry*)sle->waitQueue->Remove();
						//outPktHdr.to = (re->machineId)/100;

						/* you're the lock owner now!! */
						sle->owner = re->machineId;

						printf("release lock. Make the next client-%d acquire the lock.\n",sle->owner);

						ack = "done";
						if(re->machineId==netname*100+currentThread->mailBox)
						{
							outPktHdr.to = netname;		//mahcine ID,the same
							outMailHdr.to = currentThread->mailBox-1;
							outMailHdr.length = strlen(ack) + 1;
							postOffice->Send(outPktHdr, outMailHdr, ack); 
						}


					}else{

						sle->state = FREE;
						sle->owner = NULL;

						printf("A client-%d release lock. No one else requests for that lock, it becomes FREE.\n",((MessageEntry *)temp5->item)->ntID);

					}



					break;


				case DESTROY_LOCK:

				       
				  printf("nt %d PROCESS A DESTORY LOCK request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					
					lockIndex = atoi(arg1);

					sle = (ntLockEntry*)ntLockTable->Get(lockIndex);
					sle->deleteCounter--;


					/* You can bite it now!! */
					if(sle->deleteCounter == 0){
						lockName[lockIndex] = "/0"; /* zero out the corresponding name entry */

						ntLockTable->Remove(lockIndex);

						printf("Lock-%d has been deleted from the nt!\n",conditionIndex);
						ack = "deleted";
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack);

						break;

					}
					printf("Lock-%d cannot be deleted right now. The deleteCounter = %d !\n",lockIndex,sle->deleteCounter);

					ack = "notyet";
					outMailHdr.length = strlen(ack) + 1;
					postOffice->Send(outPktHdr, outMailHdr, ack);

					break;

				case CREATE_CV:

				       
					printf("nt %d PROCESS A CREAT CV request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					
					isExisted = false;

					for(int i = 0; i < conditionNameNumber; i++){
						if(strcmp(arg1,(char*)conditionName[i].c_str())==0){

							printf("OOPs,this condition has already been created before.Index is %d,here you go!\n",i);
							isExisted = true;
							conditionIndex = i;

							sce = (ntConditionEntry*)ntConditionTable->Get(conditionIndex);
							sce->deleteCounter++;
							break;

						}

					}

					if(!isExisted){

						printf("Condition name:[%s] is not existed in nt database. We CREATE a new one.\n",arg1);

						sce = new ntConditionEntry;
						sce->lock = NULL;
						sce->waitQueue = new List;
						sce->deleteCounter = 1;
						conditionIndex = ntConditionTable->Put((void*) sce);

						conditionName[conditionIndex] = arg1;
						//printf("the condition name in ARRAY is %s\n",conditionName[conditionIndex].c_str());
						conditionNameNumber++;

					}

					itoa(ack,3,conditionIndex);
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox){
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;

						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}

					break;

				case SIGNAL:
					/* 
					I assume that the client who make the signal is A
					the client who is waken up is B
					*/

					//printf("A SIGNAL request is got by nt!!\n");
					printf("nt %d PROCESS A SIGNAL request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					
					//CAUTION: RUOYANG WANG REMOVED THIS LINE
					//arg2 = strtok(NULL,","); /* define the 2nd for the SIGNAL is the CV Id */



					//printf("the 1st argument(conid) is %s\n",arg1);
					//printf("the 2nd argument(lockid) is %s\n",arg2);

					conditionIndex = atoi(arg1);
					lockIndex = atoi(arg2);

					sce = (ntConditionEntry*)ntConditionTable->Get(conditionIndex);

					if(sce->waitQueue->IsEmpty()){

						printf("The wait queue is empty.No on can be signaled. Request finished!!\n");
						ack = "done";
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;

						postOffice->Send(outPktHdr, outMailHdr, ack); 
						break;

					}

					/* if the wait queue is empty, the code won't come to here */
					/* send the ack to the client A  */
					ack = "done";
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox){
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;	 
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}


					/* Now it's client B time!!  */
					/* change the sending destination to B */
					re = (ReplyEntry*)sce->waitQueue->Remove();
					outPktHdr.to = (re->machineId)%100;

					//printf("the MUST BE IS %d\n",outPktHdr.to);

					/* make the client-B ACQUIRE the lock before being signaled */
					sle = (ntLockEntry*)ntLockTable->Get(lockIndex);

					if(sle->state == FREE){
						/* same as ACQUIRE */
						sle->owner = re->machineId; 
						sle->state = BUSY;

						ack = "wakeup";
						if(re->machineId==netname*100+currentThread->mailBox){
							outPktHdr.to = netname;		//mahcine ID,the same
							outMailHdr.to = currentThread->mailBox-1;
							outMailHdr.length = strlen(ack) + 1;
							postOffice->Send(outPktHdr, outMailHdr, ack);
						}

					}
					else{

						/* we put the cilent B machine ID into the wait queue */
						/* let Release wake up the B*/

						re = new ReplyEntry;
						re->machineId = netname*100+currentThread->mailBox;;
						sle->waitQueue->Append((void *)re);

						printf("The lock is currently BUSY.Cannot ACQUIRE now. Put client-%d into the wait queue\n",outPktHdr.to);

					}

					break;

				case WAIT:
				  //printf("process A WAIT request by nt %d !!\n",netname*100+currentThread->mailBox);
					printf("nt %d PROCESS A RELEASE request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
					
					//arg2 = strtok(NULL,",");
					//printf("the 1st argument(conid) is %s\n",arg1);
					//printf("the 2nd argument(lockid) is %s\n",arg2);

					conditionIndex = atoi(arg1);
					lockIndex = atoi(arg2);

					/* get the condition entry by the condition id */
					sce = (ntConditionEntry*)ntConditionTable->Get(conditionIndex);

					if(sce->lock == NULL && lockIndex != NULL){

						sce->lock = lockIndex;

					}

					if(sce->lock != lockIndex){
						ack = "wronglock";
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;

						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}

					/* put the client who send the request into the wait queue */
					printf("the client-%d wants to Wait!!!\n",inPktHdr.from);



					re = new ReplyEntry;
					re->machineId = netname*100+currentThread->mailBox;
					//waitQueuePointer = &inPktHdr.from;
					sce->waitQueue->Append((void*)re);

					/* In the Wait, Release the lock in nt side */
					sle = (ntLockEntry*)ntLockTable->Get(lockIndex);

					if(!sle->waitQueue->IsEmpty()){

						re = (ReplyEntry*)sle->waitQueue->Remove();
						outPktHdr.to = (re->machineId)%100;

						sle->owner = outPktHdr.to;

						printf("A client-%d release lock. Make the next client-%d acquire the lock.\n",inPktHdr.from,outPktHdr.to);

						ack = "done";
						if(re->machineId==netname*100+currentThread->mailBox){
							outPktHdr.to = netname;		//mahcine ID,the same
							outMailHdr.to = currentThread->mailBox-1;
							outMailHdr.length = strlen(ack) + 1;
							postOffice->Send(outPktHdr, outMailHdr, ack); 
						}

					}else{
						sle->state = FREE;
						sle->owner = NULL;

						printf("A client-%d release lock. No one else requests for that lock, it becomes FREE.\n",inPktHdr.from);

					}

					break;

				case BROADCAST:


					printf("A BROADCAST request is got by nt!!\n");
					//arg2 = strtok(NULL,","); /* define the 2nd for the SIGNAL is the CV Id */
					//printf("the 1st argument(conid) is %s\n",arg1);
					//printf("the 2nd argument(lockid) is %s\n",arg2);

					conditionIndex = atoi(arg1);
					lockIndex = atoi(arg2);

					sce = (ntConditionEntry*)ntConditionTable->Get(conditionIndex);

					if(sce->waitQueue->IsEmpty()){

						printf("The wait queue is empty.BROADCAST your sister.Request finished!!\n");
						ack = "done";
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
						break;

					}

					/* send the ack to the client A  */
					ack = "done";
					outMailHdr.length = strlen(ack) + 1;
					postOffice->Send(outPktHdr, outMailHdr, ack); 


					/* What makes Broadcast a Broadcast */
					/* Just same as the Signal, but multiple */
					while(!sce->waitQueue->IsEmpty()){

						re = (ReplyEntry*)sce->waitQueue->Remove();
						outPktHdr.to = re->machineId;

						sle = (ntLockEntry*)ntLockTable->Get(lockIndex);

						if(sle->state == FREE){
							/* same as ACQUIRE */
							sle->owner = outPktHdr.to; 
							sle->state = BUSY;
							ack = "wakeup";
							outMailHdr.length = strlen(ack) + 1;
							postOffice->Send(outPktHdr, outMailHdr, ack);

						}
						else{

							re = new ReplyEntry;
							re->machineId = outPktHdr.to;
							sle->waitQueue->Append((void *)re);
							printf("The lock is currently BUSY, put client-%d into the wait queue\n",outPktHdr.to);

						}
					}

					break;

				case DESTROY_CV:

					printf("A DESTROY_CV request is got by nt!!\n");

					conditionIndex = atoi(arg1);

					sce = (ntConditionEntry*)ntConditionTable->Get(conditionIndex);
					sce->deleteCounter--;


					/* You can bite it now!! */
					if(sce->deleteCounter == 0){
						conditionName[conditionIndex] = "/0"; /* zero out the corresponding name entry */
						ntConditionTable->Remove(conditionIndex);

						printf("CV-%d has been deleted from the nt!\n",conditionIndex);

						ack = "deleted";
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack);

						break;

					}

					printf("Condition-%d cannot be deleted right now. The deleteCounter = %d !\n",conditionIndex,sce->deleteCounter);
					ack = "notyet";
					outMailHdr.length = strlen(ack) + 1;
					postOffice->Send(outPktHdr, outMailHdr, ack);

					break;



				case CREATE_MONITOR:
				  //printf("A CREATE_MONITOR request is got by nt!!\n");
	printf("nt %d PROCESS A CREATE_MONITOR request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
				
					isExisted = false;

					for(int i = 0; i < monitorNameNumber; i++){
						if(strcmp(arg1,(char*)monitorName[i].c_str())==0){
							printf("OOPs,this monitor has already been created before. Index is %d,here you go!\n",i);
							isExisted = true;
							monitorIndex = i;
							break;

						}

					}

					if(!isExisted){

						printf("Monitor name:[%s] is not existed in nt database. We CREATE a new one.\n",arg1);

						sme = new ntMonitorEntry;
						sme->value = 0;  /* when create a monitor, set it to 0 */

						monitorIndex = ntMonitorTable->Put((void*) sme);

						monitorName[monitorIndex] = arg1;
						//printf("the monitor name in ARRAY is %s\n",monitorName[monitorIndex].c_str());
						monitorNameNumber++;

					}
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox){

						itoa(ack,3,monitorIndex);
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}
					break;

				case RETRIEVE_MONITOR:
	printf("nt %d PROCESS A RETRIEVE_MONITOR request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
				
	//	printf("A RETRIEVE_MONITOR request is got by nt!!\n");
					monitorIndex = atoi(arg1);
					sme = (ntMonitorEntry*)ntMonitorTable->Get(monitorIndex);

					monitorValue = sme->value;
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox){
						itoa(ack,3,monitorValue);
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}
					break;

				case SET_MONITOR:

				  //	printf("A SET_MONITOR request is got by nt!!\n");
				    printf("nt %d PROCESS A SET_MONITOR request from %d !!\n",netname*100+currentThread->mailBox,((MessageEntry *)temp5->item)->ntID);
				
					//arg2 = strtok(NULL,",");
					printf("the 1st argument(mid) is %s\n",arg1);
					if(arg2==NULL){
					  printf("im in set monitor function but missing the second argument!!!\n");
					}
					printf("the 2nd argument(mvalue) is %s\n",arg2);

					monitorIndex = atoi(arg1);
					monitorValue = atoi(arg2);
					printf("net thread %d set moniter %d to value %d\n ",netname*100+currentThread->mailBox,monitorIndex,monitorValue);		
					sme = (ntMonitorEntry*)ntMonitorTable->Get(monitorIndex);

					sme->value = monitorValue;

					ack = "done";
					if(((MessageEntry *)temp5->item)->ntID==netname*100+currentThread->mailBox){
						outPktHdr.to = netname;		//mahcine ID,the same
						outMailHdr.to = currentThread->mailBox-1;
						outMailHdr.length = strlen(ack) + 1;
						postOffice->Send(outPktHdr, outMailHdr, ack); 
					}
					break;

				case START_SIMULATION:

					//get my threadID(need lock)

					/*
					//send msg to register
					printf("HERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
					requestType="m";
					sprintf(data,"%s,%d,%d",requestType,outPktHdr.from,currentThread->tid);  // need the num of currentThread

					sendPacket(data);

					//wait for reponse
					postOffice->Receive(0, &inPktHdr, &inMailHdr, buffer);
					printf("buffer :----->   %s\n",buffer);
					char *b= strtok(buffer,",");
					byte _b=*b;
					int tMachine= (int)_b;

					printf("TOTAL instance I KNOW: %d\n",tMachine);

					char *info = strtok(NULL,",");

					byte *_info=(byte* )info;

					int counter=0;
					for(int i=0;i<tMachine;i++){
					byte _infomid = _info[counter];
					int mid = (int)_infomid;

					byte _infol=_info[counter+1];
					byte _infor=_info[counter+2];

					int sum = (int)(_infol<<8|_infor);	


					//save this...........................	
					//int rmid=(int)_info;
					printf("Machine ID: %d, total Threads: %d\n",mid,sum);

					counter+=3;
					}
					*/

					// printf("Userprogm has asked to start simulation!\n");


					//send the registration msg to reg server and wait for reply..... ask YI PEI for the code
					break;

				}
				temp5=temp5->next;
				ProcessableMSG->Remove();
			}//match while(temp5->next!=NULL)
			/* I thought it's necessary to clean the buffer every time nt finishes a job */
			//	buffer[0] = '\0';
			//	    delete temp5;
	}

	machine->Run();
}

int Exec_Syscall(unsigned int vaddr){
	//TO-DO : need lock to protect creating run executable 
	int max=60;        // TO-DO : shoud change to a define when intergrate
	//printf("start executing....\n");
	int rv;
	int maxlen = 20; //TEST!!!!!!!!!!!!!!!!

	char *buf = new char[maxlen];	// Kernel buffer to put the name in  

	if (!buf) return -1;

	int len = copyin(vaddr,maxlen,buf);
	if( len == -1 ) {
		printf("%s","Bad pointer passed to Create\n");
		delete buf;
		return -1;
	}	

	buf[len] = '\0';



	//TO-DO:check maximum process


	//Now Open that file using filesystem->Open.
	PLock->Acquire();
	OpenFile *executable = fileSystem->Open(buf);

	//check if the executable loaded 
	if (executable == NULL) {
		printf("Unable to open file,returning... %s\n", buf);
		PLock->Release();
		return -1;
	}


	//printf("executable checked, openfile success\n");

	//create a new address space for the executable file
	AddrSpace *as = new AddrSpace(executable);

	//TO-DO : the constructor of the process

	//crate a process, PID is the entry in the ProcessTable
	Process* p = new Process(as, buf);   // buf is its name and as is its add space
	int pid = ProcessTable->Put((void*) p);
	rv=pid;
	p -> setPID(pid);
	//  p->getAddrSpace()->setPIDToIPT(pid);

	//printf("Process is created!\n");

	//lock
	processCounter++;


	//add a new thread
	Thread *thread = new Thread(buf);

	//make a table entry.
	int threadid = p->ChildThread->Put((void*) thread);
	//add thread's parent process as this process.
	thread -> setParentProcess(p);
	(p->ChildThreadCounter)++;  
	//printf("thread is created!%d\n",p->ChildThreadCounter);
	// If this is the first thread, initialize currentThread

	if (currentThread == NULL) {
		printf("no thread running currently, making this thread the current thread!\n");
		currentThread = thread;

	}

	// if every thing is fine then add this thread to the new process.Restore interuppts and return
	//assgin the created AddrSpace to thread

	thread -> space = as;   
	p->MainThread=thread;
	//  printf("thread space set!");  


	//need lock
	int nwThreadID = threadCounter+1;
	int upThreadID=threadCounter;
	threadCounter += 2;


	Thread *NTthread= new Thread("NW");



	NTthread -> Fork((VoidFunctionPtr) network_thread, (int) nwThreadID);




	thread -> Fork((VoidFunctionPtr) exec_thread, (int)upThreadID);

	PLock->Release();
	return rv;  
}


int findIPTIndex(int vpn){
	IPTLock->Acquire();
	int pid= currentThread->getParentProcess()->getPID();
	for(int k=0; k < NumPhysPages;k++){
		if(ipt[k].valid==true && ipt[k].pid==pid && ipt[k].virtualPage==vpn){		
			IPTLock->Release();
			return k;		
		}		     
	}
	IPTLock->Release();
	return -1;

}

void updateTLB(unsigned int vaddr){
	/*
	AddrSpace* as= currentThread->space; 
	int vPageNumber = vaddr/PageSize; 


	// check if this exceeds the bound of vaddr

	as->addTLB(vPageNumber);*/


	AddrSpace* as= currentThread->space; 
	int pid = currentThread->getParentProcess()->getPID();



	int vPageNumber = vaddr/PageSize;
	//printf("%d\n",vaddr);

	int ppn = findIPTIndex(vPageNumber);
	if( ppn == -1){
		// miss from ipt
		//for now lots of memory!!!!!!!!!!!!!!
		//  printf("WWWWWW:%d  VPN:%d\n",currentThread->tid, vPageNumber);
		int pid = currentThread->getParentProcess()->getPID();
		as->updateIPT(vaddr,pid);


	}

	else{
		// printf("Vaddr:%d  PPN:  %d ppn, VPN: %d \n", vaddr, ppn, vPageNumber);
		as->addTLB(ppn);
		//update TLB

	}
	// check if this exceeds the bound of vaddr


}








void ExceptionHandler(ExceptionType which) {
	int type = machine->ReadRegister(2); // Which syscall?
	int rv=0; 	// the return value from a syscall
	//printf("A system call happened here, type = %d\n",type);
	if ( which == SyscallException ) {
		switch (type) {
		default:
			DEBUG('a', "Unknown syscall - shutting down.\n");
		case SC_Halt:
			DEBUG('a', "Shutdown, initiated by user program.\n");
			interrupt->Halt();
			break;
		case SC_Create:
			DEBUG('a', "Create syscall.\n");
			Create_Syscall(machine->ReadRegister(4), machine->ReadRegister(5));
			break;
		case SC_Open:
			DEBUG('a', "Open syscall.\n");
			rv = Open_Syscall(machine->ReadRegister(4), machine->ReadRegister(5));
			break;
		case SC_Write:
			DEBUG('a', "Write syscall.\n");
			Write_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5),
				machine->ReadRegister(6));
			break;
		case SC_Read:
			DEBUG('a', "Read syscall.\n");
			rv = Read_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5),
				machine->ReadRegister(6));
			break;
		case SC_Close:
			DEBUG('a', "Close syscall.\n");
			Close_Syscall(machine->ReadRegister(4));
			break;



			//add new
		case SC_Exec:
			DEBUG('a',"Exec. \n");
			rv=Exec_Syscall(machine->ReadRegister(4));
			break;
		case SC_Exit:
			//  printf("machine->ReadRegister(4) = %d \n",machine->ReadRegister(4));
			DEBUG('a'," Exittd.\n");
			Exit_Syscall(machine->ReadRegister(4));
			break;
		case SC_Fork:
			//	        DEBUG('a'," Fork a new thread.\n");
			Fork_Syscall(machine->ReadRegister(4)
				);
			break;
		case SC_Yield:
			DEBUG('a'," Yield .\n");
			Yield_Syscall();
			break;

#ifdef NETWORK 
		case SC_CreateCondition:
			DEBUG('a'," Create Condition syscall.\n");
			rv=CreateCondition_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5));
			break;

		case SC_WaitCondition:
			DEBUG('a'," Wait Condition syscall.\n");
			WaitCondition_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5));
			break;

		case SC_SignalCondition:
			DEBUG('a'," Signal Condition syscall.\n");
			SignalCondition_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5));
			break;

		case SC_BroadcastCondition:
			DEBUG('a'," Broadcast Condition syscall.\n");
			BroadcastCondition_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5));
			break;


		case SC_DestroyCondition:
			DEBUG('a'," Destroy Condition syscall.\n");
			DestroyCondition_Syscall(machine->ReadRegister(4)
				);
			break;

		case SC_CreateLock:
			DEBUG('a'," Create Lock syscall.\n");
			rv=CreateLock_Syscall(machine->ReadRegister(4),
				machine->ReadRegister(5));
			break;
		case SC_AcquireLock:
			DEBUG('a'," Acquire Lock syscall.\n");
			AcquireLock_Syscall(machine->ReadRegister(4)
				);
			break;
		case SC_ReleaseLock:
			DEBUG('a'," Release Lock syscall.\n");
			ReleaseLock_Syscall(machine->ReadRegister(4)
				);
			break;
		case SC_DestroyLock:
			DEBUG('a'," Destroy Lock syscall.\n");
			DestroyLock_Syscall(machine->ReadRegister(4)
				);
			break;

		case SC_CreateMonitor:
			DEBUG('a'," Create Monitor syscall. \n");
			rv = CreateMonitor_Syscall(machine->ReadRegister(4),machine->ReadRegister(5));
			break;

		case SC_RetrieveMonitor:
			DEBUG('a'," Retrieve Monitor syscall. \n");
			rv = RetrieveMonitor_Syscall(machine->ReadRegister(4));
			break;

		case SC_SetMonitor:
			DEBUG('a'," Set Monitor syscall. \n");
			SetMonitor_Syscall(machine->ReadRegister(4),machine->ReadRegister(5));
			break;

		case SC_StartSimulation:
			DEBUG('a'," start simulation syscall. \n");
			StartSimulation_Syscall();
			break;
#endif
		}

		// Put in the return value and increment the PC
		machine->WriteRegister(2,rv);
		machine->WriteRegister(PrevPCReg,machine->ReadRegister(PCReg));
		machine->WriteRegister(PCReg,machine->ReadRegister(NextPCReg));
		machine->WriteRegister(NextPCReg,machine->ReadRegister(PCReg)+4);
		return;
	} 
	else if(which == PageFaultException){
		//	printf("ERROR!!!!!!!!!!!!%d!!!!!!!!\n",machine->ReadRegister(BadVAddrReg));
		updateTLB(machine->ReadRegister(BadVAddrReg));

	}
	else {
		cout<<"Unexpected user mode exception - which:"<<which<<"  type:"<< type<<endl;
		interrupt->Halt();
	}
}
