#pragma once
#ifndef TERMINAL_H
#define TERMINAL_H

#include <mutex>
#include <string>
#include <initializer_list>

namespace Terminal {
	enum PrintType {
		INFO,
		WARNING,
		ERROR,
		SERVER
	};

	void Print(PrintType type, std::initializer_list<std::string> info);
}

#endif // !TERMINAL_H
