#include <stdio.h>

int saero, garo;
char arr[110][110];
char garb;

int result;

int ay[4] = { 1, 1, 0, -1 };
int ax[4] = { 0, 1, 1, 1 };

void check(int y, int x);
int isvaild(int y, int x);

int main(void)
{
	scanf("%d %d", &saero, &garo);

	for (int i = 0; i < saero; i++)
	{
		scanf("%s", &arr[i]);
	}

	int onetime = 0;
	for (int i = 0; i < saero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			if (arr[i][j] == '.') {
				check(i, j);
				onetime = 1;
			}
		}
	}
	if (onetime == 0)
		check(0, 0);

	printf("%d\n", result);

	return 0;
}

void check(int y, int x)
{
	int cur = 0;
	arr[y][x] = 'o'; //set

	for (int i = 0; i < saero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			if (arr[i][j] == 'o') {
				for (int k = 0; k < 4; k++)
				{
					if (arr[i + ay[k]][j + ax[k]] == 'o' && isvaild(i + ay[k], j + ax[k]))
						cur++;
				} //for k
			} //if
		}
	}

	if (result < cur)
		result = cur;

	arr[y][x] = '.'; //reset
}

int isvaild(int y, int x)
{
	if (y >= 0 && y < saero && x >= 0 && x < garo)
		return 1;
	else
		return 0;
}