#include "monty.h"
#include <stdio.h>
#include <string.h>

stack_t *top = NULL;
/**
 * main - monty interpreter.
 * @argc : number of argument.
 * @argv : array of argument.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int i, command_line = 1;
	char line[100], *del = " \n", *str, *command_arg[2];
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		i = 0;
		str = strtok(line, del);
		while (i < 2)
		{
			if (str == NULL)
				str = "None";
			command_arg[i] = str;
			str = strtok(NULL, del);
			i++;
		}
		command_execution(command_arg, command_line);
		command_line++;
	}
	fclose(fp);
	return (0);
}
