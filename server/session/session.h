#pragma once
#ifndef SESSION_H
#define SESSION_H

#include "../packethandler/packethandler.h"
#include "../sockets/currentconnection/currentconnection.h"

class Session {
public:
    Session(CurrentConnection& connection);
    ~Session();

    void Run();

private:
	CurrentConnection& currentConnection;
    PacketHandler packetHandler;
};

#endif // !SESSION_H
