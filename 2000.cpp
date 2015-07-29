//2000 동전교환

#include <stdio.h>

int N;	//coin num;
int coin[10];	//coin this

int W;	//won
int won[65000];	//dongjun array

int main(void)
{
	int i, j, k;

	scanf("%d", &N);	//N input

	for(i=0; i<N; i++)	
		scanf("%d", &coin[i]);	//input this

	scanf("%d", &W);	//won

	for(i=1; i<=W; i++)	{
		won[i] = 100000;
	}

	for(i=0; i<N; i++)	{
		for(j=coin[i]; j<=W; j++)	{
			if(won[j] > won[j - coin[i] ] + 1)	{
				won[j] = won[j- coin[i] ] + 1;
			}	//if
		}	//for j
		/*
		for(k=0; k<=W; k++)	{
			printf("%d ", won[k]);
		}
		printf("\n");
		*/
	}	//for i
	if(won[W] == 100000)	{
		printf("impossible\n");
	}
	else	{
		printf("%d\n", won[W]);
	}
	return 0;
}
/*

3
1 4 6
8

3
2 4 6
7

3
2 4 6
8
*/