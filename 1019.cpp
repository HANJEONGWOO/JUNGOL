#include <stdio.h>
#include <stdlib.h>
#define size 100000
#define k 3


int s[size + 1][4];
int a[size + 1];
int sum[size + 1];

int l, n, j;

int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);

		sum[i] = sum[i - 1] + a[i];
	}

	scanf("%d", &l);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			s[i][j] = s[i - 1][j]; //바로 윗 행의 값으로 대체한다.

			if (i - l >= 0) {
				if (s[i][j] < s[i - l][j - 1] + (sum[i] - sum[i - l]))
					s[i][j] = s[i - l][j - 1] + (sum[i] - sum[i - l]);
			}

		}
	}

	printf("%d\n", s[n][k]);

	return 0;
}