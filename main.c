#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void factorize(char *token);
int main (int argc, char *argv[])
{
        FILE *file;
        char line[MAX_LINE_LENGTH];

        if (argc != 2)
        {
                fprintf(stderr, "Usage: factors <file>");
                exit(EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");

        if (!file)
        {
                fprintf(stderr, "File not found");
                exit(EXIT_FAILURE);
        }

	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		char *token = strtok(line, " \t\r\n");
		factorize(token);
	}
	
	return (0);
}

void factorize(char *token)
{
	int  value;
	int half;
	int i;

	if (!token)
	{
		fprintf(stderr, "Error");
	}

	value = atoll(token);	
	half = value / 2;

	for (i = 2; i <= half; i++)
	{
		if (value % i == 0)
		{
			int q = value / i;
			printf("%d=%d*%d\n", value, q, i);
			return;
		}
	}
	
	return;
}
