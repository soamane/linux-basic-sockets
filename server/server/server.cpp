#include "server.h"

#include <memory>
#include <thread>
#include <string>

#include "../session/session.h"
#include "../terminal/terminal.h"

void Server::Start(std::string_view address, unsigned short port) {
	Terminal::Print(Terminal::PrintType::SERVER, { "Welcome to ALS (Aceid Linux Server)" });

	for (unsigned int id = 0; id < SOMAXCONN; id++) {
		std::shared_ptr<CurrentConnection> currentConnection = this->Accept(address, port);
		if (currentConnection == nullptr) {
			continue;
		}

		currentConnection->id = id;
		this->connections.push_back(currentConnection);

		std::unique_ptr<Session> currentSession = std::make_unique<Session>(currentConnection);
		std::thread sessionThread([currentSession = std::move(currentSession)]() {
			currentSession->Run();
		});

		Terminal::Print(Terminal::PrintType::SERVER, { "New connection accepted" });
		Terminal::Print(Terminal::PrintType::INFO, { "Connection information:" });
		Terminal::Print(Terminal::PrintType::INFO, { "Identificator:", std::to_string(currentConnection->id) });
		Terminal::Print(Terminal::PrintType::INFO, { "Endpoint (address:port):", std::string(inet_ntoa(currentConnection->info.sin_addr)), ":", std::to_string(currentConnection->info.sin_port) });

		sessionThread.detach();
	}
}
