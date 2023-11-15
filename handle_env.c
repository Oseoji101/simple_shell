#include "main.h"
/**
 * handle_env - =======
 * @env: ======
 */
void handle_env(char **env)
{
	int i = 0;

	for (i = 0; env[i]; i++)
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 1);
	}
}
