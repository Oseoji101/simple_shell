#include "main.h"
/**
 * deletememmory - =========
 * @arg: ========
 */
void deletememmory(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		free(arg[i]);
		i++;
	}

	free(arg);


}
