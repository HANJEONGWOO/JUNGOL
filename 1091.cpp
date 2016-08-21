//C6H5OH

#include <stdio.h>

#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01



char str[200];

int str_len;

int mystrlen(char *str);

double result;
double s_result;
double gop;

int main(void)
{
	scanf("%s", &str); //input

	str_len = mystrlen(str);

	for (int i = 0; i < str_len; i++)
	{
		if (str[i] == 'C') {
			if (gop == 0)
				result += s_result;
			else
				result += s_result * gop;
			gop = 0;

			s_result = C;
		}
		else if (str[i] == 'H') {
			if (gop == 0)
				result += s_result;
			else
				result += s_result * gop;
			gop = 0;

			s_result = H;
		}
		else if (str[i] == 'O') {
			if (gop == 0)
				result += s_result;
			else
				result += s_result * gop;
			gop = 0;

			s_result = O;
		}
		else if (str[i] == 'N') {
			if (gop == 0)
				result += s_result;
			else
				result += s_result * gop;
			gop = 0;

			s_result = N;
		}
		else
			gop = (gop * 10) + (str[i] - '0');

	}

	if (gop == 0)
		result += s_result;
	else
		result += s_result * gop;
	gop = 0;

	printf("%.3lf\n", result);

	return 0;
}

int mystrlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);

	return i;
}
