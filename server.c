/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:48:51 by ivanisp           #+#    #+#             */
/*   Updated: 2023/02/23 02:13:38 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "minitalk.h"
#include <stdio.h>

int	count;
char	chr;

void	ft_traduce_bit(int bit)
{
	char	c;

	if (!chr)
		chr = 0;
	if (!count)
		count = 8;
	count--;
//	num[count] = i + '0';
//	printf("count es: %i\n", count);
	if (bit == 12)
		chr |= (1 << count);
	if (count == 0)
	{

		write(1, &chr, 1);
		chr = 0;
		count = 8;
	}
}

void	ft_putchar(int	c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int number)
{
	if (number < 9)
	{
		ft_putchar(number + '0');
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putchar(number % 10  + '0');
	}
}

int	main(void)
{
	int	pid;

	write(1, "IVAN's Server is Ready\n", 23);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
//	printf("%i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_traduce_bit);
		signal(SIGUSR2, ft_traduce_bit);
		pause();
	}
	return (0);
} 
