#include "client.h"

#include <thread>
#include <memory>
#include <iostream>

#include "../session/session.h"

void Client::JoinToServer(std::string_view address, USHORT port) {
	this->currentSocket = this->Connect(address, port);
	if (*this->currentSocket == INVALID_SOCKET) {
		return;
	}

	this->Join();
}

void Client::Join() {
	std::unique_ptr<Session> currentSession = std::make_unique<Session>(std::move(this->currentSocket));
	currentSession->Run();
}
