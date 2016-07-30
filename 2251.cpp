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

int result_idx[11000]; //���� ��, ���Ľ��Ѿ���
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
		l[i].f_lamp = i; // ��¥ �ε������� ���ڸ� ������� ���Խ�Ų��.

		index[l[i].t_lamp] = i; //�ε��� ������ �ε����� �����Ͽ� �ٷ� �� �� �ֵ��� �Ѵ�.
	}

	for (int i = 0; i < n; i++)
	{
		l[i].f_switch = index[l[i].t_switch]; //�ε��� �迭�� ���ڷ� ����ġ ��ȣ�� ���󰡸� �ȴ�.
	}

	//
	for (int i = 0; i < n; i++)
	{
		l[i].prev_idx = i; //�ʱ� ���� �ε����� �ڱ� �ڽ��̴�.

		l[i].idx_val = 1; // �ε��� ���� �翬�� 1�� �⺻��(�ڱ��ڽ�)
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (l[j].f_switch < l[i].f_switch && l[j].idx_val + 1 > l[i].idx_val) //����ġ�� i�� �� ũ��, ���� j�� �� Ŭ ��,
			{
				l[i].idx_val = l[j].idx_val + 1; //�� ��ü

				l[i].prev_idx = j; //j�� ���� �ε����̴�.
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