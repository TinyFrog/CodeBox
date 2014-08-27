var http = require('http'),
    fs = require('fs'),
    path = require('path'),
    mime = require('mime'),
    chatServer = require('./lib/chat_server.js');
    cache = [];

function send404(res) {
    res.writeHead(404, {'Content-Type': 'text/plain'});
    res.write('Error 404: resource not found');
    res.end();
}

function sendFile(res, filePath, fileContent) {
    res.writeHead(200, {'Content-Type': mime.lookup(path.basename(filePath))});
    res.end(fileContent);
}

function serveStatic(res, cache, absPath) {
    if (cache[absPath]) {
        sendFile(res, absPath, cache[absPath]);
    } else {
        fs.exists(absPath, function(exists) {
            if (exists) {
                console.log('File ' + absPath + ' exists. Sending it...');
                fs.readFile(absPath, function(err, data) {
                    if (err) {
                        send404(res);
                    } else {
                        cache[absPath] = data;
                        sendFile(res, absPath, data);
                    }
                });
            } else {
                send404(res);
            }
        });
    }
}

var server = http.createServer(function(req, res) {

    var filePath = false;
    console.log(req.url);
    if (req.url == '/') {
        filePath = 'public/index.html';
    } else {
        filePath = 'public/' + req.url;
    }
    var absPath = './' + filePath;
    serveStatic(res, cache, absPath);

});

chatServer.listen(server);
server.listen(3000, function() {
    console.log('Server starts listening on port 3000');
});
