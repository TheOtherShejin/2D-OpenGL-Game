#include "Logger.h"

void Logger::Log(std::string category, LEVEL level, std::string text) {
	std::cout << "[*][" << LevelToString(level) << "] " << category << ": " << text << '\n';
}

std::string Logger::LevelToString(LEVEL level) {
	switch (level) {
	case DEBUG:
		return "DEBUG";
		break;
	case INFO:
		return "INFO";
		break;
	case CRITICAL:
		return "CRITICAL";
		break;
	default:
		return "UNKNOWN";
		break;
	}
}