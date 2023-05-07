#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "LinkedList.h"

class LineEditor : public LinkedList {
public:
	void Display(FILE* fp = stdout) {
		int i = 0;
		while (getchar() != '\n');
		for (Node* p = getHead(); p != NULL; p = p->getLink(), i++) {
			printf("%d: ", i);
			p->print(fp);
		}
	}
	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		//printf(" �Է��� ��ȣ: ");
		scanf("%d", &position);
		//printf(" �Է��� ����: ");
		while (getchar() != '\n');
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		insert(position, new Node(line));
	}
	void DeleteLine() {
		//printf(" ������ ��ȣ: ");
		int position;
		scanf("%d", &position);
		while (getchar() != '\n');
		delete remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		//printf(" �Է��� ��ȣ: ");
		scanf("%d", &position);
		//printf(" �Է��� ����: ");
		while (getchar() != '\n');
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		replace(position, new Node(line));
	}
	void FindReplace() {
		Node* n = &org;
		Node* prev = NULL;
		//printf(" ã���� ����: ");
		char line1[MAX_CHAR_PER_LINE];
		while (getchar() != '\n');
		fgets(line1, MAX_CHAR_PER_LINE, stdin);
		//printf(" �ٲ��� ����: ");
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