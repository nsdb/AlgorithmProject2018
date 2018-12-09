#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct Hotel{
    int id;
    int price;
}Hotel;

struct Site{
    int id;
    int time;
    int price;
    Hotel hotel[100];
}site[100];

struct Transportation{
    int id;
    int time;
    int price;
    struct Site departure, arrival;
}transportation[300];

int main()
{
    int destination, budget, period;



    //input destination, budget, period
    printf("Destination: ");
    scanf("%d", &destination);
    printf("Budget: ");
    scanf("%d", &budget);
    printf("Period: ");
    scanf("%d", &period);


    return 0;
}
