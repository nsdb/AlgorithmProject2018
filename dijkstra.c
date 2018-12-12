#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_MAX 2147483647 // 최대 정수
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100 //정점의 수
#define INF 9999 //무한대(연결이 없는 경우)

int weight[MAX_VERTICES][MAX_VERTICES]; //네트워크의 인접 행렬, 여기서 weight는 시간을 의미함
int distance[MAX_VERTICES]; //시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES]; //방문한 정점 표시
int path[MAX_VERTICES][MAX_VERTICES]; //최단거리 정점까지 거치는 노드들을 저장
int check[MAX_VERTICES];//한 정점으로 가는 정점을 표시

void path_init(int path[][MAX_VERTICES]); //path 인접행렬 초기화
int choose(int distance[], int n, int found[]); // 최단시간에 갈 수 있는 정점을 찾는 함수
void shortest_path(int start, int n);//최단 경로 알고리즘

void main()
{
	int i, j;
	int start, destination;

	for (i = 0; i < MAX_VERTICES; i++) // weight 2차원배열 초기화
	{
		for (j = 0; j < MAX_VERTICES; j++)
		{
			if (i == j)
				weight[i][j] = 0;
			else
				weight[i][j] = INF;
		}
	}

	srand((unsigned)time(NULL));

	int rand_time;

	// i번 vertex와 연결 (transportation 총 300개)
	for (int i = 0; i < 12; i++)
	{
		for (int j = i + 1; j <= 99; j += (i + 1))
		{
			rand_time = (rand() * rand()) % 5 + 1;
			weight[i][j] = rand_time;
			weight[j][i] = rand_time;
		}
	}

	path_init(path);

	printf("시작 정점을 선택하시오 (0 ~ 99 사이의 정수 입력): ");
	scanf_s("%d", &start);
	printf("도착 정점을 선택하시오 (0 ~ 99 사이의 정수 입력): ");
	scanf_s("%d", &destination);
	printf("\n");

	shortest_path(start, MAX_VERTICES);

	printf("%d에서 %d까지의 최단시간: %d \n", start, destination, distance[destination]);
	printf("%d에서 %d까지의 노드: ", start, destination);

	for (i = 0; i < MAX_VERTICES; i++)
	{
		if (path[destination][i] != INF)
		{
			printf("%d->", path[destination][i]); //저장된 경로를 출력한다
		}
	}
	printf("%d\n", destination);
}

//path 인접행렬 초기화
void path_init(int path[][MAX_VERTICES])
{
	int i, j;

	for (i = 0; i<MAX_VERTICES; i++)
		for (j = 0; j<MAX_VERTICES; j++)
			path[i][j] = INF;
}

// 최단시간에 갈 수 있는 정점을 찾는 함수
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;

	min = INT_MAX;

	minpos = -1;

	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;

}

//최단 경로 알고리즘
void shortest_path(int start, int n)
{
	int i, j, u, w;

	for (i = 0; i < n; i++) //초기화
	{
		distance[i] = weight[start][i];
		found[i] = FALSE;
		check[i] = 1;
		path[i][0] = start;
	}

	found[start] = TRUE;//시작 정점 방문 표시

	distance[start] = 0;

	for (i = 0; i < n - 2; i++)
	{
		u = choose(distance, n, found);
		found[u] = TRUE;

		for (w = 0; w<n; w++)
		{
			if (!found[w])
			{
				if (distance[u] + weight[u][w] < distance[w])
				{
					if (i == 0) //처음에는 인접한 정점에 연결
					{
						path[w][check[w]] = u; //갱신된 경로를 경로 배열에 저장
						check[w]++;
					}
					else
					{
						for (j = 0; j < (check[u] + 1); j++) //저장된 만큼 반복
						{
							path[w][j] = path[u][j]; //경로를 갱신
							path[w][j + 1] = u; //끝부분에 자기자신을 저장
							check[w]++;
						}
					}
					distance[w] = distance[u] + weight[u][w];
				}
			}
		}
	}
}
