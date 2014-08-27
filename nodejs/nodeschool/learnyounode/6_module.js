var fs = require('fs');

module.exports = function(dir, fileExt, callback) {

    fs.readdir(dir, function (err, files) {
        if (err) {
            return callback(err);
        }

        var re = new RegExp("." + fileExt + "$");

        // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter
        console.log(files);
        files = files.filter(function(file) {
            return file.match(re);
        });

        callback(null, files);
    });
};
