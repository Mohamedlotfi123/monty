#include "monty.h"
stack_t *head = NULL;
/**
 * main - Interpreter for Monty Byte codes files
 * @argc : number of arguments
 * @argv : array of arguments
 *
 * Return: Integer
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char line[1024], *token, *y, *arr[1024];
	int i, line_no = 0, x;
	(void)argc;

	/*if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}*/
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((y = fgets(line, sizeof(line), fp)) != NULL)
	{
		line_no += 1;
		i = 0;
		x = 0;
		token = strtok(y, " $\n");
		while (x < 2 && token != NULL)
		{
			arr[i] = token;
			i++;
			token = strtok(NULL, " $\n");
			x++;
		}
		command(arr, line_no);
	}
	fclose(fp);
	return (0);
}
