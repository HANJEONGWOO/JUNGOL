#include <stdio.h>

int map[110][110];

int saero, garo;
int h_saero, h_garo, j_saero, j_garo;

int queue[11000][2];	//saero, garo 
int front, rear;
int front_, rear_;

int end_flag;
int result =1;

void search(int h_saero, int h_garo);

int main(void)
{
	int i, j;

	scanf("%d %d", &saero, &garo);
	scanf("%d %d %d %d", &h_saero, &h_garo, &j_saero, &j_garo);

	queue[rear][0] = h_saero;
	queue[rear][1] = h_garo;
	
	map[queue[rear][0] ][queue[rear][1] ] = result;
	rear++;
	result++;

	while(1)
	{
		front_ = front;
		rear_ = rear;
	
		while(front < rear_)	{
			search(queue[front][0], queue[front][1]);
			front++;
		}


		if(end_flag == 1)	{
			printf("%d\n", map[j_saero][j_garo]-1);
			break;
		}

		result++;
	}

	return 0;
}

void search(int h_saero, int h_garo)
{
	if(h_saero == j_saero && h_garo == j_garo)	{
		end_flag = 1;
		return;
	}

	if(h_saero-2 > 0 && h_garo+1 <= garo && map[h_saero-2][h_garo+1] == 0)	{
		map[h_saero-2][h_garo+1] = result;

		queue[rear][0] = h_saero-2;
		queue[rear][1] = h_garo+1;
		rear++;
	}
	if(h_saero-1 > 0 && h_garo+2 <= garo && map[h_saero-1][h_garo+2] == 0)	{
		map[h_saero-1][h_garo+2] = result;

		queue[rear][0] = h_saero-1;
		queue[rear][1] = h_garo+2;
		rear++;
	}	//1

	if(h_saero+1 <= saero && h_garo+2 <= garo && map[h_saero+1][h_garo+2] == 0)	{
		map[h_saero+1][h_garo+2] = result;

		queue[rear][0] = h_saero+1;
		queue[rear][1] = h_garo+2;
		rear++;
	}
	if(h_saero+2 <= saero && h_garo+1 <= garo && map[h_saero+2][h_garo+1] == 0)	{
		map[h_saero+2][h_garo+1] = result;

		queue[rear][0] = h_saero+2;
		queue[rear][1] = h_garo+1;
		rear++;
	}	//2

	if(h_saero+2 <= saero && h_garo-1 > 0 && map[h_saero+2][h_garo-1] == 0)	{
		map[h_saero+2][h_garo-1] = result;

		queue[rear][0] = h_saero+2;
		queue[rear][1] = h_garo-1;
		rear++;
	}
	if(h_saero+1 <= saero && h_garo-2 > 0 && map[h_saero+1][h_garo-2] == 0)	{
		map[h_saero+1][h_garo-2] = result;

		queue[rear][0] = h_saero+1;
		queue[rear][1] = h_garo-2;
		rear++;
	}	//3

	if(h_saero-1 > 0 && h_garo-2 > 0 && map[h_saero-1][h_garo-2] == 0)	{
		map[h_saero-1][h_garo-2] = result;

		queue[rear][0] = h_saero-1;
		queue[rear][1] = h_garo-2;
		rear++;
	}
	if(h_saero-2 > 0 && h_garo-1 > 0 && map[h_saero-2][h_garo-1] == 0)	{
		map[h_saero-2][h_garo-1] = result;

		queue[rear][0] = h_saero-2;
		queue[rear][1] = h_garo-1;
		rear++;
	}	//4

}