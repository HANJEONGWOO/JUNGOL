#include <stdio.h>

int N;

char arr[110][110];

int ischecked[110][110];

int result1, result2;

void f1(int y, int x, char color);
int check1(int y, int x, char color);

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ischecked[i][j] == 0) {
				result1++;
				f1(i, j, arr[i][j]);
			}
		}
	}

	//reset
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ischecked[i][j] = 0;
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ischecked[i][j] == 0) {
				result2++;
				f1(i, j, arr[i][j]);
			}
		}
	}

	printf("%d %d\n", result1, result2);

	return 0;
}

void f1(int y, int x, char color)
{
	ischecked[y][x] = 1;

	if (check1(y + 1, x, color))
		f1(y + 1, x, color);
	if (check1(y - 1, x, color))
		f1(y - 1, x, color);
	if (check1(y, x + 1, color))
		f1(y, x + 1, color);
	if (check1(y, x - 1, color))
		f1(y, x - 1, color);
}

int check1(int y, int x, char color)
{
	if (y >= 0 && y < N && x >= 0 && x < N && (ischecked[y][x] == 0) && (color == arr[y][x]))
		return 1;
	else
		return 0;
}