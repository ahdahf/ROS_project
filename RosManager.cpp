#include"RosManager.h"

RosManager::~RosManager() {
	publishers.clear();
	subscribers.clear();
}


void RosManager::registerPublisher() {
	std::string node_name{};
	std::string topic_name{};
	try {
		std::cout << "请输入发布者节点名称:" << std::endl;
		std::cin >> node_name;
		std::cout << "请输入发布者节点话题名称:" << std::endl;
		std::cin >> topic_name;
		if (node_name.empty() && topic_name.empty()) {
			std::cout<<"节点名称和话题名称不能为空!"<<std::endl;
			return;
		}
		else {
			for (const auto& publisher : publishers) {
				if (publisher.getNodeName() == node_name) {
					std::cout << "该节点已存在!" << std::endl;
					return;
				}
			}
			Publisher publisher(node_name, topic_name);
			publishers.push_back(publisher);
		}
	}
	catch (...) {
		std::cout << "注册失败:未知错误" << std::endl;
	}
}


void RosManager::registerSubscriber() {
	std::string node_name{};
	std::string topic_name{};
	try {
		std::cout << "请输入订阅者节点名称:" << std::endl;
		std::cin >> node_name;
		std::cout << "请输入订阅者节点话题名称:" << std::endl;
		std::cin >> topic_name;
		if (node_name.empty() && topic_name.empty()) {
			throw std::runtime_error("节点名称和话题名称不能为空!");
		}
		else {
			for (const auto& subscriber : subscribers) {
				if (subscriber.getNodeName() == node_name) {
					std::cout << "该节点已存在!" << std::endl;
					return;
				}
			}
			Subscriber subscriber(node_name, topic_name);
			subscribers.push_back(subscriber);
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "注册失败:" << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "注册失败:未知错误" << std::endl;
	}
}
void RosManager::relayMessage() {
	std::string node_name{};
	std::cout << "请输入发布者节点名称:" << std::endl;
	std::cin >> node_name;
	for (const auto& publisher : publishers) {
		if (publisher.getNodeName() == node_name) {
			Message message = publisher.sendMessage();
			for (const auto& subscriber : subscribers) {
				if (publisher.getTopic() == subscriber.getTopic()) {
					subscriber.receiveMessage(message);
				}
				else {
					std::cout << "未找到订阅该话题的订阅者节点!" << std::endl;
				}
			}
		}
		else {
			std::cout << "未找到该发布者节点!" << std::endl;
			return;
		}
	}
}
void RosManager::closeNode() {
	publishers.clear();
	subscribers.clear();
}


