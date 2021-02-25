#pragma once
#pragma once
#include <ostream>
#include <sstream>
#define ERR ErrorLog().err()
#define ERROR_LOG_FILE_PATH "logs/error.log"

class ErrorLog {
private:
	std::ostringstream os;
public:
	ErrorLog();
	virtual ~ErrorLog();
	std::ostringstream& err();
	static void EmptyLog();
};