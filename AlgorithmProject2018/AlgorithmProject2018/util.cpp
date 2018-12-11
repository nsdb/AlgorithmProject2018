#include "util.h"

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

// �迭�� ������ ������ �����մϴ�.
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
		} while (dup_check == 1); // �ߺ� ��ȣ�� ���� ���� �ٽ� ����

		array[i] = n;
	}

}