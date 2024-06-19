#pragma once
#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include <string>
#include <memory>
#include <WinSock2.h>

class PacketHandler {
public:
	PacketHandler(std::shared_ptr<SOCKET> currentSocket);

	bool SendStringPacket(const std::string& packet);
	const std::string ReceiveStringPacket();

private:
	bool SendAllBytes(const char* buffer, int length);
	bool ReceiveAllBytes(char* buffer, int length);

private:
	std::shared_ptr<SOCKET> currentSocket;
};

#endif // !PACKET_HANDLER_H
