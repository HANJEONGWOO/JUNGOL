#include <stdio.h>

#define COM 50	//�ִ� 20���
#define MAX_INVEST 1000	//�ִ� 300����

int dynamic[COM][MAX_INVEST];
int invest[COM][MAX_INVEST];
//com��° ȸ�翡 ������ �ݾ�

int in[MAX_INVEST][COM];

int c;	//company
int m;	//money

int garb;	//garbage;

void print_result(int money, int com);

int main(void)
{
	int i, j, k;

	scanf("%d %d", &m, &c);

	for(i=1; i<=m; i++)	{
		scanf("%d", &garb);
		for(j=1; j<=c; j++)	{
			scanf("%d", &in[i][j]);
		}
	}

	for(i=0; i<=c; i++)
		dynamic[0][i] = 0;
	for(i=0; i<=m; i++)
		dynamic[i][0] = 0;

	for(i=1; i<=c; i++)	//i�� ���� ��� ��ȣ
	{
		for(j=1; j<=m; j++)	//j�� ���� ����� ������ �ݾ�
		{
			for(k=0; k<=j; k++)	
			{
				if(dynamic[j][i] < dynamic[k][i-1] + in[j-k][i])	{
					dynamic[j][i] = dynamic[k][i-1] + in[j-k][i];
					invest[j][i] = j-k;
				}	//if
			}	//for k
		}	//for j
	}	//for i

	printf("%d\n", dynamic[m][c]);

	print_result(m, c);


	return 0;
}

void print_result(int money, int com)	{

	if(com == 1)
		printf("%d ", money);
	else	{
		print_result(money - invest[money][com], com-1);
		printf("%d ", money);
	}
}
/*
4 2
1 5 1
2 6 5
3 7 9
4 10 15
*/