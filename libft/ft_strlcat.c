/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:56:44 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 15:07:18 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Appends the NUL-terminated string src to the end of dst. 
** It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result.
** It returns the initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	d_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	d_len = dst_len;
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (dst_len < dstsize - 1 && src[i])
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (d_len + src_len);
}
