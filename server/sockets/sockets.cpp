#include "sockets.h"

#include <unistd.h>

const SOCKET Sockets::InitBaseSocket(std::string_view address, unsigned short port) const {
    static SOCKET baseSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (baseSocket == -1) {
        return -1;
    }

    static sockaddr_in endpoint = this->CreateEndpoint(address, port);

    if (bind(baseSocket, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == -1) {
        close(baseSocket);
        return -1;
    }

    if (listen(baseSocket, SOMAXCONN) == -1) {
        close(baseSocket);
        return -1;
    }

    return baseSocket;
}

const sockaddr_in& Sockets::CreateEndpoint(std::string_view address, unsigned short port) const {
    static sockaddr_in endpoint{ };

    endpoint.sin_family = AF_INET;
    endpoint.sin_port = htons(port);
    inet_pton(AF_INET, address.data(), &endpoint.sin_addr);

    return endpoint;
}

const std::shared_ptr<CurrentConnection> Sockets::Accept(std::string_view address, unsigned short port) const {
    static SOCKET baseSocket = this->InitBaseSocket(address, port);
    if (baseSocket == -1) {
        return nullptr;
    }

    sockaddr_in clientInfo{};
    socklen_t clientInfoSize = sizeof(clientInfo);

    CurrentConnection currentConnection{ };

    currentConnection.socket = accept(baseSocket, reinterpret_cast<sockaddr*>(&clientInfo), &clientInfoSize);
    if (currentConnection.socket == -1) {
        return nullptr;
    }

    currentConnection.info = clientInfo;

    return std::make_shared<CurrentConnection>(currentConnection);
}
