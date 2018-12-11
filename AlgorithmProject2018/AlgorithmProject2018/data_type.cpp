#include <iostream>
#include "data_type.h"
#include "rbt_hotel.h"
#include "rbt_reservationinfo.h"

Site site[SITE_COUNT];
Transportation transportation[TRANSPORTATION_COUNT];

ReservationInfo reservation_info[RESERVATION_INFO_COUNT];
ReservationNode* reservation_node;

void init_data() {
	srand(time(NULL));

	std::cout << "- 여행 정보 데이터 초기화" << std::endl;

	// site, hotel init
	int site_time[SITE_COUNT];
	set_random_array(site_time, SITE_COUNT, SITE_TIME_MIN, SITE_TIME_MAX, TRUE);
	int site_price[SITE_COUNT];
	set_random_array(site_price, SITE_COUNT, SITE_PRICE_MIN, SITE_PRICE_MAX, FALSE);

	for (int i = 0; i < SITE_COUNT; i++) {

		site[i].id = i;
		site[i].time = site_time[i];
		site[i].price = site_price[i];

		int hotel_price[HOTEL_COUNT];
		set_random_array(hotel_price, HOTEL_COUNT, HOTEL_PRICE_MIN, SITE_PRICE_MAX, FALSE);
		for (int j = 0; j < HOTEL_COUNT; j++) {
			site[i].hotel[j].id = j;
			site[i].hotel[j].price = hotel_price[j];
		}

		site[i].hotel_node = make_hotelTree(i);


	}

	std::cout << "- 호텔, 부지 데이터 초기화 완료" << std::endl;

	// transformation init
	int transfortation_time[TRANSPORTATION_COUNT];
	set_random_array(transfortation_time, TRANSPORTATION_COUNT, TRANSPORTATION_TIME_MIN, TRANSPORTATION_TIME_MAX, TRUE);
	int transfortation_price[TRANSPORTATION_COUNT];
	set_random_array(transfortation_price, TRANSPORTATION_COUNT, TRANSPORTATION_PRICE_MIN, TRANSPORTATION_PRICE_MAX, FALSE);
	int transfortation_departure[TRANSPORTATION_COUNT];
	int transfortation_arrival[TRANSPORTATION_COUNT];
	set_random_array(transfortation_departure, TRANSPORTATION_COUNT, 0, SITE_COUNT - 1, TRUE);
	set_random_array(transfortation_arrival, TRANSPORTATION_COUNT, 0, SITE_COUNT - 1, TRUE);

	for (int i = 0; i < TRANSPORTATION_COUNT; i++) {

		transportation[i].id = i;
		transportation[i].time = transfortation_time[i];
		transportation[i].price = transfortation_price[i];
		transportation[i].departure = &site[transfortation_departure[i]];
		transportation[i].arrival = &site[transfortation_arrival[i]];

	}

	std::cout << "- 교통수단 데이터 초기화 완료" << std::endl;


}

void add_reservation(int period, int budget, int destination, int userId) {

	if (Search_tree(reservation_node, userId) != NULL) {
		std::cout << "- 이미 예약하셨습니다. 예약을 취소한 후 다시 시도해주세요." << std::endl;

	} else {
		ReservationInfo info;
		info.period = period;
		info.budget = budget;
		info.destination = destination;
		info.userId = userId;

		reservation_node = Insert_RB(reservation_node, info);
		std::cout << "- 예약에 성공하였습니다." << std::endl;
	}

}

void remove_reservation(int userId) {

	if (Search_tree(reservation_node, userId) == NULL) {
		std::cout << "- 예약정보가 없습니다." << std::endl;
	} else {

		Delete_RB(reservation_node, userId);
		std::cout << "- 예약을 취소하였습니다." << std::endl;
		
	}

}



void print_hotel(int site_id) {
	std::cout << "- 해당 부지의 호텔 정보가 담긴 RBT를 출력합니다." << std::endl;
	PrintBst(site[site_id].hotel_node, 0);

}
void print_site() {
	for (int i = 0; i < SITE_COUNT; i++) {
		std::cout << "site " << i << 
			" : id=" << site[i].id << 
			", time=" << site[i].time << 
			", price=" << site[i].price << 
			std::endl;
	}
}
void print_transportation() {
	for (int i = 0; i < TRANSPORTATION_COUNT; i++) {
		std::cout << "transportation " << i << 
			" : id=" << transportation[i].id << 
			", time=" << transportation[i].time << 
			", price=" << transportation[i].price << 
			", departure_site_id=" << transportation[i].departure->id <<
			", arrival_site_id=" << transportation[i].arrival->id <<
			std::endl;
	}
}
void print_reservation() {
	std::cout << "- 예약 정보가 담긴 RBT를 출력합니다." << std::endl;
	PrintBst(reservation_node, 0);

}


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