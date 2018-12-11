#include "util.h"

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

// 배열에 무작위 정수를 생성합니다.
void set_random_array(int array[], int count, int min, int max, int duplicate_allow) {

	int dup_check = 0, n;

	for (int i = 0; i < count; i++) {

		do {
			n = rand() % (max - min + 1) + min;
			dup_check = 0;
			for (int j = 0; j < i && !duplicate_allow; j++) {
				if (n == array[j]) {
					dup_check = 1;
					break;
				}
			}
		} while (dup_check == 1); // 중복 신호가 오면 값을 다시 생성

		array[i] = n;
	}

}