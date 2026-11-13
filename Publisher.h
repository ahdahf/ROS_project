#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include"Node.h"
#include"Message.h"
class Publisher :public Node {
private:
	std::string topic;
public:
	Publisher(const std::string&, const std::string&);

	~Publisher() override;

	std::string getTopic() const;

	Message sendMessage();
};