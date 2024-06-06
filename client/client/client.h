#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string_view>

#include "../sockets/sockets.h"

class Client : public Sockets {
public:
	void JoinToServer(std::string_view address, USHORT port);

private:
	void Join();

private:
	SOCKET currentSocket;
};

#endif // !CLIENT_H
