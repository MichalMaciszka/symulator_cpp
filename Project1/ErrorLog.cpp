#include "ErrorLog.h"
#include<fstream>
#include<chrono>
#include<ctime>
#include<iomanip>
#define _CRT_SECURE_NO_WARNINGS 1

std::ostringstream& ErrorLog::err() {
	auto time = std::chrono::system_clock::now();
	auto time_t = std::chrono::system_clock::to_time_t(time);

	os << std::put_time(std::localtime(&time_t), "%X") << ":\t";
	return os;
}

void ErrorLog::EmptyLog() {
	std::ofstream logFile(ERROR_LOG_FILE_PATH);
	if (logFile.good())
		logFile.close();
}

ErrorLog::~ErrorLog() {
	os << std::endl;
	std::ofstream logFile(ERROR_LOG_FILE_PATH, std::ios::app);
	if (!logFile.good())
		return;
	logFile << os.str();
	logFile.close();
}

ErrorLog::ErrorLog() {}