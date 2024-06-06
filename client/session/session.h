#pragma once
#ifndef SESSION_H
#define SESSION_H

#include <WinSock2.h>

#include "../packethandler/packethandler.h"

class Session {
public:
	Session(SOCKET socket);
	~Session();

	void Run();

private:
	const SOCKET socket;
	PacketHandler packetHandler;
};

#endif // !SESSION_H