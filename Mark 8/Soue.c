# include <stdio.h>
#include <conio.h>
# define LEN 1000
void main(void)
{
	char line[LEN];
	int i = 0;
	int c, start;
	int counter = 0;
	int max = 0;
	char *ptr;


	for (i = 0; (i < (LEN - 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++)
	{
		line[i] = c;
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
		{
			counter++;
			if (counter > max)
			{
				max = counter;
				start = i + 1 - max;
			}
		}
		else

			counter = 0;
	}
	line[i] = '\0';                                                     // ����� ������
	puts(line);
	printf("samoe dlinoe slovo:");
	for (i = start; i < start + max; i++)                      // ����� ������ �������� �����
		printf("%c", line[i]);
	for (i = start; ((line[i]) != EOF) && (line[i] != '\0') && ((line[i]) != '\n') && (i < (LEN - 1)); i++)
	{
		ptr = &line[i];
		if (start == 0)
			*ptr++ = line[i + max + 1];
		else
		{
			*ptr-- = line[i + max];
			*ptr = line[i + max];
		}
	}
	printf("\n");
	printf("rezultat:");
	puts(line);
	_getch();
}
