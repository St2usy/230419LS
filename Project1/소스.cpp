#include <iostream>
#pragma warning (disable:4996)
#define MAX_CHAR_PER_LINE 1000

class Node {
	char data[MAX_CHAR_PER_LINE];
	Node* link;
public:
	Node(const char* str = "") : link(NULL) { strcpy(data, str); }
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
	void print() { printf("%s", data); }
	bool hasData(const char* str) { return strcmp(str, data) == 0; }
};
class LineEditor {
private:
	Node org; // 헤드포인터가 아님!
public:
	LineEditor()
		: org("") {}
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
	void Display() {
		int i = 0;
		while (getchar() != '\n');
		for (Node* p = getHead(); p != NULL; p = p->getLink(), i++) {
			printf("%d: ", i);
			p->print();
		}
	}
	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		scanf("%d", &position);
		while (getchar() != '\n');
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		insert(position, new Node(line));
	}
	void DeleteLine() {
		int position;
		scanf("%d", &position);
		while (getchar() != '\n');
		delete remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		scanf("%d", &position);
		while (getchar() != '\n');
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		replace(position, new Node(line));
	}
	void FindReplace() {
		Node* n = &org;
		Node* prev = NULL;
		char line1[MAX_CHAR_PER_LINE];
		while (getchar() != '\n');
		fgets(line1, MAX_CHAR_PER_LINE, stdin);
		char line2[MAX_CHAR_PER_LINE];
		fgets(line2, MAX_CHAR_PER_LINE, stdin);
		for (; n != NULL; n = n->getLink())
			if (n->hasData(line1)) {
				for (Node* p = &org; p != n; p = p->getLink()) {
					prev = p;
				}
				if (prev != NULL) {
					delete prev->removeNext();
					prev->insertNext(new Node(line2));
				}
			}
	}
};
int main() {
	char command;
	LineEditor editor;
	do {
		command = getchar();
		switch (command) {
		case 'i': editor.InsertLine(); std::cout << "EOF" << std::endl; break;
		case 'd': editor.DeleteLine(); std::cout << "EOF" << std::endl; break;
		case 'r': editor.ReplaceLine(); std::cout << "EOF" << std::endl; break;
		case 'f': editor.FindReplace(); std::cout << "EOF" << std::endl; break;
		case 'p': editor.Display(); std::cout << "EOF" << std::endl; break;
		case 'q': break;
		}
	} while (command != 'q');

	return 0;
}