//process.stdin.setEncoding('utf8');

process.stdin.once('data', function (buffer) {



		var ui8 = new Uint8Array(buffer.length);
  		for (var i = 0; i < buffer.length; i++) ui8[i] = buffer[i];
 		 console.log(JSON.stringify(ui8))	
});