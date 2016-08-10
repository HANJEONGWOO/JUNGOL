#include <stdio.h>

#define MOD 1000000003

int n, k, DT[2][1100][1100];

int f(int a, int b, int can)
{
	if (b == k) return 1;
	if (a >= n - can) return 0;
	if (DT[can][a][b] == -1)
		DT[can][a][b] = (f(a + 2, b + 1, can) + f(a + 1, b, can)) % MOD;

	return DT[can][a][b];
}

int main(void)
{

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1100; j++)
		{
			for (int k = 0; k < 1100; k++)
			{
				DT[i][j][k] = -1;
			}
		}
	}

	scanf("%d %d", &n, &k);

	printf("%d\n", (f(1, 0, 0) + f(2, 1, 1)) % MOD);

	return 0;
}