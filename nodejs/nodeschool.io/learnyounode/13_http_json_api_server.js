var http = require('http'),
    url = require('url'),
    port = process.argv[2];

/*

forwardgood-lm:learnyounode ssb$ node -pe "require('url').parse('/test?q=1', true)"
{ protocol: null,
  slashes: null,
  auth: null,
  host: null,
  port: null,
  hostname: null,
  hash: null,
  search: '?q=1',
  query: { q: '1' },
  pathname: '/test',
  path: '/test?q=1',
  href: '/test?q=1' }


*/

var server = http.createServer( function(req, res) {
    var data;
    var u = url.parse(req.url);
    // console.log(u);
    if (u.pathname === '/api/parsetime') {
        var isoTime = u.query.split('=')[1];
        // Passing isoTime to Date(). Date() would parse it 
        var date = new Date(isoTime);
        var hours =    date.getHours(),
            minutes = date.getMinutes(),
            seconds = date.getSeconds();

        var data = {
            'hour': hours,
            'minute': minutes,
            'second': seconds
        };

        data = JSON.stringify(data);

    }

    if (u.pathname === '/api/unixtime') {
        // console.log('unixtime');
        var isoTime = u.query.split('=')[1];
        // Passing isoTime to Date(). Date() would parse it 
        var date = new Date(isoTime);
        data = { 'unixtime': date.getTime() };
        data = JSON.stringify(data);
    }


    res.writeHead(200, { 'Content-Type': 'application/json' });
    // res.end() must take string or Buffer
    res.end(data.toString());
});


server.listen(port);




/*

Solution:

    var http = require('http')
    var url = require('url')

    function parsetime (time) {
      return {
        hour: time.getHours(),
        minute: time.getMinutes(),
        second: time.getSeconds()
      }
    }

    function unixtime (time) {
      return { unixtime : time.getTime() }
    }

    var server = http.createServer(function (req, res) {
      var parsedUrl = url.parse(req.url, true)
      var time = new Date(parsedUrl.query.iso)
      var result

      if (/^\/api\/parsetime/.test(req.url))
        result = parsetime(time)
      else if (/^\/api\/unixtime/.test(req.url))
        result = unixtime(time)

      if (result) {
        res.writeHead(200, { 'Content-Type': 'application/json' })
        res.end(JSON.stringify(result))
      } else {
        res.writeHead(404)
        res.end()
      }
    })
    server.listen(Number(process.argv[2]))


*/
