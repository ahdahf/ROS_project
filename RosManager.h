#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Publisher.h"
#include"Subscriber.h"
class RosManager {
private:
	std::vector<Publisher> publishers;
	std::vector<Subscriber>subscribers;
public:
	RosManager();

	~RosManager();

	Publisher registerPublisher();

	Subscriber registerSubscriber();

	void relayMessage();

	void closeNode();

};