#include "LineEditor.h"
#include <iostream>

void Usage() {
	printf("[메뉴선택] i-입력, d-삭제, r-변경, ,p-출력, f-찾아바꾸기, q-종료=> ");
}

void main() {
	char command;
	LineEditor editor;
	do {
		//Usage();
		command = getchar();
		switch (command) {
		case 'i': editor.InsertLine(); std::cout << "EOF" << std::endl; break;
		case 'd': editor.DeleteLine(); std::cout << "EOF" << std::endl; break;
		case 'r': editor.ReplaceLine(); std::cout << "EOF" << std::endl; break;
		case 'f': editor.FindReplace(); std::cout << "EOF" << std::endl; break;
		case 'p': editor.Display(); std::cout << "EOF" << std::endl; break;
		case 'q': break;
		}
		fflush(stdin);
	} while (command != 'q');
}