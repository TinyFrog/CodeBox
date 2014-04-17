var dirPath = process.argv[2],
    fileExt = process.argv[3],
    fs = require('fs');

fs.readdir(dirPath, function (err, list) {

    if (err) { return; }

    if (list) {
        for ( var i in list ) {
            // http://stackoverflow.com/a/494046/677596
            var re = new RegExp("." + fileExt + "$");
            if (list[i].match(re)) {
                console.log(list[i]);
            }
        }
    }


});
