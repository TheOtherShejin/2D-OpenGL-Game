#pragma once

#include <iostream>
#include <string>

class Logger {
public:
	enum LEVEL {
		DEBUG,
		INFO,
		CRITICAL
	};

	static void Log(std::string category, LEVEL level, std::string text);
private:
	Logger() {}

	static std::string LevelToString(LEVEL level);
};