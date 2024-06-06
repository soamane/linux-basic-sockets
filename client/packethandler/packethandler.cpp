#include "packethandler.h"

#include <vector>

PacketHandler::PacketHandler(SOCKET currentSocket) : currentSocket(currentSocket) {

}

bool PacketHandler::SendStringPacket(const std::string& packet) {
    const std::size_t packetSize = packet.size();

    if (!SendAllBytes(reinterpret_cast<const char*>(&packetSize), sizeof(packetSize))) {
        return false;
    }

    if (!SendAllBytes(packet.data(), static_cast<int>(packet.size()))) {
        return false;
    }

    return true;
}

const std::string PacketHandler::ReceiveStringPacket() {
    std::size_t packetSize{};

    if (!ReceiveAllBytes(reinterpret_cast<char*>(&packetSize), sizeof(packetSize))) {
        return std::string();
    }

    std::vector<char> buffer(packetSize);
    if (!ReceiveAllBytes(buffer.data(), static_cast<int>(packetSize))) {
        return std::string();
    }

    return std::string(buffer.data(), packetSize);
}

bool PacketHandler::SendAllBytes(const char* buffer, int length) {
    int totalBytesSent = 0;
    while (totalBytesSent < length) {
        int bytesSent = send(this->currentSocket, buffer + totalBytesSent, length - totalBytesSent, 0);
        if (bytesSent <= 0) {
            return false;
        }
        totalBytesSent += bytesSent;
    }

    return true;
}

bool PacketHandler::ReceiveAllBytes(char* buffer, int length) {
    int totalBytesReceived = 0;
    while (totalBytesReceived < length) {
        int bytesReceived = recv(this->currentSocket, buffer + totalBytesReceived, length - totalBytesReceived, 0);
        if (bytesReceived <= 0) {
            return false;
        }
        totalBytesReceived += bytesReceived;
    }

    return true;
}