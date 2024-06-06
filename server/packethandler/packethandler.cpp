#include "packethandler.h"

#include <vector>

PacketHandler::PacketHandler(const CurrentConnection& connection) : currentConnection(connection) { }

bool PacketHandler::SendStringPacket(const std::string& packet) {
    const std::size_t packetSize = packet.size();

    if (!SendAllBytes(reinterpret_cast<const char*>(&packetSize), sizeof(packetSize))) {
        return false;
    }

    if (!SendAllBytes(packet.data(), packet.size())) {
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
    if (!ReceiveAllBytes(buffer.data(), packetSize)) {
        return std::string();
    }

    return std::string(buffer.data(), packetSize);
}

bool PacketHandler::SendAllBytes(const char* buffer, std::size_t length) {
    std::size_t totalBytesSent = 0;
    while (totalBytesSent < length) {
        ssize_t bytesSent = send(this->currentConnection.socket, buffer + totalBytesSent, length - totalBytesSent, 0);
        if (bytesSent <= 0) {
            return false;
        }
        totalBytesSent += bytesSent;
    }

    return true;
}

bool PacketHandler::ReceiveAllBytes(char* buffer, std::size_t length) {
    std::size_t totalBytesReceived = 0;
    while (totalBytesReceived < length) {
        ssize_t bytesReceived = recv(this->currentConnection.socket, buffer + totalBytesReceived, length - totalBytesReceived, 0);
        if (bytesReceived <= 0) {
            return false;
        }
        totalBytesReceived += bytesReceived;
    }

    return true;
}