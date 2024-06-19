#pragma once
#ifndef SOCKETS_H
#define SOCKETS_H

#include <memory>
#include <WinSock2.h>
#include <string_view>

class Sockets {
public:
	Sockets();
	~Sockets();

protected:
	std::shared_ptr<SOCKET> Connect(std::string_view address, u_short port) const;

private:
	sockaddr_in GetEndpointData(std::string_view address, u_short port) const;
	SOCKET CreateClientSocket() const;

	void InitializeWSA();
	void CleanupWSA();
};

#endif // !SOCKETS_H
