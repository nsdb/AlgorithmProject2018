#include <iostream>
#include "data_type.h"

SITE site[SITE_COUNT];
TRANSFORMATION transportation[TRANSPORTATION_COUNT];

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
			site[i].hotel[j].id = i * HOTEL_COUNT + j;
			site[i].hotel[j].price = hotel_price[j];
		}

	}

	std::cout << "- 호텔, 사이트 데이터 초기화 완료" << std::endl;

	// transformation init
	int transfortation_time[TRANSPORTATION_COUNT];
	set_random_array(transfortation_time, TRANSPORTATION_COUNT, TRANSPORTATION_TIME_MIN, TRANSPORTATION_TIME_MAX, TRUE);
	int transfortation_price[TRANSPORTATION_COUNT];
	set_random_array(transfortation_price, TRANSPORTATION_COUNT, TRANSPORTATION_PRICE_MIN, TRANSPORTATION_PRICE_MAX, TRUE);

	for (int i = 0; i < TRANSPORTATION_COUNT; i++) {

		transportation[i].id = i;
		transportation[i].time = transfortation_time[i];
		transportation[i].price = transfortation_price[i];

	}

	std::cout << "- 교통 데이터 초기화 완료" << std::endl;

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