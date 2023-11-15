#include "main.h"
void process_cmd_file(char **arg, char *p);
/**
 * process_cmd_file - =======
 * @arg: ======
 * @p: =====
 */
void process_cmd_file(char **arg, char *p)
{

	pid_t pid;
	int status;

	(void)p;
	pid =  fork();

	if (pid == 0)
	{
		if (strcmp(arg[0], "ls") == 0)
		{
			execve("/bin/ls", arg, environ);
		}
		else if (strcmp(arg[0], "echo") == 0)
		{
			execve("/bin/echo", arg, environ);
		}
		else
		{
			execve(arg[0], arg, environ);
		}
		write(2, "./hsh: 1: ", 10);
		write(2, arg[0], strlen(arg[0]));
		write(2, ": not found\n", 12);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		int exit_status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status  != 0 && !isatty(STDIN_FILENO))
			{
				exit(exit_status);
			}
		}
	}
}
