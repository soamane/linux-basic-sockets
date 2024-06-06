#include "session.h"

Session::Session(SOCKET socket) : socket(socket), packetHandler(socket) { 

}

Session::~Session() {
	if (this->socket != INVALID_SOCKET) {
		closesocket(this->socket);
	}
}

void Session::Run() {

    std::string jsonString = R"(
    {
        "name": "John Doe",
        "age": 30,
        "email": "johndoe@example.com",
        "address": {
            "street": "123 Main St",
            "city": "Anytown",
            "zip": "12345"
        },
        "phoneNumbers": [
            {
                "type": "home",
                "number": "123-456-7890"
            },
            {
                "type": "mobile",
                "number": "098-765-4321"
            }
        ]
    }
    )";

	this->packetHandler.SendStringPacket(jsonString);
}