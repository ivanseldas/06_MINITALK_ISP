/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:31:09 by ivanisp           #+#    #+#             */
/*   Updated: 2023/02/16 21:01:26 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static void	pass_bit(int pid, char *string)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (i <= ft_strlen(string))
	{
		j = 0;
		while (j < 7)
		{
			bit = (string[i] >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "\nFail\n", 6);
		return (0);
	}
	pass_bit(ft_atoi(argv[1]), argv[2]);
	return (0);
}
