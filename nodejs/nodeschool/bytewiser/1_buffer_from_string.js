/*

http://nodejs.org/api/buffer.html#buffer_class_buffer

Pure JavaScript is Unicode friendly but not nice to binary data. When dealing with TCP streams or the file system, it's necessary to handle octet streams. Node has several strategies for manipulating, creating, and consuming octet streams.

Raw data is stored in instances of the Buffer class. A Buffer is similar to an array of integers but corresponds to *** a raw memory allocation outside the V8 heap ***. A Buffer cannot be resized.

*/

console.log(Buffer("bytewiser"));


// It will give:
// "<Buffer 62 79 74 65 77 69 73 65 72>"