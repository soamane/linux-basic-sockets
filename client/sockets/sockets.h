#pragma once
#ifndef SOCKETS_H
#define SOCKETS_H

#include <string_view>
#include <WinSock2.h>

class Sockets {
public:
	Sockets();
	~Sockets();

protected:
	SOCKET Connect(std::string_view address, u_short port) const;

private:
	sockaddr_in GetEndpointData(std::string_view address, u_short port) const;
	SOCKET CreateClientSocket() const;

	void InitializeWSA();
	void CleanupWSA();
};

#endif // !SOCKETS_H
