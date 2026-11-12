#pragma once
#include<iostream>
#include<ctime>
#include<string>
class Message {
private:
	std::string content;
	std::string time_stamp;
public:
	Message(const std::string&);
	~Message();
	std::string getContent() const;
	std::string getTimeStamp () const;
private:
	static std::string createTimeStamp();
};