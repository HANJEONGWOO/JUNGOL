#include <stdio.h>

int N;

int in[1100];
int ori[1100];

int cnt[4];

int incorrect;

void swap(int *a, int *b); //swap value
int swap_flag;

int main(void)
{
	scanf("%d", &N); //input N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]); //input in

		if (in[i] == 1)
			cnt[1]++;
		else if (in[i] == 2)
			cnt[2]++;
		else
			cnt[3]++;
	}

	cnt[2] += cnt[1];
	cnt[3] += cnt[2]; //��ġ ������

					  //1�κ� �˻�
	for (int i = 0; i < cnt[1]; i++)
	{
		if (in[i] == 2)
		{
			swap_flag = 0;
			for (int j = cnt[1]; j < cnt[2]; j++)
			{
				if (in[j] == 1)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[2]; j < cnt[3]; j++)
				{
					if (in[j] == 1)
					{
						swap(&in[i], &in[j]);
						break; //�ٲٰ� ������.
					}
				}
			} //if swap_flag == 0

		} //if(in[i] == 3)
		else if (in[i] == 3)
		{
			swap_flag = 0;
			for (int j = cnt[2]; j < cnt[3]; j++)
			{
				if (in[j] == 1)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[1]; j < cnt[2]; j++)
				{
					if (in[j] == 1)
					{
						swap(&in[i], &in[j]);
						break;
					}
				}
			}
		} //else if(in[i] == 3)
	}

	//2�κ� �˻�
	for (int i = cnt[1]; i < cnt[2]; i++)
	{
		if (in[i] == 1)
		{
			swap_flag = 0;
			for (int j = 0; j < cnt[1]; j++)
			{
				if (in[j] == 2)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[2]; j < cnt[3]; j++)
				{
					if (in[j] == 2)
					{
						swap(&in[i], &in[j]);
						break; //�ٲٰ� ������.
					}
				}
			} //if swap_flag == 0

		} //if(in[i] == 3)
		else if (in[i] == 3)
		{
			swap_flag = 0;
			for (int j = cnt[2]; j < cnt[3]; j++)
			{
				if (in[j] == 2)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = 0; j < cnt[1]; j++)
				{
					if (in[j] == 2)
					{
						swap(&in[i], &in[j]);
						break;
					}
				}
			}
		} //else if(in[i] == 3)
	}

	//3�κ� �˻�
	for (int i = cnt[2]; i < cnt[3]; i++)
	{
		if (in[i] == 1)
		{
			swap_flag = 0;
			for (int j = 0; j < cnt[1]; j++)
			{
				if (in[j] == 1)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[1]; j < cnt[2]; j++)
				{
					if (in[j] == 1)
					{
						swap(&in[i], &in[j]);
						break; //�ٲٰ� ������.
					}
				}
			} //if swap_flag == 0

		} //if(in[i] == 1)
		else if (in[i] == 2)
		{
			swap_flag = 0;
			for (int j = cnt[1]; j < cnt[2]; j++)
			{
				if (in[j] == 3)
				{
					swap(&in[i], &in[j]);
					swap_flag = 1;
					break; //�ٲٰ� ������.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = 0; j < cnt[1]; j++)
				{
					if (in[j] == 3)
					{
						swap(&in[i], &in[j]);
						break;
					}
				}
			}
		} //else if(in[i] == 3)
	}

	printf("%d\n", incorrect);

	return 0;
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp; //swap value

	incorrect++; //���Ѵ�
}