#include <stdio.h>

int N, M;

int graph[110][110];
int dist[110];
int sptset[110];

int dist_idx[110];

int minDistance(void);
void dijkstra(int s);
void f(int idx_);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	dijkstra(0);

	printf("%d\n", dist[M - 1]);

	f(M - 1);
	printf("%d \n", M);

	return 0;
}

void f(int idx_)
{
	if (dist_idx[idx_] != 0)
		f(dist_idx[idx_]);

	printf("%d ", dist_idx[idx_] + 1);
}

int minDistance(void)
{
	int min = 987654321;
	int min_idx;

	for (int i = 0; i < N; i++)
	{
		if (sptset[i] == 0 && dist[i] < min) {
			min = dist[i];
			min_idx = i;
		}
	}

	return min_idx;
}

void dijkstra(int s)
{
	for (int i = 0; i < N; i++)
		dist[i] = 987654321, sptset[i] = 0;

	dist[s] = 0; //start distance is zero


	for (int i = 0; i < N - 1; i++)
	{
		int mid = minDistance();

		sptset[mid] = 1; //�߾��� ���İ��� ������ �ε���

		for (int j = 0; j < N; j++)
		{
			if (sptset[j] == 0 && (dist[mid] + graph[mid][j] < dist[j]) && graph[mid][j]) {
				dist[j] = dist[mid] + graph[mid][j];
				dist_idx[j] = mid; //�ε��� �����Ų��.
			} //if
		}
	}
}