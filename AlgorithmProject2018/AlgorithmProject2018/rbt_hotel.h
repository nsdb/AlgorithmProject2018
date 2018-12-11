
#pragma once 
#include <stdio.h>
#include "data_type.h"

HotelNode* make_hotelTree(int n_site);
HotelNode* Search_tree(HotelNode* node, int key, int n_site);
void left_rotation(HotelNode* root, HotelNode* x);
void right_rotation(HotelNode* root, HotelNode* x);
HotelNode* MinNum(HotelNode* node);
HotelNode* successor(HotelNode* node);
HotelNode* Fixup_Insert_RB(HotelNode* root, HotelNode* z);
void Fixup_Delete_RB(HotelNode* root, HotelNode* x);
HotelNode* Insert_RB(HotelNode* root, Hotel key, int n_site);
void Delete_RB(HotelNode* root, Hotel key, int n_site);
void PrintBst(HotelNode* node, int space);


