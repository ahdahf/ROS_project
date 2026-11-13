
#include"Publisher.h"
Publisher::Publisher(const std::string& node_name, const std::string& topic_name) :Node(node_name), topic(topic_name) {
	std::cout << "名称为" << node_name << ",话题为" << topic_name << "的推送者节点生成了" << std::endl;
}

Publisher::~Publisher() {
	std::cout << "名称为" << node_name << "的推送者节点被关闭了" << std::endl;
}

std::string Publisher::getTopic() const {
	return topic;
}

Message Publisher::sendMessage() {
	std::string content{};
	std::cout << "请输入消息内容:" << std::endl;
	try {
		std::cin >> content;
		if (content.empty()) {
			throw std::runtime_error("消息内容不能为空!");
		}
		else {
			Message message(content);
		}
	}
	catch (...) {
			std::cout << "输入错误,消息发送失败";
	}
