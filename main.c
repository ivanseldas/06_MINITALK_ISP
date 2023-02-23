#include <unistd.h>

int	main(void)
{
	char	chr;

	chr = 49;
	write(1, &chr, 1);
       return (0);
}       
