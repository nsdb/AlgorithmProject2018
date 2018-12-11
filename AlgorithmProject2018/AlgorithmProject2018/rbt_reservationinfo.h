#pragma once
#include <stdio.h>
#include "data_type.h"


ReservationNode* make_reservationInfo(int n_reservation);
ReservationNode* Search_tree(ReservationNode* node, int key);
void left_rotation(ReservationNode* root, ReservationNode* x);
void right_rotation(ReservationNode* root, ReservationNode* x);
ReservationNode* MinNum(ReservationNode* node);
ReservationNode* successor(ReservationNode* node);
ReservationNode* Fixup_Insert_RB(ReservationNode* root, ReservationNode* z);
void Fixup_Delete_RB(ReservationNode* root, ReservationNode* x);
ReservationNode* Insert_RB(ReservationNode* root, ReservationInfo key);
void Delete_RB(ReservationNode* root, int userId);
void PrintBst(ReservationNode* node, int space);
