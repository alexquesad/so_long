/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:03:35 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 16:32:07 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Finds the first occurrence of the string `needle` in the string `haystack`
** where no more than `len` characters are searched. 
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_size;
	size_t	n_size;
	size_t	s_size;

	h_size = ft_strlen(haystack);
	n_size = ft_strlen(needle);
	if (n_size == 0)
		return ((char *)haystack);
	else if (n_size > h_size)
		return (NULL);
	if (h_size > len)
		s_size = len;
	else
		s_size = h_size;
	while (n_size <= s_size)
	{
		if (!ft_strncmp(haystack, needle, n_size))
			return ((char *)haystack);
		haystack++;
		s_size--;
	}
	return (NULL);
}
