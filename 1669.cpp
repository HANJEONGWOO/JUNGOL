#include <stdio.h>

typedef struct sosage	{
	int length;
	int width;
} SOSAGE;

SOSAGE sosage[5050];
SOSAGE prev_sosage;
int selected[5050];	//	not : 0 , select : 1

int N, N_;	//N_ is minus variable
int result;

void quick(SOSAGE *arr, int n);


int main(void)
{
	int i, j;

	scanf("%d", &N);	//input N;;;;
	N_ = N;	//dae ip

	for(i=0; i<N; i++)
		scanf("%d %d", &sosage[i].length, &sosage[i].width);

	quick(sosage, N);	//quick

	while(1)
	{
		if(N_ <= 0)	{
			printf("%d\n", result);
			return 0;
		}

		for(i=0; i<N; i++)	{
			if(selected[i] == 0)	{
				prev_sosage = sosage[i];	//init sosage;;;;
				selected[i] = 1;	//selected[i] is 1
				N_--;	//adsf
				break;
			}
		}	

		for(j=i+1; j<N; j++)	{
			if(sosage[j].width >= prev_sosage.width && selected[j] == 0)	{
				selected[j] = 1;	//selected;;
				prev_sosage = sosage[j];
				N_--;	//asdf
			}
		}

		result++;	//plus result;;;
	}


	return 0;
}


void quick(SOSAGE *arr, int n)
{
	int i, j;
	int mid;
	SOSAGE temp;

	if(n > 1)
	{
		i = -1;
		j = n-1;
		mid = arr[n-1].length;

		while(1)
		{
			while(arr[++i].length < mid);
			while(arr[--j].length > mid);

			if(i >= j)
				break;
			
			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}	//while

		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n-1];
		arr[n-1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr+i, n-i-1);

	}	//if

}	//quick