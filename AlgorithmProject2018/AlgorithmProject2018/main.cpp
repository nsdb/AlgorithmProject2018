#include <iostream>
#include "data_type.h"
#include "rbt_hotel.h"

int main(void) {

	// ����Ʈ, ȣ��, ���� ������ �ʱ�ȭ
	init_data();



	// rbt_hotel testcode
	//int n_site = 0;
	//for (int i = 0; i<HOTEL_COUNT; i++) {
	//	root = Insert_RB(root, site[n_site].hotel[i], 0);
	//}
	//printf("Hotel\n\n");
	//PrintBst(root, 0);
	//printf("\n");




	// ���� �����
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "- �˰��� �� ������Ʈ" << std::endl;
	std::cout << "- Tour reservation and scheduling system" << std::endl;
	std::cout << "- ������ : �赿��, �赵��, ������" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	// �޴�, �����⸦ ������ ����
	int menu = -1;
	while (menu != 4) {

		std::cout << "- �޴� : 1-�����ϱ�, 2-����ϱ�, 3-������Ȳ��ȸ, 4-������" << std::endl;
		std::cout << "- ���ϴ� �޴��� �����ּ��� : ";
		std::cin >> menu;
		
		// ���ڰ� �ƴҰ��, �Է¹��� ������ ��� ����� �ٽ� �Է¹޴´�.
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			menu = -1;
			std::cout << "- �ٽ� �Է����ּ���." << std::endl;

		} else switch (menu) {

		case 1: std::cout << "- �����ϱ�" << std::endl; break; // TODO
		case 2: std::cout << "- ����ϱ�" << std::endl; break; // TODO
		case 3: std::cout << "- ������Ȳ��ȸ" << std::endl; break; // TODO
		case 4: std::cout << "- ������" << std::endl; break;
		default: std::cout << "- �ٽ� �Է����ּ���." << std::endl;

		}

	}

	std::cout << "- �̿����ּż� �����մϴ�." << std::endl;
	





	return 0;


}