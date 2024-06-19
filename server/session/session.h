#pragma once
#ifndef SESSION_H
#define SESSION_H

#include "../packethandler/packethandler.h"
#include "../sockets/currentconnection/currentconnection.h"

class Session {
public:
    Session(std::shared_ptr<CurrentConnection> connection);
    ~Session();

    void Run();

private:
	std::shared_ptr<CurrentConnection> currentConnection;
    std::unique_ptr<PacketHandler> packetHandler;
};

#endif // !SESSION_H
