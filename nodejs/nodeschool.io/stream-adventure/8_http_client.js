/*

Send an HTTP POST request to http://localhost:8000 and pipe process.stdin into
it. Pipe the response stream to process.stdout

*/


var request = require('request');

/*

The object that you get back from `request.post()` is a readable+writable
stream so you can pipe a readable stream into it (`src.pipe(r)`) and you can
pipe it to a writable stream (`r.pipe(dst)`).

*/

process.stdin.pipe(request.post('http://localhost:8000')).pipe(process.stdout)