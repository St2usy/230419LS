#pragma once
#include <iostream>
#include "LinkedList.h"
class Polynomial {
	LinkedList degree; // 다항식의 각항의 차수
	LinkedList coef; // 각 항에 대한 계수
public:
	Polynomial() {}

	void read() {
		int n; // 항의 개수
		int degree_temp; // 차수
		int coef_temp;   // 계수
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