#include"Message.h"

Message::Message(const std::string& str) :content(str),time_stamp(createTimeStamp()){
};

Message::~Message() {

};

std::string Message::getContent() const{
	return content;
};

std::string Message::getTimeStamp() const{
	return time_stamp;
};

std::string Message::createTimeStamp() {

}