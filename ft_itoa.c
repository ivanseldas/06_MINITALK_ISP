/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:31:53 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/29 20:07:55 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * It converts an integer to a string.
 * @param n the number to be converted
 * @return A string of characters.
 */

static long int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_char(char *str, unsigned int num, long int len)
{
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	num;
	int				sign;

	sign = 1;
	len = ft_intlen(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		num = n * -1;
		str[0] = '-';
	}
	else
		num = n;
	str = ft_char(str, num, len);
	return (str);
}
