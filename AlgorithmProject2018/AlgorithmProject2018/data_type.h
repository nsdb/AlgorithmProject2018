#pragma once

#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

const int TRANSPORTATION_COUNT = 300;
const int SITE_COUNT = 100;
const int HOTEL_COUNT = 100;
const int RESERVATION_INFO_COUNT = 1000;

const int HOTEL_PRICE_MIN = 50000;
const int HOTEL_PRICE_MAX = 300000;

const int SITE_TIME_MIN = 3;
const int SITE_TIME_MAX = 30;
const int SITE_PRICE_MIN = 500000;
const int SITE_PRICE_MAX = 2000000;

const int TRANSPORTATION_TIME_MIN = 1;
const int TRANSPORTATION_TIME_MAX = 20;
const int TRANSPORTATION_PRICE_MIN = 5000;
const int TRANSPORTATION_PRICE_MAX = 200000;

struct HotelNode;

typedef struct Hotel {
	int id;
	int price;
}Hotel;

typedef struct Site {
	int id;
	int time;
	int price;
	Hotel hotel[HOTEL_COUNT];
	HotelNode* hotel_node;
}Site;

typedef struct Transportation {
	int id;
	int time;
	int price;
	Site *departure, *arrival;
} Transportation;

enum nodeColor { red, black };

typedef struct HotelNode {
	Hotel hotel;
	enum nodeColor color;
	HotelNode* left, *right, *parent;
}Node;

typedef struct ReservationInfo {
    int site[SITE_COUNT];
    int hotel[HOTEL_COUNT];
    int transportation[TRANSPORTATION_COUNT];

    int n_site;//length of site[]
    int n_hotel;//length of hotel[]
    int n_tran;//length of transportation[]

    int period;
    int budget;
    int destination;
    int userId;
}ReservationInfo;

typedef struct ReservationNode{
    ReservationInfo reservationInfo;
    enum nodeColor color;
    struct ReservationNode* left, *right, *parent;
}ReservationNode;


void init_data();

void add_reservation(int period, int budget, int destination, int userId);

void print_hotel(int site_id);
void print_site();
void print_transportation();

void set_random_array(int array[], int count, int min, int max, int duplicate_allow);


