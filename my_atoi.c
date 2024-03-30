#include "monty.h"
/**
 * my_atoi - convert string into integer.
 * @s : string to be converted.
 *
 * Return: the number or 1 if fail.
 */
int my_atoi(char *s)
{
	int i = 0, num, sign = 1, result = 0;

	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = s[i] - 48;
			result = result * 10 + num;
		}
		else
			return (1);
	}
	return (result * sign);
}
