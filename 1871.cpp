#include <stdio.h>

#define MAX 200

int line[MAX];
int LIS[MAX];
int maxValue;
int n;	//배열 길이

//LIS(Longest Increase Subsequence) : 최장증가수열
void lis(void)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		LIS[i] = 1;
		for(j=0; j<i; j++)
		{
			if(line[j] < line[i] && LIS[j]+1 > LIS[i])
				LIS[i] = LIS[j]+1;
		}
	}
}

void get_max()
{
	int i, j;
	maxValue = LIS[0];

	for(i=0; i<n; i++)
	{
		if(maxValue < LIS[i])
			maxValue = LIS[i];
	}
}

int main(void)
{
	int i, j;

	scanf("%d", &n);	//input
	
	for(i=0; i<n; i++)
		scanf("%d", &line[i]);	//input

	lis();
	/*
	for(i=0; i<n; i++)	
		printf("%d ", LIS[i]);
	printf("\n");
	*/
	get_max();

	printf("%d", n-maxValue);
}
/*
7
3 7 5 2 6 1 4
*/