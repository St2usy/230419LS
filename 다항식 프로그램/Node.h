#pragma once
#include <iostream>

class Node {
	Node* link;
	float coef;
	int degree;
public:
	Node(float c = 0, int d = 0)
		: coef(c), degree(d) {
		link = NULL;
	}
	Node* getLink() {
		return link;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << coef << " x^" << degree << " + ";
	}
	void display2() {
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << coef << " x^" << degree ;
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
	friend class LinkedList;
};