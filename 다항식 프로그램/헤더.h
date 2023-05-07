#pragma once
#include <iostream>
#include "LinkedList.h"
class Polynomial {
	LinkedList degree; // ���׽��� ������ ����
	LinkedList coef; // �� �׿� ���� ���
public:
	Polynomial() {}

	void read() {
		int n; // ���� ����
		int degree_temp; // ����
		int coef_temp;   // ���
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> degree_temp >> coef_temp;
			degree.insert(i, new Node<int>(degree_temp));
			coef.insert(i, new Node<int>(coef_temp));
		}
	}

	void add(Polynomial a, Polynomial b) {
		/*if(a.degree.getHead()->getData()>= b.degree.getHead()->getData())*/
		while (!a.degree.isEmpty()) {
			if(a.degree.remove(0)->getData()== b.degree.remove(0)->getData())
				a.coef.replace(0)
		}
	}
};