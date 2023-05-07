#include "LinkedList.h"

int main() {
	LinkedList A;
	LinkedList B;
	A.read();
	B.read();
	A.display();
	B.display();
	A.Add(&B);
}