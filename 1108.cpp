#include <stdio.h>
#include <limits.h>

int N;
int graph[550][550];
int a, b;
int max;

double result;

int main(void)
{
	scanf("%d", &N); //input N
	for (int i = 0; i <= 500; i++)
	{
		for (int j = 0; j <= 500; j++)
		{
			graph[i][j] = 987654321;
			if (i == j)
				graph[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b); //input a, b;

		graph[a][b] = 1;


		if (a > max)
			max = a;
		if (b > max)
			max = b;
	} //for i

	for (int k = 1; k <= max; k++)
	{
		for (int i = 1; i <= max; i++)
		{
			for (int j = 1; j <= max; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j]; //°ª ´ëÃ¼
			}
		}
	}

	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= max; j++)
		{
			if (graph[i][j] != 987654321)
				result += (double)graph[i][j];
		}
	}

	result /= (max * (max - 1));

	printf("%.3lf\n", result);

	return 0;
}
