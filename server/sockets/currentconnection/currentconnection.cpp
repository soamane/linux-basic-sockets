#include "currentconnection.h"

#include <cstring>
#include <unistd.h>

void CurrentConnection::CloseConnection() {
	this->id = -1;
	close(this->socket);
	memset(&this->info, 0, sizeof(this->info));
}
