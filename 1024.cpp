#include <stdio.h>

int saero, garo;
int map[550][550];
int DT[550][550];

int result;

int solve(int saero, int garo);

int main(void)
{
	scanf("%d %d", &saero, &garo);

	for (int i = 0; i < saero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	DT[saero - 1][garo - 1] = 1;

	printf("%d\n", solve(0, 0));

	return 0;
}

int solve(int M, int N)
{
	if (DT[M][N])
		return DT[M][N];

	int cnt = 0;

	if (M + 1 < saero && map[M + 1][N] < map[M][N])
		cnt += solve(M + 1, N);
	if (M - 1 >= 0 && map[M - 1][N] < map[M][N])
		cnt += solve(M - 1, N);
	if (N + 1 < garo && map[M][N + 1] < map[M][N])
		cnt += solve(M, N + 1);
	if (N - 1 >= 0 && map[M][N - 1] < map[M][N])
		cnt += solve(M, N - 1);

	DT[M][N] = cnt;

	return DT[M][N];
}