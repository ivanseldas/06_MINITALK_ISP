/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:43:54 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/29 20:09:12 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct	s_string
{
	char	c;
	size_t	i;
}	t_string;

char	*ft_itoa(int n);

#endif
