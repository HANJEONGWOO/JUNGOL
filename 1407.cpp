#include <stdio.h>

int result = 1;

int fibo[50];

char str[50];

int current;

int num;

int main(void)
{
	fibo[0] = 1;
	fibo[1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	scanf("%s", &str); //input

	current = 1;
	for (int i = 1; str[i] != NULL; i++)
	{
		num = ((str[i - 1] - '0') * 10) + (str[i] - '0');

		if (num <= 34) {
			if (str[i - 1] == '0' && str[i] == '0')
			{
				printf("0\n");
				return 0;
			}
			else if (str[i - 1] == '0')
				continue;
			else if (str[i] == '0')
				current--;
			else
				current++;
		}

		else if (str[i] == '0')
		{
			printf("0\n");
			return 0;
		}
		else
		{
			result *= fibo[current]; //set result;
			current = 1; //set current 1
		}

		//printf("!%d\n", result);
	}
	result *= fibo[current];

	printf("%d\n", result);

	return 0;
}