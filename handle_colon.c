#include "main.h"
void  handle_colon(char *ptr);
/**
 * handle_colon - =======
 * @ptr: ====
 */
void  handle_colon(char *ptr)
{
	char **colon;
	int i = 0;
	char *arg[5000] = {NULL};
	int k = 0;
	char *tok = NULL;

	/*ls  -l ; ls -a*/
	/*colon 0 as ls -l*/
	/*colon 1 as ls -a*/

	colon = malloc(sizeof(char *) * 5000);
	tok = strtok(ptr, "&|;\n");
	while (tok != NULL)
	{
		if (tok[0] == '#')
			break;
		colon[i] = malloc(sizeof(char) * strlen(tok) + 1);
		strcpy(colon[i], tok);
		tok = strtok(NULL, "&|;\n");
		i++;
	}
	colon[i] = NULL;
	i = 0;

	while (colon[i])
	{
		tok = strtok(colon[i], " \t\r\n");
		while (tok != NULL)
		{
			if (tok[0] == '#')
				break;
			arg[k]  = tok;
			tok = strtok(NULL, " \t\r\n");
			k++;
		}
		arg[k] = NULL;
		k = 0;
		if (arg[0] != NULL)
			process_cmd2(arg, ptr);
		i++;
	}
	deletememmory(colon);
}
