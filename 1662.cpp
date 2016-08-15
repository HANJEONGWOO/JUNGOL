#include <stdio.h>

int N, a[20][20], d1[30];


int f(int n)
{
	if (n >= 2 * N - 1)
		return 0;

	int max = -1, x, y, tmp;
	x = n < N ? 0 : n - (N - 1);
	y = n < N ? n : N - 1;

	while (y >= 0 && x < N)
	{
		if (a[y][x] == 1 && d1[x - y + N] == 0)
		{
			d1[x - y + N] = 1;
			tmp = f(n + 2) + 1;
			d1[x - y + N] = 0;
			if (max < tmp)
				max = tmp;
		}
		x++;
		y--;
	}

	if (max < 0)
		max = f(n + 2);
	return max;
}

int main(void)
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d", f(0) + f(1));

	return 0;
}