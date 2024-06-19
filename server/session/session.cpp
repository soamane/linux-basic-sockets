#include "session.h"

#include "../terminal/terminal.h"

#include <thread>
Session::Session(std::shared_ptr<CurrentConnection> connection) : currentConnection(connection), packetHandler(std::make_unique<PacketHandler>(connection)) {

}

Session::~Session() { 
	if (this->currentConnection->socket != -1) {
		this->currentConnection->CloseConnection();
	}
}

void Session::Run() {
	while (true) {
		Terminal::Print(Terminal::PrintType::INFO, { this->packetHandler->ReceiveStringPacket() });
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
