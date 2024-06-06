#include "../client/client.h"

int main() {
	try {
		Client client;
		client.JoinToServer("193.124.114.141", 1337);
	} catch (std::exception exception) {
		MessageBoxA(0, exception.what(), 0, MB_OK | MB_ICONERROR);
	}

	return 0;
}