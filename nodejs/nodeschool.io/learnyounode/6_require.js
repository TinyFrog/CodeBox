var module = require('./6_module.js'),
    argv = process.argv,
    fileDir = argv[2],
    fileExt = argv[3];

module(fileDir, fileExt, function(err, results) {

    if (err) {
        console.log(err);
    }

    for (var i in results) {
        console.log(results[i]);
    }

});
