var http = require('http'),
    fs = require('fs'),
    port = process.argv[2],
    filePath = process.argv[3];

var server = http.createServer(function callback (request, response) {
    var responseData = "";
    var readable = fs.createReadStream(filePath);
    readable.setEncoding('utf8');
    readable.on('data', function(data) {
        responseData = data;
        response.writeHead(200, {"Content-Type": "text/plain"});
        // this line cannot be put outside 
        response.end(responseData);
    });
});

server.listen(port);
