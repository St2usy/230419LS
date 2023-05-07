#pragma once
#include "Node.h"
class LinkedList {
	Node<int> org; // 헤드포인터가 아님!
public:
	LinkedList()
		: org(0) {}
	void clear() { while (!isEmpty()) delete remove(0); }
	Node<int>* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }
	Node<int>* getEntry(int pos) {
		Node<int>* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}
	void insert(int pos, Node<int>* n) {
		Node<int>* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}
	Node<int>* remove(int pos) {
		Node<int>* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	Node<int>* find(int val) {
		//for (Node<int>* p = getHead(); p != NULL; p = p->getLink())
		//	if (p->hasdata(val)) return p;
		//return NULL;
		Node<int>* n = &org;
		for (; n != NULL; n = n->getLink())
			if (n->hasdata(val)) return n;
		return NULL;
	}
	void replace(int pos, Node<int>* n) {
		Node<int>* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	Node<int>* findreplace(int val, Node<int>* new1) {
		Node<int>* n = &org;
		Node<int>* prev = NULL;
		for (; n != NULL; n = n->getLink())
			if (n->hasdata(val)) {
				for (Node<int>* p = &org; p != n; p = p->getLink()) {
					prev = p;
				}
				if (prev != NULL) {
					delete prev->removeNext();
					prev->insertNext(new1);
					return 0;
				}
			}
		return NULL;
	}
	int size() {
		int count = 0;
		for (Node<int>* p = getHead(); p != NULL; p = p->getLink()) {
			count++;;
		}
		return count;
	}
	void display() {
		int count = 0;
		std::cout << "[단순연결리스트 항목 수 = " << size() << "] : ";
		for (Node<int>* p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
		}
		std::cout << std::endl;
	}
};