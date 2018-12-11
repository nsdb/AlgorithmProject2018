#include <iostream>
#include "data_type.h"
#include "rbt_hotel.h"
#include "util.h"

void menu_add();
void menu_inquiry();

int main(void) {

	// ����, ȣ��, ������� ������ �ʱ�ȭ
	init_data();

	// ���� �����
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "- �˰��� �� ������Ʈ" << std::endl;
	std::cout << "- Tour reservation and scheduling system" << std::endl;
	std::cout << "- ������ : �赿��, �赵��, ������" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	// �޴�, �����⸦ ������ ����
	int menu = -1;
	while (menu != 4) {

		std::cout << "- �޴� : 1-�����ϱ�, 2-����ϱ�, 3-������Ȳ��ȸ, 4-������, 5-��������ȸ" << std::endl;
		std::cout << "- ���ϴ� �޴��� �����ּ��� : ";

		menu = input_number();
		switch (menu) {

		case 1: std::cout << "- �����ϱ�" << std::endl; menu_add();  break;
		case 2: std::cout << "- ����ϱ�" << std::endl; break; // TODO
		case 3: std::cout << "- ������Ȳ��ȸ" << std::endl; break; // TODO
		case 4: std::cout << "- ������" << std::endl; break;
		case 5: std::cout << "- ��������ȸ" << std::endl; menu_inquiry(); break;
		default: std::cout << "- �ٽ� �Է����ּ���." << std::endl;

		}

	}

	std::cout << "- �̿����ּż� �����մϴ�." << std::endl;
	





	return 0;


}

void menu_add() {

	std::cout << "- ����Ⱓ�� �Է����ּ��� : ";
	int period = input_number();
	while (period <= 0) {
		std::cout << "- ����Ⱓ�� �Ϸ� �̻��̾�� �մϴ�. �ٽ� �Է����ּ���." << std::endl;
		std::cout << "- ����Ⱓ�� �Է����ּ��� : ";
		period = input_number();
	}

	std::cout << "- ������ �Է����ּ��� : ";
	int budget = input_number();
	while (budget <= 0) {
		std::cout << "- ������ 1�� �̻��̾�� �մϴ�. �ٽ� �Է����ּ���." << std::endl;
		std::cout << "- ������ �Է����ּ��� : ";
		budget = input_number();
	}

	std::cout << "- ������ ID�� �Է����ּ��� : ";
	int destination = input_number();
	while (destination < 0) {
		std::cout << "- ������ ID�� 1 �̻��̾�� �մϴ�. �ٽ� �Է����ּ���." << std::endl;
		std::cout << "- ������ ID�� �Է����ּ��� : ";
		destination = input_number();
	}

	std::cout << "- ����� ID�� �Է����ּ��� : ";
	int user = input_number();
	while (user < 0) {
		std::cout << "- ����� ID�� 1 �̻��̾�� �մϴ�. �ٽ� �Է����ּ���." << std::endl;
		std::cout << "- ����� ID�� �Է����ּ��� : ";
		user = input_number();
	}

	add_reservation(period, budget, destination, user);

}

void menu_inquiry() {

	int menu = -1;

	std::cout << "- ������ ��ȸ : 1-ȣ��, 2-����, 3-�������" << std::endl;
	std::cout << "- ���ϴ� �޴��� �����ּ��� : ";

	menu = input_number();
	switch (menu) {

	case 1: 
		std::cout << "- ���� ID�� �Է����ּ��� : ";
		menu = input_number();
		print_hotel(menu);
		break;
	case 2: print_site(); break;
	case 3: print_transportation(); break;
	default: std::cout << "- �ٽ� �Է����ּ���." << std::endl;

	}


}