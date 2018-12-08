#pragma once

#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

const int TRANSPORTATION_COUNT = 300;
const int SITE_COUNT = 100;
const int HOTEL_COUNT = 100;

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

struct Node;

typedef struct HOTEL {
	int id;
	int price;
}HOTEL;

typedef struct SITE {
	int id;
	int time;
	int price;
	HOTEL hotel[HOTEL_COUNT];
	Node* hotel_node;
}SITE;

typedef struct TRANSPORTATION {
	int id;
	int time;
	int price;
	SITE *departure, *arrival;
} TRANSFORMATION;

enum nodeColor { red, black };

typedef struct Node {
	HOTEL hotel;
	enum nodeColor color;
	Node* left, *right, *parent;
}Node;


void init_data();
void print_hotel(int site_id);
void print_site();
void print_transportation();
void set_random_array(int array[], int count, int min, int max, int duplicate_allow);


