#pragma once
#ifndef CURRENT_CONNECTION_H
#define CURRENT_CONNECTION_H

#include <arpa/inet.h>

typedef int SOCKET;

struct CurrentConnection {
	SOCKET socket;
	sockaddr_in info;
	unsigned int id;

public:
	void CloseConnection();
};

#endif // !CURRENT_CONNECTION_H
