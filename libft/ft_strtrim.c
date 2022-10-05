/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:47:56 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 21:11:58 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a copy of `s1` with the characters specified in `set`
** removed from the beginning and the end of the string. 
*/

#include "libft.h"

static int	ft_in_charset(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_in_charset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_in_charset(s1[end - 1], set))
		end--;
	new_str = (char *)malloc(end - start + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
