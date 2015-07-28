#include <stdio.h>

int saero, garo;

char map[60][60];	//mapping;;

int calc_map[60][60];	//calculate 

int biggest;

int queue[2500][2];	//queue this;;;
int front, rear;
int front_, rear_;
int result;

void search(int pos_y, int pos_x);

int garb;

int main(void)
{
	int i, j, k, l;

	scanf("%d %d", &saero, &garo);

	for(i=0; i<saero; i++)	{
		scanf("%s", &map[i]);	//input this
	}	//input;;


	for(i=0; i<saero; i++)	{
		for(j=0; j<garo; j++)	{
			if(map[i][j] == 'L')	{

				//INIT
				for(k=0; k<saero; k++)	{
					for(l=0; l<garo; l++)	{
						calc_map[k][l] = 0;	//init code
					}	//l
				}	//k

				front = rear = 0;
				front_ = rear_ = 0;
				result = 1;
				
				calc_map[i][j] = result;	//init is one;;;
				queue[rear][0] = i;
				queue[rear][1] = j;
				rear++;

				while(1)
				{
					front_ = front;
					rear_ = rear;
					
					result++;
					while(front < rear_)	{
						search(queue[front][0], queue[front][1]);
						front++;	//front plus this
					}
					
					if(front == rear)	{
						break;
					}	//searching all this

				}	//while(1)

				/*
				//TEST
				printf("====================\n");
				for(k=0; k<saero; k++)	{
					for(l=0; l<garo; l++)	{
						printf("%d ", calc_map[k][l]);
					}
					printf("\n");
				}	//for k;
				scanf("%d", &garb);
				*/

				for(k=0; k<saero; k++)	{
					for(l=0; l<garo; l++)	{
						if(calc_map[k][l] > biggest)	{
							biggest = calc_map[k][l];
						}	//ififif
					}	//l
				}	//k

			}	//map[i][j] == 'L'!!! 



		}	//for j
	}	//for i

	printf("%d\n", biggest-1);
	

	return 0;
}

void search(int pos_y, int pos_x)
{
	if(pos_y-1 >=0 && map[pos_y-1][pos_x] == 'L' && calc_map[pos_y-1][pos_x] == 0)	{
		calc_map[pos_y-1][pos_x] = result;

		queue[rear][0] = pos_y-1;
		queue[rear][1] = pos_x;
		rear++;
	}	//if

	if(pos_y+1 <saero && map[pos_y+1][pos_x] == 'L' && calc_map[pos_y+1][pos_x] == 0)	{
		calc_map[pos_y+1][pos_x] = result;

		queue[rear][0] = pos_y+1;
		queue[rear][1] = pos_x;
		rear++;
	}	//if

	if(pos_x-1 >= 0 && map[pos_y][pos_x-1] == 'L' && calc_map[pos_y][pos_x-1] == 0)	{
		calc_map[pos_y][pos_x-1] = result;

		queue[rear][0] = pos_y;
		queue[rear][1] = pos_x-1;
		rear++;
	}	//if

	if(pos_x+1 < garo && map[pos_y][pos_x+1] == 'L' && calc_map[pos_y][pos_x+1] == 0)	{
		calc_map[pos_y][pos_x+1] = result;

		queue[rear][0] = pos_y;
		queue[rear][1] = pos_x+1;
		rear++;
	}	//if

}