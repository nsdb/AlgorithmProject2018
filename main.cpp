#include <stdio.h>
#include <stdlib.h>


using namespace std;

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
