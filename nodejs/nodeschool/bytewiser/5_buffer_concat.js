var through = require('through'),
	tr = new through(write,end);

var bufferList = [];

function write(data){

	var buf = Buffer(data);
	bufferList.push(buf);
}

function end () {
	var concatBuffer = Buffer.concat(bufferList);
	console.log(concatBuffer);
}


process.stdin.pipe(tr).pipe(process.stdout);