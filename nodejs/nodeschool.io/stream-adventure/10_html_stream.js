var trumpet = require('trumpet');
var through = require('through');
var tr = trumpet();



var stream = tr.select('.loud').createStream();

// learned from solution
// pipe from stream and to stream(!!)
stream.pipe(through(function(line){
	this.queue(line.toString().toUpperCase());
})).pipe(stream);


// why tr here?
process.stdin.pipe(tr).pipe(process.stdout);


