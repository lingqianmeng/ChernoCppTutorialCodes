#include<iostream>

/*Show how to write very simple logging class, with enumeration declaration*/

class Log
{
public:
	// instead of previous version here the enum will be used. 
	enum LogLevel: const int 
	{
		LogLevelError, LogLevelWarning, LogLevelInfo
	};

private:
	LogLevel m_LogLevel = LogLevelInfo; // it means everything should be printed.

public:
	void SetLevel(LogLevel level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[Error]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[Warning]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::LogLevelInfo); // use Log:: just like being treated as static variables. So const varibles also class members not instance members?
	log.Info("Hello!");
	log.Warn("Hello!");
	log.Error("Hello!");
	std::cin.get();
}