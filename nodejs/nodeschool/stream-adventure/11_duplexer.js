var spawn = require('child_process').spawn,
	duplexer = require('duplexer');

module.exports = function(cmd, args) {
	
	var child =	spawn(cmd, args);
	return duplexer(child.stdin, child.stdout);
};