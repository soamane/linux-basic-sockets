#pragma once
#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include <string>
#include <memory>

#include "../sockets/currentconnection/currentconnection.h"

class PacketHandler {
public:
	PacketHandler(std::shared_ptr<CurrentConnection> connection);

	bool SendStringPacket(const std::string& packet);
	const std::string ReceiveStringPacket();

private:
	bool SendAllBytes(const char* buffer, std::size_t length);
	bool ReceiveAllBytes(char* buffer, std::size_t length);

private:
	std::shared_ptr<CurrentConnection> currentConnection;
};

#endif // !PACKET_HANDLER_H
