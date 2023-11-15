#include "main.h"
int main(int argc, char **argv);
/**
 * main - entrypoint
 * @argc: arg count
 * @argv: argv vector
 * Return: 0 on sucess
 */
int main(int argc, char **argv)
{

	size_t  bufsize = 0;
	char *ptr = NULL;
	int bytes = 0;
	char *tok = NULL;
	int i = 0;
	char **cmd;
	int isinteractive = isatty(STDIN_FILENO);

	(void)argc;
	(void)argv;

	if (argc >= 2)
		handlefile(argv[1]);
	while (1)
	{
		if (isinteractive == 1)
		{
			write(1, "# ", 2);
		}
		bytes = getline(&ptr, &bufsize, stdin);
		if (bytes == -1)
		{
			break;
		}
		if (strchr(ptr, ';') != NULL)
		{
			handle_colon(ptr);
			continue;
		}
		cmd = malloc(sizeof(char *) * 10000);
		tok = strtok(ptr, " \n\t\r");
		while (tok != NULL)
		{
			if (tok[0] == '#')
			{
				break;
			}


			cmd[i] = malloc(sizeof(char) * strlen(tok) + 1);
			strcpy(cmd[i], tok);
			tok = strtok(NULL, " \n\t\r");
			i++;
		}
		cmd[i] = NULL;
		i = 0;
		if (cmd[0] == NULL)
		{
			deletememmory(cmd);
			continue;
		}
		if (strcmp(cmd[0], "exit") == 0)
		{
			exit_shell(cmd, ptr);
			/*deletememmory(cmd);*/
			break;
		}
		if (strcmp(cmd[0], "env") == 0)
		{
			deletememmory(cmd);
			handle_env(environ);
			continue;
		}
		process_cmd(cmd, ptr);
		if (isinteractive == 0)
			continue;
	}
	free(ptr);
	return (0);
}
