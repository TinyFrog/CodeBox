var split = require('split'),
	through = require('through');


var lineNumber = 1;

process.stdin
    .pipe(split())
    .pipe(through(function (line) {
    	// lineNumber / 2 is not an integer, it's decimal
    	if (lineNumber%2 === 0){
    		// console.dir would add '' around the string
    		console.log(line.toString().toUpperCase());
    	} else {
    		console.log(line.toString().toLowerCase());
    	}
    	lineNumber++;
    })).pipe(process.stdout);