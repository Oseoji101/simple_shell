#include "main.h"
/**
 * checkstatus - =======
 * @num: ======
 * Return: =====
 */
int checkstatus(char *num)
{
	int i = 0;

	for (i = 0; num[i]; i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			return (2);
		}
	}
	return (0);
}
/**
 * exit_shell - =======
 * @cmd: ======
 * @ptr: =====
 */
void exit_shell(char **cmd, char *ptr)
{
	int status = 0;
	int value;

	if (cmd[1] != NULL)
	{
		value = checkstatus(cmd[1]);
		if (value == 2)
		{
			write(2, "./hsh:", 6);
			write(2, " 1: exit: ", 10);
			write(2, "Illegal number: ", 16);
			write(2, cmd[1], strlen(cmd[1]));
			write(2, "\n", 1);
			deletememmory(cmd);
			free(ptr);
			exit(EXIT_FAILURE);
		}
		free(ptr);
		status = atoi(cmd[1]);
		deletememmory(cmd);
		exit(status);
	}
	else
	{
		deletememmory(cmd);
		free(ptr);
		exit(0);
	}
}
