#include <stdio.h>

unsigned int num;

unsigned int result;

unsigned char temp;

int main(void)
{
	scanf("%d", &num); //input num;;;

	for (int i = 1; i <= 4; i++)
	{
		temp = num; //마지막 8자리만 저장된다고 가정함
		result |= temp << (32 - i * 8); //그러면 result에 24, 16, 8, 0
		num = num >> 8; //num을 시프트 8하여 저장된 8자리를 날린다.
	}

	printf("%u\n", result);

	return 0;
}