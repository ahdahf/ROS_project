
#include"Message.h"

Message::Message(const std::string& str) :content(str),time_stamp(createTimeStamp()){
};

Message::~Message() {

};

std::string Message::getContent() const{
	return content;
};

std::string Message::getTimeStamp() const{
	createTimeStamp;
	return time_stamp;

};

std::string Message::createTimeStamp() {
	char buffer[128];
	time_t now = std::time(nullptr);
	std::tm* timeptr = localtime(&now);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeptr);
	std::string time_stamp = buffer;
	return time_stamp;
}
