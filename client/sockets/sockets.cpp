#include "sockets.h"

#include <stdexcept>
#include <ws2tcpip.h>

Sockets::Sockets() {
    InitializeWSA();
}

Sockets::~Sockets() {
    CleanupWSA();
}

SOCKET Sockets::Connect(std::string_view address, u_short port) const {
    static SOCKET clientSocket = CreateClientSocket();
    if (clientSocket == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed");
    }
    static sockaddr_in endpoint = GetEndpointData(address, port);

    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == SOCKET_ERROR) {
        closesocket(clientSocket);
        return INVALID_SOCKET;
    }

    return clientSocket;
}

sockaddr_in Sockets::GetEndpointData(std::string_view address, u_short port) const {
    sockaddr_in endpoint{};

    endpoint.sin_family = AF_INET;
    endpoint.sin_port = htons(port);
    inet_pton(AF_INET, address.data(), &endpoint.sin_addr);

    return endpoint;
}

SOCKET Sockets::CreateClientSocket() const {
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        return INVALID_SOCKET;
    }

    return clientSocket;
}

void Sockets::InitializeWSA() {
    WSADATA wsaData{ };
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("Failed to initialize WSA");
    }
}

void Sockets::CleanupWSA() {
    WSACleanup();
}