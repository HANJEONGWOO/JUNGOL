#include <stdio.h>

typedef struct lamp {
	int f_switch;
	int t_switch;

	int idx_val;
	int prev_idx;

	int f_lamp;
	int t_lamp;
} LAMP;

int n;

LAMP l[11000];

int index[11000];

int max, max_idx;

int result_idx[11000]; //넣은 뒤, 정렬시켜야함
int idx_cnt;

void quick(int *arr, int n);

int main(void)
{
	scanf("%d", &n); //input n;;;

	for (int i = 0; i < n; i++)
		scanf("%d", &l[i].t_switch);

	for (int i = 0; i < n; i++)
		scanf("%d", &l[i].t_lamp);

	for (int i = 0; i < n; i++)
	{
		l[i].f_lamp = i; // 가짜 인덱스에는 숫자를 순서대로 대입시킨다.

		index[l[i].t_lamp] = i; //인덱스 변수에 인덱스를 저장하여 바로 쓸 수 있도록 한다.
	}

	for (int i = 0; i < n; i++)
	{
		l[i].f_switch = index[l[i].t_switch]; //인덱스 배열의 인자로 스위치 번호를 따라가면 된다.
	}

	//
	for (int i = 0; i < n; i++)
	{
		l[i].prev_idx = i; //초기 이전 인덱스는 자기 자신이다.

		l[i].idx_val = 1; // 인덱스 값은 당연히 1이 기본값(자기자신)
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (l[j].f_switch < l[i].f_switch && l[j].idx_val + 1 > l[i].idx_val) //스위치가 i가 더 크고, 값은 j가 더 클 때,
			{
				l[i].idx_val = l[j].idx_val + 1; //값 대체

				l[i].prev_idx = j; //j가 이전 인덱스이다.
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		if (l[i].idx_val > max)
		{
			max = l[i].idx_val;
			max_idx = i;
		}
	}


	while (1)
	{
		result_idx[idx_cnt++] = l[max_idx].t_switch;

		if (max_idx == l[max_idx].prev_idx)
			break;
		else
			max_idx = l[max_idx].prev_idx;
	}

	quick(result_idx, idx_cnt);

	printf("%d\n", max);

	for (int i = 0; i < idx_cnt; i++)
		printf("%d ", result_idx[i]);
	printf("\n");

	return 0;
}

void quick(int *arr, int n)
{
	int i, j;
	int mid;
	int temp;

	if (n > 1)
	{
		i = -1;
		j = n - 1;
		mid = arr[n - 1];

		while (1)
		{
			while (arr[++i] < mid);
			while (arr[--j] > mid);

			if (i >= j)
				break;

			//swap two value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		//swap pivot value
		temp = arr[i];
		arr[i] = arr[n - 1];
		arr[n - 1] = temp;

		//re-quick
		quick(arr, i);
		quick(arr + i + 1, n - i - 1);
	}

}