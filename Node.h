#pragma once
#include<iostream>
#include<string>
class Node {
protected:
	std::string node_name;

public:
	Node( const std::string&);

	virtual ~Node() = 0;

	std::string getNodeName() const;
	
};