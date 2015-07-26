#include <stdio.h>

int saero, garo;

char map[60][60];

//yongsa
int queue1[10000][2];
int front1, rear1;
int front1_, rear1_;

//fire
int queue2[10000][2];
int front2, rear2;
int front2_, rear2_;

void move_worrior(int y, int x);
void move_fire(int y, int x);

int end_flag;
int fail_flag;

int result;

int main(void)
{
	int i, j;

	scanf("%d %d", &saero, &garo);

	for(i=0; i<saero; i++)	
		scanf("%s", &map[i]);	//input this

	for(i=0; i<saero; i++)
	{
		for(j=0; j<garo; j++)
		{
			if(map[i][j] == 'S')	{
				queue1[rear1][0] = i;
				queue1[rear1++][1] = j;
			}
			else if(map[i][j] == '*')	{
				queue2[rear2][0] = i;
				queue2[rear2++][1] = j;
			}
		}	//for j
	}	//for i

	front1_ = front1;
	rear1_ = rear1;

	front2_ = front2;
	rear2_ = rear2;

	/*
	//TEST
		printf("============\n");
		for(i=0; i<saero; i++)	{
			for(j=0; j<garo; j++)	{
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
		//
	*/

	while(1)	{
		fail_flag = 0;

		while(front1 < rear1_)	{
			if(map[queue1[front1][0]] [queue1[front1][1]] == 'S')	{
				move_worrior(queue1[front1][0], queue1[front1][1]);	//move worrior this
			}
			//printf("%d %d\n", queue1[front1][0], queue1[front1][1]);
			front1++;
		}

		//TEST
		/*
		printf("============\n");
		for(i=0; i<saero; i++)	{
			for(j=0; j<garo; j++)	{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		*/
		while(front2 < rear2_)	{
			move_fire(queue2[front2][0], queue2[front2][1]);
			//printf("%d %d\n", queue2[front2][0], queue2[front2][1]);
			front2++;
		}

		result++;
		
		if(end_flag == 1)	{
			printf("%d\n", result);
			break;
		}

		//TEST
		/*
		printf("============\n");
		for(i=0; i<saero; i++)	{
			for(j=0; j<garo; j++)	{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		//
		*/
		front1_ = front1;
		rear1_ = rear1;
		front2_ = front2;
		rear2_ = rear2;		//dea ip

		if(front1 == rear1)	{
			printf("impossible\n");
			break;
		}
	}

	return 0;
}

void move_worrior(int y, int x)
{
	int i, j;

	if(y-1 >= 0 && map[y-1][x] == '.')	{
		queue1[rear1][0] = y-1;
		queue1[rear1++][1] = x;
		map[y-1][x] = 'S';
	}
	else if(y-1 >= 0 && map[y-1][x] == 'D')	{
		end_flag = 1;
		//printf("end call1\n");
	}

	if(y+1 < saero && map[y+1][x] == '.')	{
		queue1[rear1][0] = y+1;
		queue1[rear1++][1] = x;
		map[y+1][x] = 'S';
	}
	else if(y+1 < saero && map[y+1][x] == 'D')	{
		end_flag = 1;
		
		//printf("end call2\n");
	}
	
	if(x-1 >= 0 && map[y][x-1] == '.')	{
		queue1[rear1][0] = y;
		queue1[rear1++][1] = x-1;
		map[y][x-1] = 'S';
	}
	else if(x-1 >= 0 && map[y][x-1] == 'D')	{
		end_flag = 1;
		
		//printf("end call3\n");
	}

	if(x+1 < garo && map[y][x+1] == '.')	{
		queue1[rear1][0] = y;
		queue1[rear1++][1] = x+1;
		map[y][x+1] = 'S';
	}
	else if(x+1 < garo && map[y][x+1] == 'D')	{
		end_flag = 1;
		
		//printf("end call4\n");
	}
	//end end end
}

void move_fire(int y, int x)
{
	int i, j;

	if(y-1 >= 0 && (map[y-1][x] == '.' || map[y-1][x] == 'S') )	{
		queue2[rear2][0] = y-1;
		queue2[rear2++][1] = x;
		map[y-1][x] = '*';
	}
	if(y+1 < saero && (map[y+1][x] == '.' || map[y+1][x] == 'S') )	{
		queue2[rear2][0] = y+1;
		queue2[rear2++][1] = x;
		map[y+1][x] = '*';
	}
	
	if(x-1 >= 0 && (map[y][x-1] == '.' || map[y][x-1] == 'S') )	{
		queue2[rear2][0] = y;
		queue2[rear2++][1] = x-1;
		map[y][x-1] = '*';
	}
	if(x+1 < garo && (map[y][x+1] == '.' || map[y][x+1] == 'S') )	{
		queue2[rear2][0] = y;
		queue2[rear2++][1] = x+1;
		map[y][x+1] = '*';
	}
}
/*
3 3
D.*
...
.S.

3 3
D.*
...
..S

3 6
D...*.
.X.X..
....S.

*/