var http = require('http'),
    url = process.argv[2];

http.get(url, function (response) {

    var output = "";
    response.setEncoding('utf8');
    response.on("data", function (data) {
        output += data;
    });
    response.on("end", function (data) {
        console.log(output.length);
        console.log(output);
    });
});
