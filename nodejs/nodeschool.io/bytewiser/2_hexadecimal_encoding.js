var output = "";

for (var i = 2; i < process.argv.length; i++) {
	// The first argument of this Buffer() can be a string, size or array
	var buffer = new Buffer([process.argv[i]]);
	output += buffer.toString('hex');
}


console.log(output);
