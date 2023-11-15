#include "main.h"
void handlefile(char *filename);
/**
 * handlefile - =======
 * @filename: ======
 */
void handlefile(char *filename)
{
	int nbytes = 0;
	char  buffer[10000];
	int  fd;
	int i, j = 0;
	int k = 0;
	char *tok = NULL;
	char *arg[10000] = {NULL};
	char line[10000] = {'\0'};

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "./hsh: 0: Can't open ", strlen("./hsh: 0: Can't open "));
		write(2, filename, strlen(filename));
		write(2, "\n", 2);
		exit(127);
	}
	while ((nbytes = read(fd, buffer, 10000)) > 0)
	{
		for (i = 0; i < nbytes; i++)
		{

			if (buffer[i] == '\n')
			{
				line[j] = '\0';
				tok = strtok(line, " \t\n\r");
				while (tok != NULL)
				{
					arg[k] = tok;
					tok = strtok(NULL,  " \t\n\r");
					k++;
				}
				arg[k] = NULL;
				k = 0;
				if (arg[0] != NULL)
					process_cmd_file(arg, NULL);
				strcpy(line, "\0");
				j = 0;
			}
			else
			{
				line[j] = buffer[i];
				j++;
			}
		}
	}
	exit(0);
}
