#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Hotel {
	int id;
	int price;
}Hotel;

typedef struct Site {
	int id;
	int time;
	int price;
	Hotel hotel[100];
//	Node* hotel_node;
}Site;

typedef struct Transportation {
	int id;
	int time;
	int price;
	Site *departure, *arrival;
} TRANSPORTATION;

typedef struct ReservationInfo {
    int site[100];
    int hotel[100];
    int transportation[300];

    int n_site;
    int n_hotel;
    int n_tran;

    int period;
    int budget;
    int destination;
    int userId;
}ReservationInfo;

enum nodeColor{red, black};

typedef struct Reservation_Node{
    ReservationInfo reservationInfo;
    enum nodeColor color;
    struct Reservation_Node* left, *right, *parent;
}RESERVATION_Node;

void make_reservationInfo(int n_reservation);
RESERVATION_Node* Search_tree(RESERVATION_Node* node, int key, int n_site);
void left_rotation(RESERVATION_Node* root, RESERVATION_Node* x);
void right_rotation(RESERVATION_Node* root, RESERVATION_Node* x);
RESERVATION_Node* MinNum(RESERVATION_Node* node);
RESERVATION_Node* successor(RESERVATION_Node* node);
RESERVATION_Node* Fixup_Insert_RB(RESERVATION_Node* root, RESERVATION_Node* z);
void Fixup_Delete_RB(RESERVATION_Node* root, RESERVATION_Node* x);
RESERVATION_Node* Insert_RB(RESERVATION_Node* root, ReservationInfo key);
void Delete_RB(RESERVATION_Node* root, int userId);
void PrintBst(RESERVATION_Node* node, int space);
void make_node(int userId);//info[]에 정보 넣기

void setA(int a[]);//날릴 부분


RESERVATION_Node* root =  NULL;
ReservationInfo info[1000];//그냥 넉넉하게 잡아논것이므로 크기를 바꿔도 됨


//이것들을 넘겨줘야 합니다. 어디거쳐서 어떤 호텔과 교통을 쓴는지 정해지면 저장해야 할 것들입니다.
int s_data[100];//그냥 넉넉하게 잡아논것
int h_data[100];//그냥 넉넉하게 잡아논것
int t_data[300];//그냥 넉넉하게 잡아논것
int n_reservation;//reservation_info 개수로 사용자 추가될 때마다 +1 해줘야함. 처음에는 0으로 초기화
int n_site;//방문하는 site의 총 개수(출발지 포함) = s_data의 유효한 개수 = info[]에 들어갈 site[]의 크기
int n_hotel;// 위와 비슷
int n_tran;// 위와 비슷

//요것들은 입력으로 들어오겠지요? 날리세요
int period;
int budget;
int destination;

int main()
{
//날릴부분
    srand(time(NULL));

    period = 10;
    budget = 1000;
    n_reservation = 5;
    n_site = 10;
    n_hotel = 10;
    n_tran = 9;

    int A[20] = {-1};

    for(int j =0; j< n_reservation; j++){
        setA(A);
        for(int i=0; i<n_site; i++){
            s_data[i] = A[i];
        }
        setA(A);
        for(int i=0; i<n_hotel; i++){
            h_data[i] = A[i];
        }
        setA(A);
        for(int i=0; i<n_tran; i++){
            t_data[i] = A[i];
        }
        destination = s_data[n_site-1];

        make_node(j);
    }

    for(int i=0; i<n_reservation; i++){
        printf("user ID: %d, period: %d, budget: %d, destination: %d\n", info[i].userId, info[i].period, info[i].budget, info[i].destination);
        printf("site:\t\t");
        for(int j=0; j<n_site-1; j++){
            printf("%d\t->\t", info[i].site[j]);
        }
        printf("%d\n", info[i].site[n_site-1]);

        printf("transportation:\t\t");
        for(int j=0; j<n_tran-1; j++){
            printf("%d\t\t", info[i].site[j]);
        }
        printf("%d\n", info[i].site[n_tran-1]);

        printf("hotel:\t\t");
        for(int j=0; j<n_hotel-1; j++){
            printf("%d\t\t", info[i].hotel[j]);
        }
        printf("%d\n\n", info[i].hotel[n_hotel-1]);
    }
//


    for(int i=0; i<n_reservation; i++){
        root = Insert_RB(root, info[i]);
    }
    PrintBst(root, 0);
    printf("\n");

    return 0;
}

void make_reservationInfo(int n_reservation){
    for(int i=0; i<n_reservation; i++){
        Insert_RB(root, info[i]);
    }
}


RESERVATION_Node* Search_tree(RESERVATION_Node* node, int key){// search for id -> key is userid
    if(node == NULL){
        return NULL;
    }
    if(node->reservationInfo.userId == key){
        return node;
    }
    if(node->reservationInfo.userId > key){
        return Search_tree(node->left, key);
    }

    return Search_tree(node->right, key);
}

void left_rotation(RESERVATION_Node* root, RESERVATION_Node* x){
    RESERVATION_Node* y = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    y = x->right;
    x->right = y->left;

    if(y->left != NULL){
        y->left->parent = x;
    }
    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return;
}

void right_rotation(RESERVATION_Node* root, RESERVATION_Node* x){
    RESERVATION_Node* y = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    y = x->left;
    x->left = y->right;

    if(y->right != NULL){
        y->right->parent = x;
    }
    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;

    return;
}

RESERVATION_Node* MinNum(RESERVATION_Node* node){
    while(node->left){
        node = node->left;
    }
    return node;
}

