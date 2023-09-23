#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void factorize(long long int value);
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 or 1
 */
int main (int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "File not found\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		long long int value = atoll(line);
		factorize(value);
	}

	fclose(file);
	return (0);
}

/**
 * factorize - get the smallest factors of the value
 * @value: value to find its facto
 */
void factorize(long long int value)
{
	long long int i;

	if (value <= 1)
	{
		fprintf(stderr, "not a valid number\n");
	}

	for (i = 1; i <= value / 2; i++)
	{
		if ((i != 1) && (value % i == 0))
		{
			long long int q = value / i;
			printf("%lld=%lld*%lld\n", value, q, i);
			return;
		}
	}

	return;
}
