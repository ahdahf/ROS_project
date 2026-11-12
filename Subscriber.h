#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include "Node.h"
#include"Message.h"
class Subscriber : public Node {
private:
	std::string topic;

public:
	Subscriber(const std::string&,const std::string&);

	~Subscriber() override;

	std::string getTopic() const;

	void receiveMessage(const Message&);
};
