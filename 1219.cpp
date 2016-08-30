#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define max_n 1002
#define max_k 102
#define max_len 1000000

const int MAX = 999999999;

struct point
{
	int x, y;
};
bool comp(const point &a, const point &b)
{
	if (a.x<b.x) return true; else return false;
}
point p[max_n];
int sol, minx, miny, maxx, maxy, n, k, l, cost, i, j, min_cost, ga, se;
int d[max_n][max_k];
int imax(int a, int b)
{
	if (a>b) return a; else return b;
}
int imin(int a, int b)
{
	if (a>b) return b; else return a;
}
int main(void)
{
	scanf("%d %d", &se, &ga);
	scanf("%d %d", &k, &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &p[i].y, &p[i].x);
	}

	sort(&p[1], &p[n + 1], comp);
	fill(d[0], d[n + 1], MAX);
	for (i = 0; i <= k; i++)
		d[0][i] = 0;
	for (j = 1; j <= k; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (j == 1 && i == 4)
			{
				j = j;
			}
			//get d[i][j]
			minx = p[i].x - 1;
			maxx = p[i].x;
			miny = 0;
			maxy = p[i].y;
			min_cost = MAX;
			for (l = i; l >= 1; l--)
			{
				minx = p[l].x - 1;
				maxy = imax(maxy, p[l].y);
				cost = imax(d[l - 1][j - 1], imax(maxx - minx, maxy - miny));
				min_cost = imin(min_cost, cost);
			}
			d[i][j] = imin(d[i][j - 1], min_cost);
		}
	}
	printf("%d\n", d[n][k]);

	return 0;
}