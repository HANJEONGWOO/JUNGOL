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
	if (start == end) //���� ������ ���� �����Ѵ�, ���� �ߺ�ȣ��ȴ�.
		return true;
	else
	{
		for (int i = '1'; i <= '3'; i++)
		{
			arr[start] = i;

			if (!Check(start)) continue; //���� ���� ������ �Ǵ��� üũ�غ���.
			if (FindArray_DFS(start + 1, end)) //���� ���� ���� �����̶��, ���� ����
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
		int cnt = ++idx / 2; //ī��Ʈ�迭�� ������ 2�� �Ͽ� �߾��� �����ش�.
		for (int i = 1; i <= cnt; i++)
		{
			if (strncmp(&arr[idx - i], &arr[idx - i * 2], i) == 0) //�߾��� ���� ���� �������� ���Ͽ� ���ٸ� false �����Ѵ�.
				return false;
		}
	}

	return true;
}
