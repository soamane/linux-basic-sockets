#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <vector>

#include "../sockets/sockets.h"
#include "../terminal/terminal.h"

class Server : public Sockets {
public:
	void Start(std::string_view address, unsigned short port);

private:
	std::vector<CurrentConnection> connections;
};

#endif // !SERVER_H
