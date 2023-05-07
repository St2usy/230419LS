#pragma once
#include <iostream>

template <typename T>
class Node {
	Node* link;
	T data;
public:
	Node(int val = 0)
		: data(val) {
		link = NULL;
	}
	Node* getLink() {
		return link;
	}
	T getData() {
		return data;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		std::cout << " " << data;
	}
	bool hasdata(int val) {
		return data == val;
	}
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (remove != NULL) {
			link = removed->link;
		}
		return removed;
	}
};