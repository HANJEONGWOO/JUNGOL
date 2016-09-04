#include <stdio.h>

int map[110][110];
int M, N;

int r_y, r_x;

int result;

int check(int y, int x);
void dfs(int pos_y, int pos_x, int cur, int dir);

int main(void)
{
	result = 987654321;

	scanf("%d %d", &M, &N);

	scanf("%d %d", &r_y, &r_x);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0, 0, -1);

	printf("%d\n", result - 1);

	return 0;
}

void dfs(int pos_y, int pos_x, int cur, int dir)
{
	//1 : east, 2 : west, 3 : south, 4 : north

	//set pos y, x to 2
	map[pos_y][pos_x] = 2;

	if (pos_y == r_y && pos_x == r_x)
	{
		if (cur < result)
			result = cur;
	}
	else if (cur < result - 1)
	{
		if (check(pos_y, pos_x + 1))
		{
			if (dir != 1)
				dfs(pos_y, pos_x + 1, cur + 1, 1);
			else
				dfs(pos_y, pos_x + 1, cur, 1);
		}
		if (check(pos_y, pos_x - 1))
		{
			if (dir != 2)
				dfs(pos_y, pos_x - 1, cur + 1, 2);
			else
				dfs(pos_y, pos_x - 1, cur, 2);
		}
		if (check(pos_y + 1, pos_x))
		{
			if (dir != 3)
				dfs(pos_y + 1, pos_x, cur + 1, 3);
			else
				dfs(pos_y + 1, pos_x, cur, 3);
		}
		if (check(pos_y - 1, pos_x))
		{
			if (dir != 4)
				dfs(pos_y - 1, pos_x, cur + 1, 4);
			else
				dfs(pos_y - 1, pos_x, cur, 4);
		}
	}

	map[pos_y][pos_x] = 1; //reset map
}

int check(int y, int x)
{
	if (y >= 0 && y < M && x >= 0 && x < N && map[y][x] == 1) //in the map, and blank map
		return 1; //true
	else
		return 0; //false
}