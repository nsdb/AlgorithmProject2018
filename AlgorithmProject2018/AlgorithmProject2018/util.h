#pragma once

#include <iostream>

// ������ �Է¹޽��ϴ�. ������ �ƴѰ�� -1�� �����մϴ�.
int input_number() {

	int value = -1;

	std::cin >> value;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	return value;




}