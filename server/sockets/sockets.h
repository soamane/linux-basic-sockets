#pragma once
#ifndef SOCKETS_H
#define SOCKETS_H

#include <string_view>
#include "currentconnection/currentconnection.h"

class Sockets {
private:
	const SOCKET InitBaseSocket(std::string_view address, unsigned short port) const;
	const sockaddr_in& CreateEndpoint(std::string_view address, unsigned short port) const;
	
protected:
	const CurrentConnection Accept(std::string_view address, unsigned short port) const;
};

#endif // !SOCKETS_H
