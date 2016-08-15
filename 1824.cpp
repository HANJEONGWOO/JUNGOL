#include <stdio.h>

int sudoku();
int check(int x, int y, int z);

int map[9][9];
int flag;

int main(void)
{
	//�Է���Ʈ, ����
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//���� Ǯ��, ����

	sudoku();

	//�����Ʈ, ����
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
			if (map[i][j] == 0) { //ä������ ���� ������ ������ ����
								  //���ǿ� �´� �ĺ��� �� �ϳ��� ä��� ���� ���� �� �Ǵ� - �߰��������� ����� ���� ���� ��ų����
				for (int z = 1; z <= 9; z++) {
					if (check(i, j, z) == 1) { //i, j�ڸ��� z�� ��︮���� �Ǵ�.
						map[i][j] = z;			//��︮�� ���� �ִ´�.
						sudoku();

						if (flag == 1) return 0;

						map[i][j] = 0; //������� ����
					}
				}
				return 0; //��� ĭ�� 0~9 �ƹ��͵� ��︮�� ������ ������ �߸��Ǿ����� �ǵ��� ����
			}
		}
	}
	flag = 1; //ä������ ���� ������ ������ ��� ������� ������ ���� �Ѱ��� ä���� ��

	return 0;
}

int check(int x, int y, int z)
{

	//�� �˻�
	for (int j = 0; j < 9; j++) {
		if (map[x][j] == z) {
			return 0;
		}
	}

	//�� �˻�
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == z) {
			return 0;
		}
	}

	//���� �˻�
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