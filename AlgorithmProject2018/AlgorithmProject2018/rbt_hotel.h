
#pragma once 
#include <stdio.h>
#include "data_type.h"

Node* make_hotelTree(int n_site);
Node* Search_tree(Node* node, int key, int n_site);
void left_rotation(Node* root, Node* x);
void right_rotation(Node* root, Node* x);
Node* MinNum(Node* node);
Node* successor(Node* node);
Node* Fixup_Insert_RB(Node* root, Node* z);
void Fixup_Delete_RB(Node* root, Node* x);
Node* Insert_RB(Node* root, HOTEL key, int n_site);
void Delete_RB(Node* root, HOTEL key, int n_site);
void PrintBst(Node* node, int space);


