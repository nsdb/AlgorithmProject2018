#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct HOTEL{
    int id;
    int price;
}HOTEL;

struct SITE{
    int id;
    int time;
    int price;
    HOTEL hotel[100];
}site[100];

struct TRANSPORTATION{
    int id;
    int time;
    int price;
    struct SITE departure, arrival;
}transportation[300];

enum nodeColor{red, black};

typedef struct Node{
    HOTEL hotel;
    enum nodeColor color;
    struct Node* left, *right, *parent;
}Node;

void make_hotelTree(int n_site);
Node* Search_tree(struct Node* node, int key, int n_site);
void left_rotation(Node* root, Node* x);
void right_rotation(Node* root, Node* x);
Node* MinNum(struct Node* node);
Node* successor(struct Node* node);
Node* Fixup_Insert_RB(Node* root, Node* z);
void Fixup_Delete_RB(Node* root, Node* x);
Node* Insert_RB(Node* root, HOTEL key, int n_site);
void Delete_RB(Node* root, HOTEL key, int n_site);
void PrintBst(struct Node* node, int space);


void setA(int a[]);//날릴 부분


struct Node* root =  NULL;

int main()
{
//날릴부분
    srand(time(NULL));


    int A[20] = {-1};

    printf("A[]: ");

    setA(A);
    for(int i=0; i<20; i++){
        site[0].hotel[i].id = i;
        site[0].hotel[i].price = A[i];
    }
    printf("---------------------------------------------\n");
//

    int n_site;
    for(int i=0; i<100; i++){
        root = Insert_RB(root, site[n_site].hotel[i], 0);
    }
    printf("Hotel\n\n");
    PrintBst(root, 0);
    printf("\n");

    return 0;
}

void make_hotelTree(int n_site){
    for(int i=0; i<100; i++){
        Insert_RB(root, site[n_site].hotel[i], n_site);
    }
}


Node* Search_tree(struct Node* node, int key, int n_site){// search for id -> key is id of hotel
    if(node == NULL){
        return NULL;
    }
    if(node->hotel.id == key){
        return node;
    }
    if(node->hotel.price > site[n_site].hotel[key].price){
        return Search_tree(node->left, key, n_site);
    }

    return Search_tree(node->right, key, n_site);
}

void left_rotation(Node* root, Node* x){
    struct Node* y = (Node*)malloc(sizeof(Node));

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

void right_rotation(Node* root, Node* x){
    struct Node* y = (Node*)malloc(sizeof(Node));

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

Node* MinNum(struct Node* node){
    while(node->left){
        node = node->left;
    }
    return node;
}

Node* successor(struct Node* node){
    if(node->right != NULL){
        return MinNum(node->right);
    }
    struct Node* p = (Node*)malloc(sizeof(Node));
    p = node->parent;
    while(p && (node->hotel.price > p->hotel.price)){
        node = p;
        p = p->parent;
    }
    return p;
}

Node* Fixup_Insert_RB(Node* root, Node* z){
    struct Node* y = (Node*)malloc(sizeof(Node));

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

    struct Node* p = z;
    while(p->parent)
        p = p->parent;
    root = p;
    root->color = black;
    return root;
}

void Fixup_Delete_RB(Node* root, Node* x){
    struct Node* w = (Node*)malloc(sizeof(Node));

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

Node* Insert_RB(Node* root, HOTEL key, int n_site){//price 기준으로 생성
    struct Node* x = (Node*)malloc(sizeof(Node));
    struct Node* y = (Node*)malloc(sizeof(Node));
    struct Node* z = (Node*)malloc(sizeof(Node));

    if(Search_tree(root, key.id, n_site) != NULL)//key is already in the tree
        return root;

    y = NULL;
    x = root;
    z->hotel.price = key.price;
    z->hotel.id = key.id;

    while(x){
        y = x;
        if(z->hotel.price < x->hotel.price)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == NULL)
        root = z;
    else if(z->hotel.price < y->hotel.price)
        y->left = z;
    else
        y->right = z;

    z->left = z->right = NULL;
    z->color = red;
    return Fixup_Insert_RB(root, z);
}

void Delete_RB(Node* root, HOTEL key, int n_site){
    struct Node* x = (Node*)malloc(sizeof(Node));
    struct Node* y = (Node*)malloc(sizeof(Node));
    struct Node* z = (Node*)malloc(sizeof(Node));

    z = Search_tree(root, key.id, n_site);
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
        z->hotel.price = y->hotel.price;
    if(y->color == black)
        Fixup_Delete_RB(root, x);

    free(y);
}

void PrintBst(struct Node* node, int space){
    if(node == NULL)
        return;

    space ++;

    PrintBst(node->right, space);
    printf("\n");
    for(int i=1; i< space; i++)
        printf("\t");

    printf("id: %d\n", node->hotel.id);

    PrintBst(node->left, space);
}

void setA(int a[]){
    for(int i=0; i<20; i++){
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
        printf("%d ", a[i]);
    }
    printf("\n");
}
