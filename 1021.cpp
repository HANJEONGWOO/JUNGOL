#include <stdio.h>

int tree[110][110];
int result[110];
int is_mid_product[110];

int g_n, g_m;

int v1, v2;

void get_product(int idx, int v)
{
	result[idx] += v; //plus result value;

	for (int i = 1; i <= g_n; i++) {
		if (tree[idx][i]) //recursively call;
		{
			get_product(i, v * tree[idx][i]);
		}
	}
}

int main(void)
{
	scanf("%d %d", &g_n, &g_m);

	for (int i = 0; i < g_m; i++) {
		scanf("%d %d", &v1, &v2);
		is_mid_product[v1] = 1;
		scanf("%d", &tree[v1][v2]);
	}

	get_product(g_n, 1);

	for (int i = 1; i <= g_n; i++) {
		if (is_mid_product[i] == 0) {
			printf("%d %d\n", i, result[i]);
		}
	}

	return 0;
}