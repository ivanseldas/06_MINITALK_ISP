#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	*ascii_array;

	len = strlen(argv[1]);
	ascii_array = (int *)malloc(sizeof(int) * len);
	if (!ascii_array)
		return (0);
	i = 0;
	while (i <= len)
	{
		ascii_array[i] = argv[1][i];
		printf("'%d' ", ascii_array[i]);
		i++;
	}
	printf("\n");
	free(ascii_array);
	return (0);
}