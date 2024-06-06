#pragma once
#ifndef TERMINAL_H
#define TERMINAL_H

#include <mutex>
#include <string_view>

namespace Terminal {
	enum PrintType {
		INFO,
		WARNING,
		ERROR,
		SERVER
	};

	void Print(PrintType type, std::string_view info);
}

#endif // !TERMINAL_H
