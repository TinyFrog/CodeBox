var http = require('http');
    urls = [];

for (var i = 2; i<5; i++) {
    urls.push(process.argv[i]);
}

function httpGetAsync(urls, index) {

    if (urls.length > index) {
        http.get(urls[index], function(response){
            var output = "";
            response.setEncoding('utf8');
            response.on('data', function(data){
                output += data;
            });
            response.on('end', function(){
                console.log(output);
                httpGetAsync(urls, index+1);
            });
        });
    }
}

httpGetAsync(urls, 0);
