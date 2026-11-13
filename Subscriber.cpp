
#include "Subscriber.h"
Subscriber::Subscriber(const std::string& node_name,const std::string&topic_name):Node(node_name),topic(topic_name){
	std::cout << "名称为" << node_name<<",话题为"<<topic_name<<"的订阅者节点生成了"<<std::endl;
}

Subscriber::~Subscriber() {
	std::cout << "名称为" << node_name<< "的订阅者节点被关闭了"<<std::endl;
}

std::string Subscriber::getTopic() const {
	return topic;
}

void Subscriber::receiveMessage(const Message& message) {
	std::cout <<message.getContent() << "\n" 
			  << message.getTimeStamp() << std::endl;
}
*/