#include "../server/server.h"
#include "../terminal/terminal.h"

int main() {
	Server server;
	server.Start("193.124.114.141", 1337);
	return 0;
}