#pragma once
#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include <string>

#include "../sockets/currentconnection/currentconnection.h"

class PacketHandler {
public:
	PacketHandler(const CurrentConnection& connection);

	bool SendStringPacket(const std::string& packet);
	const std::string ReceiveStringPacket();

private:
	bool SendAllBytes(const char* buffer, std::size_t length);
	bool ReceiveAllBytes(char* buffer, std::size_t length);

private:
	CurrentConnection currentConnection;
};

#endif // !PACKET_HANDLER_H
