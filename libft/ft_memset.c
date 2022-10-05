/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:03:37 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 14:07:08 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* writes 'len' bytes of value 'c' (converted to an unsigned char) to
**  the string 'b' */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i++] = c;
	}
	return (b);
}
