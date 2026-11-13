#include<iostream>
int main() {
	std::string str{};
	std::cin >> str;
	if (str!="") {
		std::cout << str;
	}
	else {
		std::cout << '0';
	}
	return 0;
}