/*

Convert data from `process.stdin` to upper-case data on `process.stdout`
using the `through` module.

*/

var through = require('through'),
	tr  = through(write, end);

function write (buf) { this.queue(buf.toString().toUpperCase()); }
function end () { this.queue(null); }

// !!!
process.stdin.pipe(tr).pipe(process.stdout);
