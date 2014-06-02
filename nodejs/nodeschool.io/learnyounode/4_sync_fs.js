var fs = require("fs");

var fileName = process.argv[2];

fs.readFile(fileName, function(err, data){

    if (err) {
        return;
    }
    var counter = 0;
    // data is a Buffer
    var dataStr =  data.toString();
    for(var i in dataStr) {
        if (dataStr[i] === "\n") {
            counter++;
        }
    }
    console.log(counter);

});
