#include <stdio.h>
#include <string.h>

char arr[220];

bool Check(int idx);
bool FindArray_DFS(int start, int end);

int main(void)
{
	int N;

	scanf("%d", &N);

	FindArray_DFS(0, N);

	printf("%s\n", arr);

	return 0;
}

bool FindArray_DFS(int start, int end)
{
	if (start == end) //끝을 만나면 참을 리턴한다, 참이 중복호출된다.
		return true;
	else
	{
		for (int i = '1'; i <= '3'; i++)
		{
			arr[start] = i;

			if (!Check(start)) continue; //먼저 좋은 수열이 되는지 체크해본다.
			if (FindArray_DFS(start + 1, end)) //리턴 값이 좋은 수열이라면, 참을 리턴
				return true;
		}
	}
	return false;
}

bool Check(int idx)
{
	if (idx == 0)
		return true;
	else
	{
		int cnt = ++idx / 2; //카운트배열은 나누기 2를 하여 중앙을 나눠준다.
		for (int i = 1; i <= cnt; i++)
		{
			if (strncmp(&arr[idx - i], &arr[idx - i * 2], i) == 0) //중앙을 나눈 것을 바탕으로 비교하여 같다면 false 리턴한다.
				return false;
		}
	}

	return true;
}
