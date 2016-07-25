
#include <stdio.h>

int g_mem[110];
int g_cost[110];

int N, M;

int DT[110][11000];

int mymax(int a, int b);

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", &g_mem[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &g_cost[i]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 11000; j++)
		{
			if (g_cost[i] > j)
				DT[i][j] = DT[i - 1][j];
			else
				DT[i][j] = mymax(DT[i - 1][j], DT[i - 1][j - g_cost[i]] + g_mem[i]);
		}
	}

	for (int i = 0; i <= 10000; i++)
	{
		if (DT[N][i] >= M)
		{
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}

int mymax(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}