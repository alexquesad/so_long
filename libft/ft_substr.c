/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:05:06 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 16:57:51 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a substring from the string `s`. The substring begins
** at index `start` and is of maximum size `len`.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (i < len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
