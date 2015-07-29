#include <stdio.h>

int N;	//input N;;;

int input1, input2;

typedef struct color	{
	int saero;
	int garo;
	double saero_;
}	PAPER;
PAPER paper[110];

int LIS[110];

int result;

void quick(PAPER *arr, int n);
void lis(void);

int main(void)
{
	int i, j;

	scanf("%d", &N);	//input N;

	for(i=0; i<N; i++)	{
		scanf("%d %d", &input1, &input2);

		if(input1 >= input2)	{
			paper[i].saero = input1;
			paper[i].garo = input2;
		}
		else	{
			paper[i].saero = input2;
			paper[i].garo = input1;
		}

		paper[i].saero_ = (double)paper[i].saero + ((double)paper[i].garo / ((double)paper[i].saero + 1) );	//paper[i].saero_!!!
		//[0]번에 큰 거, [1]번에 작은게 들어간다.
	}	//for i
	
	quick(paper, N);	//input
	/*
	printf("*****\n");
	for(i=0; i<N; i++)	{
		printf("%d %d\n", paper[i].saero, paper[i].garo);
	}
	*/
	lis();
	/*
	for(i=0; i<N; i++)	{
		printf("%d ", LIS[i]);
	}
	printf("\n");
	*/
	for(i=0; i<N; i++)	{
		if(result < LIS[i])	{
			result = LIS[i];
		}
	}
	printf("%d\n", result);

	return 0;
}

void lis(void)
{
	int i, j;

	for(i=0; i<N; i++)	{
		LIS[i] = 1;
		for(j=0; j<i; j++)	{
				if(paper[j].garo >= paper[i].garo && LIS[i] < LIS[j]+1)	{
					LIS[i] = LIS[j]+1;
				}
		}	//for j
	}	//for i
}	//lis();

void quick(PAPER *arr, int n)
{
	int i, j;
	double mid;
	PAPER temp;

	if(n > 1)
	{
		i = -1; 
		j = n-1;
		mid = arr[n-1].saero_;

		while(1)
		{
			while(arr[++i].saero_ > mid);	//nae rim cha soon
			while(arr[--j].saero_ < mid);	

			if(i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}

		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n-1];
		arr[n-1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr+i+1, n-i-1);

	}	//if (n > 1)
	
}	//quick

/*

7
1 2
8 7
20 10
20 20
15 12
12 14
11 12

*/