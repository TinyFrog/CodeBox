var concat = require('concat-stream'),
	through = require('through');

// http://stackoverflow.com/a/959004/677596
function reverseString(str){
    return str.split("").reverse().join("");
}

//function write(buf) { this.queue(buf);}
//
// through module is used to manipulate the input stream
// https://www.npmjs.org/package/through
//
// concat-stream is used to buffer the input 
//

var ret;

// return of concat is not a readable class so it cannot continue to pipe
process.stdin.pipe(concat(function (data) {
	ret = reverseString(data.toString());
	console.log(ret);

}));
