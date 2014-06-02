var filePath = process.argv[2],
	fs = require('fs');

fs.readFile(filePath, function (err, results) {

	var lastStartPos = 0;
	for (var i =0; i < results.length; i++){
		if (results[i] === 10 || i === results.length -1) {
//			console.log("A new line!!!");
			var goodFellas = results.slice(lastStartPos, i);
			console.log(goodFellas);
			lastStartPos = i+1;
		}
	}

})
