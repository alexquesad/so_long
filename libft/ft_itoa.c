/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:56:49 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 13:38:00 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates and returns a string representing the integer received as an
 * argument. */

static void	get_string(char *str, int n, size_t size)
{
	str[size] = '\0';
	if (n >= 0)
	{
		while (size--)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		while (--size)
		{
			str[size] = (n % 10) * -1 + '0';
			n /= 10;
		}
		str[size] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		temp;
	char	*res;
	size_t	size;

	if (n >= 0)
		size = 1;
	else
		size = 2;
	temp = n / 10;
	while (temp)
	{
		size++;
		temp /= 10;
	}
	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	get_string(res, n, size);
	return (res);
}
