/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:14:08 by ivanisp           #+#    #+#             */
/*   Updated: 2023/02/16 20:22:29 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "minitalk.h"

t_string	*g_var;

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
	write (1, "\n", 1);
}

void	man_signal(int bit)
{
	if (bit == 0)
		g_var->c = g_var->c & (~(1 << g_var->i));
	else
		g_var->c = g_var->c | (1 << g_var->i);
	g_var->i++;
	if (g_var->i == 7)
	{
		write (1, &(g_var->c), 1);
		g_var->i = 0;
		g_var->c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	char	*pid_char;

	write(1, "Say hi to Ivan's server\nPID: ", 29);
	pid = getpid();
	pid_char = ft_itoa(pid);
	if (!pid_char)
	{
		write (1, "Error to get pid\n", 17);
		return (0);
	}
	ft_putstr(pid_char);
	while (1)
	{
		signal(SIGUSR1, man_signal);
		signal(SIGUSR2, man_signal);
		pause();
	}
	return (0);
}
