#pragma once
#include "Node.h"
class LinkedList {
protected:
	Node org; // 헤드포인터가 아님!
public:
	LinkedList()
		: org("") {}
	void clear() { while (!isEmpty()) delete remove(0); }
	~LinkedList() { clear(); }
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
	Node* find(const char* str) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(str)) return p;
		return NULL;
	}
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;;
		}
		return count;
	}
};