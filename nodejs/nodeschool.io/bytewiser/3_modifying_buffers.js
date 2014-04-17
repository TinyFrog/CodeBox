
process.stdin.setEncoding('utf8');

process.stdin.on('readable', function(chunk) {
	var chunk = process.stdin.read();
	if (chunk) {
	 	var buf = new Buffer(chunk.toString().length);

		for (var i = 0; i < chunk.toString().length ; i++) {
			var c = chunk.charCodeAt(i);
		  	buf[i] = (c === 46)? 33 : c;
		}

		console.log(buf); 
		//console.log(buffer.toString());
	}
});



