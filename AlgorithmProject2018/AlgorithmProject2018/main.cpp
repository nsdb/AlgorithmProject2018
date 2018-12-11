#include <iostream>
#include "data_type.h"
#include "rbt_hotel.h"
#include "util.h"

void menu_add();
void menu_inquiry();

int main(void) {

	// 부지, 호텔, 교통수단 데이터 초기화
	init_data();

	// 최초 실행시
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "- 알고리즘 팀 프로젝트" << std::endl;
	std::cout << "- Tour reservation and scheduling system" << std::endl;
	std::cout << "- 참여자 : 김동우, 김도현, 김진범" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	// 메뉴, 끝내기를 누르면 종료
	int menu = -1;
	while (menu != 4) {

		std::cout << "- 메뉴 : 1-예약하기, 2-취소하기, 3-예약현황조회, 4-끝내기, 5-데이터조회" << std::endl;
		std::cout << "- 원하는 메뉴를 눌러주세요 : ";

		menu = input_number();
		switch (menu) {

		case 1: std::cout << "- 예약하기" << std::endl; menu_add();  break;
		case 2: std::cout << "- 취소하기" << std::endl; break; // TODO
		case 3: std::cout << "- 예약현황조회" << std::endl; break; // TODO
		case 4: std::cout << "- 끝내기" << std::endl; break;
		case 5: std::cout << "- 데이터조회" << std::endl; menu_inquiry(); break;
		default: std::cout << "- 다시 입력해주세요." << std::endl;

		}

	}

	std::cout << "- 이용해주셔서 감사합니다." << std::endl;
	





	return 0;


}

void menu_add() {

	std::cout << "- 여행기간을 입력해주세요 : ";
	int period = input_number();
	while (period <= 0) {
		std::cout << "- 여행기간은 하루 이상이어야 합니다. 다시 입력해주세요." << std::endl;
		std::cout << "- 여행기간을 입력해주세요 : ";
		period = input_number();
	}

	std::cout << "- 예산을 입력해주세요 : ";
	int budget = input_number();
	while (budget <= 0) {
		std::cout << "- 예산은 1원 이상이어야 합니다. 다시 입력해주세요." << std::endl;
		std::cout << "- 예산을 입력해주세요 : ";
		budget = input_number();
	}

	std::cout << "- 목적지 ID를 입력해주세요 : ";
	int destination = input_number();
	while (destination < 0) {
		std::cout << "- 목적지 ID는 1 이상이어야 합니다. 다시 입력해주세요." << std::endl;
		std::cout << "- 목적지 ID를 입력해주세요 : ";
		destination = input_number();
	}

	std::cout << "- 사용자 ID를 입력해주세요 : ";
	int user = input_number();
	while (user < 0) {
		std::cout << "- 사용자 ID는 1 이상이어야 합니다. 다시 입력해주세요." << std::endl;
		std::cout << "- 사용자 ID를 입력해주세요 : ";
		user = input_number();
	}

	add_reservation(period, budget, destination, user);

}

void menu_inquiry() {

	int menu = -1;

	std::cout << "- 데이터 조회 : 1-호텔, 2-부지, 3-교통수단" << std::endl;
	std::cout << "- 원하는 메뉴를 눌러주세요 : ";

	menu = input_number();
	switch (menu) {

	case 1: 
		std::cout << "- 부지 ID를 입력해주세요 : ";
		menu = input_number();
		print_hotel(menu);
		break;
	case 2: print_site(); break;
	case 3: print_transportation(); break;
	default: std::cout << "- 다시 입력해주세요." << std::endl;

	}


}