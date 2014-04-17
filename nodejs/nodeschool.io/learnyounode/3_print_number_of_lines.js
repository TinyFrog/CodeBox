/*

All synchronous (or blocking) filesystem methods in the fs module end with 'Sync'. To read a file, you'll need to use fs.readFileSync('/path/to/file'). This method will return a Buffer object containing the complete contents of the file.

*/

// Assume it always has a param
var filePath = process.argv[2];

var fs = require('fs');

var buffer  = fs.readFileSync(filePath);

/*

Buffer.toString():
Decodes and returns a string from buffer data encoded with encoding (defaults to 'utf8') beginning at start (defaults to 0) and ending at end (defaults to buffer.length). 

*/

var counter = 0;
var content = buffer.toString();
for (var i in content) {
    if (content[i] === "\n") {
        counter++;
    }
}


console.log(counter);
