#include <stdio.h>
#include <string.h>

#define MAXN 1000

void recur(int x, int y);

char seq[MAXN];
int table[MAXN][MAXN] = { 0 };
int back[MAXN][MAXN];

int main(void)
{
	int l1, l2, i, j, k, n;

	scanf("%s", seq);

	n = strlen(seq);

	for (l1 = 2; l1 <= n; l1++) {
		for (l2 = l1; l2 <= n; l2++) {
			i = l2 - l1; j = l2; k = i + 1;

			table[i][j] = table[i][k] + table[k][j];
			back[i][j] = k;

			for (k = i + 2; k < j; k++) {
				if (table[i][j] < table[i][k] + table[k][j]) {
					table[i][j] = table[i][k] + table[k][j];
					back[i][j] = k;
				}
			}
			if ((seq[i] == 'a' && seq[j - 1] == 't') || (seq[i] == 'g' && seq[j - 1] == 'c')) {
				if (table[i][j] < table[i + 1][j - 1] + 2) {
					table[i][j] = table[i + 1][j - 1] + 2;
					if (seq[i] == 'a') back[i][j] = -1;
					else back[i][j] = -2;

				}
			}

		}
	}

	printf("%d\n", table[0][n]);

	return 0;
}