RESERVATION_Node* successor(RESERVATION_Node* node){
    if(node->right != NULL){
        return MinNum(node->right);
    }
    RESERVATION_Node* p = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));
    p = node->parent;
    while(p && (node->reservationInfo.userId > p->reservationInfo.userId)){
        node = p;
        p = p->parent;
    }
    return p;
}

RESERVATION_Node* Fixup_Insert_RB(RESERVATION_Node* root, RESERVATION_Node* z){
    RESERVATION_Node* y = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    while(z->parent != NULL && z->parent->parent != NULL && z->parent->color == red){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;

            if(y!= NULL && y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else if(z == z->parent->right){
                z = z->parent;
                left_rotation(root,  z);
            }

            else{
                z->parent->color = black;
                z->parent->parent->color = red;
                right_rotation(root, z->parent->parent);
            }
        }
        else{
            y = z->parent->parent->left;

            if(y!= NULL && y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else if(z == z->parent->left){
                z = z->parent;
                right_rotation(root,  z);
            }

            else{
                z->parent->color = black;
                z->parent->parent->color = red;
                left_rotation(root, z->parent->parent);
            }
        }
    }

    RESERVATION_Node* p = z;
    while(p->parent)
        p = p->parent;
    root = p;
    root->color = black;
    return root;
}

void Fixup_Delete_RB(RESERVATION_Node* root, RESERVATION_Node* x){
    RESERVATION_Node* w = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    while(x != root && x->color == black){
        if(x == x->parent->left){
            w = x->right->parent;

            if(w->color == red){
                w->color = black;
                x->parent->color = red;
                left_rotation(root, x->parent);
                w = x->parent->right;
            }

            if(w->left->color == black && w->right->color == black){
                w->color = red;
                x = x->parent;
            }
            else if(w->right->color == black){
                w->left->color = black;
                w->color = red;
                right_rotation(root, w);
                w = x->parent->right;
            }

            else{
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                left_rotation(root, x->parent);
                x = root;
            }
        }
        else{
            w = x->left->parent;

            if(w->color == red){
                w->color = black;
                x->parent->color = red;
                left_rotation(root, x->parent);
                w = x->parent->left;
            }

            if(w->right->color == black && w->left->color == black){
                w->color = red;
                x = x->parent;
            }
            else if(w->left->color == black){
                w->right->color = black;
                w->color = red;
                right_rotation(root, w);
                w = x->parent->left;
            }

            else{
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

RESERVATION_Node* Insert_RB(RESERVATION_Node* root, ReservationInfo key){//userId 기준으로 생성
    RESERVATION_Node* x = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));
    RESERVATION_Node* y = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));
    RESERVATION_Node* z = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    if(Search_tree(root, key.userId) != NULL)//key is already in the tree
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
    for(int i=0; i<key.n_site; i++){
        z->reservationInfo.site[i] = key.site[i];
    }
    for(int i=0; i<key.n_hotel; i++){
        z->reservationInfo.hotel[i] = key.hotel[i];
    }
    for(int i=0; i<key.n_tran; i++){
        z->reservationInfo.transportation[i] = key.transportation[i];
    }


    while(x){
        y = x;
        if(z->reservationInfo.userId < x->reservationInfo.userId)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == NULL)
        root = z;
    else if(z->reservationInfo.userId < y->reservationInfo.userId)
        y->left = z;
    else
        y->right = z;

    z->left = z->right = NULL;
    z->color = red;
    return Fixup_Insert_RB(root, z);
}

void Delete_RB(RESERVATION_Node* root, int userId){
    RESERVATION_Node* x = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));
    RESERVATION_Node* y = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));
    RESERVATION_Node* z = (RESERVATION_Node*)malloc(sizeof(RESERVATION_Node));

    z = Search_tree(root, userId);
    if(z == NULL)
        return;

    if(z->left == NULL || z->right == NULL)
        y = z;
    else
        y = successor(z);

    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if(x != NULL)
        x->parent = y->parent;

    if(y->parent == NULL)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if(y != z)
        z->reservationInfo.userId = y->reservationInfo.userId;
    if(y->color == black)
        Fixup_Delete_RB(root, x);

    free(y);
}

void PrintBst(RESERVATION_Node* node, int space){
    if(node == NULL)
        return;

    space ++;

    PrintBst(node->right, space);
    printf("\n");
    for(int i=1; i< space; i++)
        printf("\t");

    printf("id: %d\n", node->reservationInfo.userId);

    PrintBst(node->left, space);
}

void make_node(int userId){
    info[userId].budget = budget;
    info[userId].destination = destination;
    info[userId].period = period;
    info[userId].userId = userId;
    info[userId].n_hotel = n_hotel;
    info[userId].n_site = n_site;
    info[userId].n_tran = n_tran;
    for(int i=0; i<n_hotel; i++){
        info[userId].hotel[i] = h_data[i];
    }
    for(int i=0; i<n_site; i++){
        info[userId].site[i] = s_data[i];
    }
    for(int i=0; i<n_tran; i++){
        info[userId].transportation[i] = t_data[i];
    }
}


void setA(int a[]){//날릴것
    for(int i=0; i<10; i++){
        int dup = 0, n;
        do{
            n = rand()%50;
            for(int j=0; j<i ;j++){
                if(n == a[j]){
                    dup = 1;
                    break;
                }
                else dup = 0;
            }
        }while(dup == 1);
        a[i] = n;
    }
}
