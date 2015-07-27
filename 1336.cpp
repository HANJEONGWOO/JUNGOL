#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime[10000];
int is_check[10000];	//check this arr...

int result;

char start[5], end[5];
char garb[5];

char queue[10000][5];	//input queue;
int front, rear;
int front_, rear_;

int end_flag;

void prime(void);
void func(char *input);

int main(void)
{
	int i, j;
	
	prime();

	scanf("%s %s", &start, &end);	//input this
	
	strcpy(queue[rear++], start);	//copy it
	is_check[atoi(start) ] = 1;	//check this

	while(1)
	{
		front_ = front;
		rear_ = rear;

		while(front < rear_)
		{
			func(queue[front++]);
		}

		if(end_flag == 1)	{
			printf("%d\n", result);
			break;
		}
		if(front == rear)	{	//if it is no queue
			break;
		}
		result++;
	}

	return 0;
}

void func(char *input)
{
	int i, j;
	char input_[5];
	int trans;

	//check it is end
	trans = atoi(input);
	if( strcmp(input, end) == 0 )	{	//if it is same,
		end_flag = 1;
		return;
	}

		
	strcpy(input_, input);	//copy this
	for(i='1'; i<='9'; i++)	{
		input_[0] = i;
		if( is_prime[atoi(input_) ] == 0 && is_check[atoi(input_) ] == 0)	{
			strcpy(queue[rear++], input_);

			//printf("q : %d\n", queue[rear-1]);
			is_check[ atoi(input_) ] = 1;	//check this
		}	//if
	}	//for 0

	strcpy(input_, input);	//copy this
	for(i='0'; i<='9'; i++)	{
		input_[1] = i;
		if( is_prime[atoi(input_) ] == 0 && is_check[atoi(input_) ] == 0)	{
			strcpy(queue[rear++], input_);

			//printf("q : %d\n", queue[rear-1]);
			is_check[ atoi(input_) ] = 1;	//check this
		}	//if
	}	//for 1 

	strcpy(input_, input);	//copy this
	for(i='0'; i<='9'; i++)	{
		input_[2] = i;
		if( is_prime[atoi(input_) ] == 0 && is_check[atoi(input_) ] == 0)	{
			strcpy(queue[rear++], input_);
			//printf("q : %d\n", queue[rear-1]);
			
			is_check[ atoi(input_) ] = 1;	//check this
		}	//if
	}	//for 2

	strcpy(input_, input);	//copy this
	for(i='0'; i<='9'; i++)	{
		input_[3] = i;
		if( is_prime[atoi(input_) ] == 0 && is_check[atoi(input_) ] == 0)	{
			strcpy(queue[rear++], input_);
			//printf("q : %d\n", queue[rear-1]);

			is_check[ atoi(input_) ] = 1;	//check this
		}	//if
	}	//for 3

}

void prime(void)
{
	int i, j;

	for(i=2; i<10000; i++)	{
		if(is_prime[i] == 0)	{
			for(j=i+i; j<10000; j+=i)	{
				is_prime[j] = 1;
			}	//for j	- make sosu
		}	//if
	}	//for i
	
}
// 1033 8179