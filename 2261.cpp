#include <stdio.h>
#include <string.h>

int N, K;

char str[1100][40];
int start, end;

int check[1100];	//is it checked?
char queue[1100][40];	//this is queue
int front, rear;
int front_, rear_;

int result;		//result this

int end_flag;

void search(char *input);

int main(void)
{
	int i, j;

	scanf("%d %d", &N, &K);

	for(i=1; i<=N; i++)	{
		scanf("%s", &str[i]);	//input this
	}
	scanf("%d %d", &start, &end);	//input
	
	strcpy(queue[rear++], str[start]);	//copy it	
	check[start] = 1;

	while(1)
	{
		front_ = front;
		rear_ = rear;

		while(front < rear_)	{
			search(queue[front++]);
		}
		
		if(end_flag == 1)	{
			printf("%d\n", result);
			break;
		}
		else if(front == rear)	{
			printf("-1\n");
			break;
		}//this is ififififif

		result++;	//plus result;;;
	}	//while(1)

	return 0;
}

void search(char *input)	//input is current string;;;
{
	int i, j;
	int len;

	int diff = 0;

	if( strcmp(input, str[end]) == 0)	{
		end_flag = 1;
		return;
	}

	for(i=1; i<=N; i++)	{
		diff = 0;

		if(check[i] == 0)	{
			for(j=0; j<K; j++)	{
				if(input[j] != str[i][j])	{
					diff++;
				}
			}	//for j

			if(diff == 1)	{
				strcpy(queue[rear++], str[i]);

				check[i] = 1;	//set 1 check flag;;;
			}	//insert it

		}	//if(check[i] == 0)
	}	//for i

}	//search

/*

5 3
000
111
010
110
001
1 2

*/