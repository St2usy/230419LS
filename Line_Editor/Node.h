#pragma once
#include "Line.h"
class Node : public Line {
	Node* link;
public:
	Node(const char* str = "") : Line(str), link(NULL) {}
	void setLInk(Node* p) { link = p; }
	Node* getLink() { return link; }
	void insertNext(Node* p) {
		if (p != NULL) {
			p->link = link;
			link = p;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};