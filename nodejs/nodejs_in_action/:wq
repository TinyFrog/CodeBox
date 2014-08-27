var socketio = require('socket.io'),
    io,
    guestNumber = 1,
    nickNames = {},
    namesUsed = [],
    currentRoom = {};

exports.listen = function(server) {

    io = socketio.listen(server);
    io.set('log level', 1);

    io.sockets.on('connection', function (socket) {
        guestNumber = assignGuestName(socket, guestNumber, nickNames, namesUsed);
        joinRoom(socket, 'Lobby');
        handleMessageBroadcasting(socket, nickNames);
        handleNameChangeAttempts(socket, nickNames, namesUsed);
        handleRoomJoining(socket);
        socket.on('rooms', function () {
            socket.emit('rooms', io.sockets.manager.rooms);
        });

        handleClientDisconnection(socket, nickNames, namesUsed);
    });
};

function assignGuestName(socket, guestNumber, nickNames, namesUsed) {
    var name = 'Guest' + guestNumber;
    nickNames[socket.id] = name;
    socket.emit('nameresult', {
        success: true,
        name: name
    });
    namesUsed.push(name);
    return guestNumber + 1;
}

//
// joinRoom(socket, room)
//
//

function joinRoom(socket, room) {

    // http://socket.io/docs/server-api/#socket#join(name:string[,-fn:function]):socket
    socket.join(room);


    // broadcast to users in the room that this person has joined

    // update userNames, guestNumber

}


//
// handleNameChangeAttempts(socket, nickNames, namesUsed)
//

function handleNameChangeAttempts () {


}

//
// handleRoomJoining(socket)
//
