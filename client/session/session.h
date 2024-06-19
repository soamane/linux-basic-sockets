#pragma once
#ifndef SESSION_H
#define SESSION_H

#include <WinSock2.h>

#include "../packethandler/packethandler.h"

class Session {
public:
	Session(std::shared_ptr<SOCKET> socket);
	~Session();

	void Run();

private:
	std::shared_ptr<SOCKET> currentSocket;
	std::unique_ptr<PacketHandler> packetHandler;
};

#endif // !SESSION_H