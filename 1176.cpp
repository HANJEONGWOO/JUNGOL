#include <stdio.h>

char str[110];
int str_len;

char mbyte[4] = "127";
char mshort[6] = "32767";
char mint[11] = "2147483647";
char mlong[20] = "9223372036854775807";

int mystrlen(char *str);

int main(void)
{
	scanf("%s", &str);

	str_len = mystrlen(str);

	if (str_len < 3)
	{
		printf("byte\n");
		return 0;
	}
	else if (str_len == 3)
	{
		int fail_flag = 0;
		for (int i = 0; i < 3; i++)
		{
			if (str[i] > mbyte[i]) {
				fail_flag = 1;
				break;
			}
		}
		if (fail_flag == 0) {
			printf("byte\n");
			return 0;
		}
		else
		{
			printf("short\n");
			return 0;
		}
	}
	else if (str_len < 5)
	{
		printf("short\n");
		return 0;
	}
	else if (str_len == 5)
	{
		int fail_flag = 0;
		for (int i = 0; i < 5; i++)
		{
			if (str[i] > mshort[i]) {
				fail_flag = 1;
				break;
			}
		}
		if (fail_flag == 0) {
			printf("short\n");
			return 0;
		}
		else {
			printf("int\n");
			return 0;
		}
	}
	else if (str_len < 10)
	{
		printf("int\n");
		return 0;
	}
	else if (str_len == 10)
	{
		int fail_flag = 0;
		for (int i = 0; i < 10; i++)
		{
			if (str[i] > mint[i]) {
				fail_flag = 1;
				break;
			}
		}
		if (fail_flag == 0) {
			printf("int\n");
			return 0;
		}
		else {
			printf("long\n");
			return 0;
		}
	}
	else if (str_len < 19)
	{
		printf("long\n");
		return 0;
	}
	else if (str_len == 19)
	{
		int fail_flag = 0;
		for (int i = 0; i < 19; i++)
		{
			if (str[i] > mlong[i]) {
				fail_flag = 1;
				break;
			}
		}
		if (fail_flag == 0) {
			printf("long\n");
			return 0;
		}
		else {
			printf("BigInteger\n");
			return 0;
		}
	}
	else
		printf("BigInteger\n");

	return 0;
}

int mystrlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);

	return i;
}