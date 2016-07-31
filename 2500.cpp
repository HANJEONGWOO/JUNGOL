#include <stdio.h>

#define MAX_N 220
#define MAX_Col 22
#define INF 2100000000

int n, c, col[MAX_N];
int d[MAX_N + 1][MAX_N][MAX_Col + 1];

void input()
{
	scanf("%d %d", &n, &c);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &col[i]);
	}

}

void process()
{
	int l, i, j, k, cp, val, min, ans = INF;

	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= c; j++)
			d[1][i][j] = 1;
		d[1][i][col[i]] = 0;
	}
	for (l = 2; l <= n; l++) {
		for (i = 0; i < n - l + 1; i++) {
			min = INF;
			for (cp = 1; cp <= c; cp++) {
				d[l][i][cp] = INF;
				for (k = 1; k < l; k++) {
					j = i + k;
					val = d[k][i][cp] + d[l - k][j][cp];
					if (val < d[l][i][cp]) d[l][i][cp] = val;
				}
				if (d[l][i][cp] < min)
					min = d[l][i][cp];
			}
			for (cp = 1; cp <= c; cp++)
			{
				if (d[l][i][cp] > min)
					d[l][i][cp] = min + 1;
				if (l == n && d[l][i][cp] < ans)
					ans = d[l][i][cp];
			}
		}
	}
	if (n == 1)
		ans = 0;

	printf("%d\n", ans);

}

int main(void)
{
	input();
	process();

	return 0;
}