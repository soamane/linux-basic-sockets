#include "session.h"

Session::Session(std::shared_ptr<SOCKET> socket) : currentSocket(socket), packetHandler(std::make_unique<PacketHandler>(socket)) {

}

Session::~Session() {
	if (*this->currentSocket != INVALID_SOCKET) {
		closesocket(*this->currentSocket);
	}
}

void Session::Run() {
	while (true) {
		this->packetHandler->SendStringPacket("Hello!");
		Sleep(500);
	}
}