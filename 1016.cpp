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
	cnt[3] += cnt[2]; //위치 정해줌

					  //1부분 검사
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
					break; //바꾸고 나간다.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[2]; j < cnt[3]; j++)
				{
					if (in[j] == 1)
					{
						swap(&in[i], &in[j]);
						break; //바꾸고 나간다.
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
					break; //바꾸고 나간다.
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

	//2부분 검사
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
					break; //바꾸고 나간다.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[2]; j < cnt[3]; j++)
				{
					if (in[j] == 2)
					{
						swap(&in[i], &in[j]);
						break; //바꾸고 나간다.
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
					break; //바꾸고 나간다.
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

	//3부분 검사
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
					break; //바꾸고 나간다.
				}
			}
			if (swap_flag == 0)
			{
				for (int j = cnt[1]; j < cnt[2]; j++)
				{
					if (in[j] == 1)
					{
						swap(&in[i], &in[j]);
						break; //바꾸고 나간다.
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
					break; //바꾸고 나간다.
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

	incorrect++; //더한다
}