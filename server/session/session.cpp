#include "session.h"

#include <unistd.h>
#include <thread>

Session::Session(CurrentConnection& connection) : currentConnection(connection), packetHandler(connection) {

}

Session::~Session() { 
	if (this->currentConnection.socket != -1) {
		this->currentConnection.CloseConnection();
	}
}

void Session::Run() {

}
