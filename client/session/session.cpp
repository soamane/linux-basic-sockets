#include "session.h"


#include <iostream>
Session::Session(SOCKET socket) : socket(socket), packetHandler(socket) { 

}

Session::~Session() {
	if (this->socket != INVALID_SOCKET) {
		closesocket(this->socket);
	}
}

void Session::Run() {

}