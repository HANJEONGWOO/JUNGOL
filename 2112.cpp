#include <stdio.h>

int N;

int f[40];
int g[40];

int main(void)
{
	scanf("%d", &N);

	f[0] = 1;
	f[1] = 0;
	g[0] = 0;
	g[1] = 1;

	for (int i = 2; i < 40; i++)
	{
		f[i] = f[i - 2] + 2 * g[i - 1];
		g[i] = f[i - 1] + g[i - 2];
	}

	printf("%d\n", f[N]);

	return 0;
}