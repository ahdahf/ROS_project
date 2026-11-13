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

	~RosManager();

	void registerPublisher();

	void registerSubscriber();

	void relayMessage();

	void closeNode();

};