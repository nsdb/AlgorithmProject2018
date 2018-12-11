#include "rbt_reservationinfo.h"


extern ReservationInfo reservation_info[RESERVATION_INFO_COUNT];


ReservationNode* make_reservationInfo(int n_reservation) {
	ReservationNode* root = NULL;
	for (int i = 0; i<n_reservation; i++) {
		root = Insert_RB(root, reservation_info[i]);
	}
	return root;
}


ReservationNode* Search_tree(ReservationNode* node, int key) {// search for id -> key is userid
	if (node == NULL) {
		return NULL;
	}
	if (node->reservationInfo.userId == key) {
		return node;
	}
	if (node->reservationInfo.userId > key) {
		return Search_tree(node->left, key);
	}

	return Search_tree(node->right, key);
}

void left_rotation(ReservationNode* root, ReservationNode* x) {
	ReservationNode* y = (ReservationNode*)malloc(sizeof(ReservationNode));

	y = x->right;
	x->right = y->left;

	if (y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;

	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;

	return;
}

void right_rotation(ReservationNode* root, ReservationNode* x) {
	ReservationNode* y = (ReservationNode*)malloc(sizeof(ReservationNode));

	y = x->left;
	x->left = y->right;

	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;

	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;

	y->right = x;
	x->parent = y;

	return;
}

ReservationNode* MinNum(ReservationNode* node) {
	while (node->left) {
		node = node->left;
	}
	return node;
}

ReservationNode* successor(ReservationNode* node) {
	if (node->right != NULL) {
		return MinNum(node->right);
	}
	ReservationNode* p = (ReservationNode*)malloc(sizeof(ReservationNode));
	p = node->parent;
	while (p && (node->reservationInfo.userId > p->reservationInfo.userId)) {
		node = p;
		p = p->parent;
	}
	return p;
}

ReservationNode* Fixup_Insert_RB(ReservationNode* root, ReservationNode* z) {
	ReservationNode* y = (ReservationNode*)malloc(sizeof(ReservationNode));

	while (z->parent != NULL && z->parent->parent != NULL && z->parent->color == red) {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;

			if (y != NULL && y->color == red) {
				z->parent->color = black;
				y->color = black;
				z->parent->parent->color = red;
				z = z->parent->parent;
			}
			else if (z == z->parent->right) {
				z = z->parent;
				left_rotation(root, z);
			}

			else {
				z->parent->color = black;
				z->parent->parent->color = red;
				right_rotation(root, z->parent->parent);
			}
		}
		else {
			y = z->parent->parent->left;

			if (y != NULL && y->color == red) {
				z->parent->color = black;
				y->color = black;
				z->parent->parent->color = red;
				z = z->parent->parent;
			}
			else if (z == z->parent->left) {
				z = z->parent;
				right_rotation(root, z);
			}

			else {
				z->parent->color = black;
				z->parent->parent->color = red;
				left_rotation(root, z->parent->parent);
			}
		}
	}

	ReservationNode* p = z;
	while (p->parent)
		p = p->parent;
	root = p;
	root->color = black;
	return root;
}

void Fixup_Delete_RB(ReservationNode* root, ReservationNode* x) {
	ReservationNode* w = (ReservationNode*)malloc(sizeof(ReservationNode));

	while (x != root && x->color == black) {
		if (x == x->parent->left) {
			w = x->right->parent;

			if (w->color == red) {
				w->color = black;
				x->parent->color = red;
				left_rotation(root, x->parent);
				w = x->parent->right;
			}

			if (w->left->color == black && w->right->color == black) {
				w->color = red;
				x = x->parent;
			}
			else if (w->right->color == black) {
				w->left->color = black;
				w->color = red;
				right_rotation(root, w);
				w = x->parent->right;
			}

			else {
				w->color = x->parent->color;
				x->parent->color = black;
				w->right->color = black;
				left_rotation(root, x->parent);
				x = root;
			}
		}
		else {
			w = x->left->parent;

			if (w->color == red) {
				w->color = black;
				x->parent->color = red;
				left_rotation(root, x->parent);
				w = x->parent->left;
			}

			if (w->right->color == black && w->left->color == black) {
				w->color = red;
				x = x->parent;
			}
			else if (w->left->color == black) {
				w->right->color = black;
				w->color = red;
				right_rotation(root, w);
				w = x->parent->left;
			}

			else {
				w->color = x->parent->color;
				x->parent->color = black;
				w->left->color = black;
				left_rotation(root, x->parent);
				x = root;
			}
		}
		x->color = black;
	}
}

ReservationNode* Insert_RB(ReservationNode* root, ReservationInfo key) {//userId 기준으로 생성
	ReservationNode* x = (ReservationNode*)malloc(sizeof(ReservationNode));
	ReservationNode* y = (ReservationNode*)malloc(sizeof(ReservationNode));
	ReservationNode* z = (ReservationNode*)malloc(sizeof(ReservationNode));

	if (Search_tree(root, key.userId) != NULL)//key is already in the tree
		return root;

	y = NULL;
	x = root;

	z->reservationInfo.budget = key.budget;
	z->reservationInfo.destination = key.destination;
	z->reservationInfo.period = key.period;
	z->reservationInfo.userId = key.userId;
	z->reservationInfo.n_hotel = key.n_hotel;
	z->reservationInfo.n_site = key.n_site;
	z->reservationInfo.n_tran = key.n_tran;
	for (int i = 0; i<key.n_site; i++) {
		z->reservationInfo.site[i] = key.site[i];
	}
	for (int i = 0; i<key.n_hotel; i++) {
		z->reservationInfo.hotel[i] = key.hotel[i];
	}
	for (int i = 0; i<key.n_tran; i++) {
		z->reservationInfo.transportation[i] = key.transportation[i];
	}


	while (x) {
		y = x;
		if (z->reservationInfo.userId < x->reservationInfo.userId)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->reservationInfo.userId < y->reservationInfo.userId)
		y->left = z;
	else
		y->right = z;

	z->left = z->right = NULL;
	z->color = red;
	return Fixup_Insert_RB(root, z);
}

void Delete_RB(ReservationNode* root, int userId) {
	ReservationNode* x = (ReservationNode*)malloc(sizeof(ReservationNode));
	ReservationNode* y = (ReservationNode*)malloc(sizeof(ReservationNode));
	ReservationNode* z = (ReservationNode*)malloc(sizeof(ReservationNode));

	z = Search_tree(root, userId);
	if (z == NULL)
		return;

	if (z->left == NULL || z->right == NULL)
		y = z;
	else
		y = successor(z);

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->reservationInfo.userId = y->reservationInfo.userId;
	if (y->color == black)
		Fixup_Delete_RB(root, x);

	free(y);
}

void PrintBst(ReservationNode* node, int space) {
	if (node == NULL)
		return;

	space++;

	PrintBst(node->right, space);
	printf("\n");
	for (int i = 1; i< space; i++)
		printf("\t");

	printf("[id: %d, period: %d, budget: %d, dest: %d]\n", node->reservationInfo.userId, node->reservationInfo.period, node->reservationInfo.budget, node->reservationInfo.destination);

	PrintBst(node->left, space);
}

