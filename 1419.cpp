#include <stdio.h>

unsigned int num;

unsigned int result;

unsigned char temp;

int main(void)
{
	scanf("%d", &num); //input num;;;

	for (int i = 1; i <= 4; i++)
	{
		temp = num; //������ 8�ڸ��� ����ȴٰ� ������
		result |= temp << (32 - i * 8); //�׷��� result�� 24, 16, 8, 0
		num = num >> 8; //num�� ����Ʈ 8�Ͽ� ����� 8�ڸ��� ������.
	}

	printf("%u\n", result);

	return 0;
}