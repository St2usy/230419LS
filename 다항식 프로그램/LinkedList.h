#pragma once
#include "Node.h"
class LinkedList {
	Node org; // 헤드포인터가 아님!
public:
	LinkedList()
		: org(0) {}
	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;;
		}
		return count;
	}
	void Add(LinkedList* operand) {
		LinkedList temp;
		int count = 0;
		Node* p = getHead();
		Node* t = operand->getHead();
		while (p != NULL && t != NULL) {
			if(p->degree == t->degree) {
				temp.insert(count++, new Node(p->coef + t->coef, p->degree));
				p = p->getLink();
				t = t->getLink();
			}
			else if (p->degree > t->degree) {
				temp.insert(count++, new Node(p->coef, p->degree));
				p = p->getLink();
			}
			else {
				temp.insert(count++, new Node(t->coef, t->degree));
				t = t->getLink();
			}
		}
		for (; p != NULL; p = p->getLink())
			temp.insert(count++, new Node(p->coef, p->degree));
		for (; t != NULL; t = t->getLink())
			temp.insert(count++, new Node(t->coef, t->degree));
		std::cout << "(" << temp.size() << ")" << " " << "=" << " ";
		temp.display3();
	}
	void read() {
		int n, degree;
		float coef;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> coef >> degree;
			insert(i, new Node(coef, degree));
		}
	}
	void display() {
		std::cout << "(" << size() << ")" << " " << "=" << " ";
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->getLink() == NULL)
				p->display2();
			else
				p->display();
		}
		std::cout << std::endl;
	}
	void display3() {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->getLink() == NULL)
				p->display2();
			else
				p->display();
		}
		std::cout << std::endl;
	}
};