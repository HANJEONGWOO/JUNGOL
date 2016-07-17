#include <stdio.h>


int g_weight[1100];
int g_value[1100];

int N, W;

int DT[1100][1100];

int main(void)
{
	scanf("%d %d", &N, &W);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &g_weight[i], &g_value[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (g_weight[i] <= j && DT[i - 1][j] < DT[i - 1][j - g_weight[i]] + g_value[i])
				DT[i][j] = DT[i - 1][j - g_weight[i]] + g_value[i];
			else
				DT[i][j] = DT[i - 1][j];
		}
	}

	/*
	for (int i = 1; i <= N; i++)
	{
	for (int j = 1; j <= W; j++)
	{
	printf("%d ", DT[i][j]);
	}
	printf("\n");
	}
	*/

	printf("%d\n", DT[N][W]);

	return 0;
}
