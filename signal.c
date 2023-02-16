#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	sigint_handler(int signum)
{
	printf("Received SIGINT. Exiting...\n");
	exit (0);
}

int	main()
{
	while (1)
	{
		signal(SIGINT, sigint_handler);
		pause();
	}
	return (0);
}
