#include "terminal.h"

#include "termcolor/termcolor.h"

#include <iostream>

void Terminal::Print(PrintType type, std::string_view info) {
	switch (type) {
		case Terminal::INFO:
			std::cout << termcolor::bold << termcolor::bright_green << "[INFO]" << ' ';
			break;

		case Terminal::WARNING:
			std::cout << termcolor::bold << termcolor::bright_yellow << "[WARNING]" << ' ';
			break;

		case Terminal::ERROR:
			std::cout << termcolor::bold << termcolor::bright_red << "[ERROR]" << ' ';
			break;

		case Terminal::SERVER:
			std::cout << '\n' << termcolor::bold << termcolor::bright_magenta << "[SERVER]" << ' ';
			break;

		default:
			break;
	}

	std::cout << termcolor::reset << info << std::endl;
}
