var http = require('http'),
	through = require('through'),
	port = process.argv[2];
/*

Tips:

For example, we can stream a file to the response object:

    var http = require('http');
    var fs = require('fs');
    var server = http.createServer(function (req, res) {
        fs.createReadStream('file.txt').pipe(res);
    });
    server.listen(process.argv[2]);

This is great because our server can response immediately without buffering
everything in memory first.


*/


var server = http.createServer(function(req, res) {


	req.pipe(through(function(data) {
		this.queue(data.toString().toUpperCase());

	})).pipe(res);

});


server.listen(port);



