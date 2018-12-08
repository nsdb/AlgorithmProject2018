#pragma once

#include <iostream>

// 정수를 입력받습니다. 정수가 아닌경우 -1을 리턴합니다.
int input_number() {

	int value = -1;

	std::cin >> value;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	return value;




}