#include <time.h>

timeval start,end;

int diff_ms(timeval t1, timeval t2)
{
  return (t1.tv_sec - t2.tv_sec) * 1000+ 
           (t1.tv_usec - t2.tv_usec)/1000;
}


void timeStart(){

  gettimeofday(&start,NULL);

}

int timeElapsed(){

  gettimeofday(&end,NULL);

  return diff_ms(end,start);
}



