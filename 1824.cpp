#include <stdio.h>

int sudoku();
int check(int x, int y, int z);

int map[9][9];
int flag;

int main(void)
{
	//입력파트, 시작
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//문제 풀이, 시작

	sudoku();

	//출력파트, 시작
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}

int sudoku() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (map[i][j] == 0) { //채워지지 않은 스도쿠 공간을 만남
								  //조건에 맞는 후보들 중 하나를 채우고 무한 진행 후 판단 - 중간점검으로 경우의 수를 단축 시킬수도
				for (int z = 1; z <= 9; z++) {
					if (check(i, j, z) == 1) { //i, j자리에 z가 어울리는지 판단.
						map[i][j] = z;			//어울리는 수를 넣는다.
						sudoku();

						if (flag == 1) return 0;

						map[i][j] = 0; //원래대로 복구
					}
				}
				return 0; //어느 칸에 0~9 아무것도 어울리지 않으면 이전에 잘못되었으니 되돌아 가자
			}
		}
	}
	flag = 1; //채워지지 않은 스도쿠 공간이 없어서 여기까지 왔으면 뭔가 한가지 채워진 것

	return 0;
}

int check(int x, int y, int z)
{

	//행 검사
	for (int j = 0; j < 9; j++) {
		if (map[x][j] == z) {
			return 0;
		}
	}

	//열 검사
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == z) {
			return 0;
		}
	}

	//구간 검사
	int a = (x / 3) * 3, b = (y / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (map[a + i][b + j] == z) {
				return 0;
			}
		}
	}

	return 1;
}