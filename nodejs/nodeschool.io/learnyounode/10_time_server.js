var net = require('net'),
    port = process.argv[2],
    dateObj = new Date();

var server = net.createServer(function (socket) {
    var year = dateObj.getFullYear(),
        month = dateObj.getMonth(),
        date = dateObj.getDate(),
        hours = dateObj.getHours(),
        minutes = dateObj.getMinutes();

    month = month + 1;
    if (month < 10) {
        month = "0" + month;
    }
    var data = year + "-" + month + "-" + date + " " + hours + ":" + minutes + "\n";
    socket.end(data);
});
server.listen(port);
