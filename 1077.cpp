#include <stdio.h>

int N, W, W_;

typedef struct treasure	{
	int weight;
	int value;
	double per_value;
} TREASURE;
TREASURE treasure[11000];

void quick(TREASURE *arr, int n);

int result;	//result value;;;

int main(void)
{
	int i, j;	

	scanf("%d %d", &N, &W);	//input this
	W_ = W;	//dae ip;;;

	for(i=0; i<N; i++)	{
		scanf("%d %d", &treasure[i].weight, &treasure[i].value);
		
		treasure[i].per_value = (double)((double)treasure[i].value / (double) treasure[i].weight);
	}	//for i

	quick(treasure, N);
	
	for(i=0; i<N; i++)	{
		while(W_ >= treasure[i].weight)	{
			result += treasure[i].value;	//plus value+++;
			W_ -= treasure[i].weight;		//minus weight---;
		}
	}

	printf("%d\n", result);

	return 0;
}

void quick(TREASURE *arr, int n)
{
	int i, j;
	double mid;
	TREASURE temp;

	if(n > 1)
	{
		i = -1;
		j = n-1;
		mid = arr[n-1].per_value;

		while(1)
		{
			while(arr[++i].per_value > mid);	//nae rim cha
			while(arr[--j].per_value < mid);	//nae rim cha

			if(i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}	//while(1)

		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n-1];
		arr[n-1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr+i+1, n-i-1);

	}	//if(n > 1)

}
