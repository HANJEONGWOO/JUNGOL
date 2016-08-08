#include <stdio.h>
#include <stdlib.h>

int b[4];
int k1[6];
int k2[6];
int table[550][550];


void read_dat()
{
	for (int i = 1; i <= 3; i++)
	{
		scanf("%d", &b[i]);
	}

	for (int i = 1; i <= 5; i++)
	{
		scanf("%d %d", &k1[i], &k2[i]);
	}
}

void process()
{
	int i, j, k;

	for (i = 0; i <= 500; i++)
	{
		for (j = 0; j <= 500; j++)
		{
			table[i][j] = 0;
			for (k = 1; k <= 3; k++)
			{
				if (i - b[k] >= 0 && table[i - b[k]][j] == 0)
					table[i][j] = 1;
				if (j - b[k] >= 0 && table[i][j - b[k]] == 0)
					table[i][j] = 1;
			}
		}
	}
}

int main(void)
{
	read_dat();

	process();
	for (int i = 1; i <= 5; i++)
		printf("%c\n", (table[k1[i]][k2[i]] == 1) ? 'A' : 'B');

	return 0;
}