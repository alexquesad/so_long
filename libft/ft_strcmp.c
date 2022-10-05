/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:40:34 by alexa             #+#    #+#             */
/*   Updated: 2022/04/27 13:40:49 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	it;

	it = 0;
	while (s1[it] && s2[it] && (s1[it] == s2[it]))
		it++;
	return ((unsigned char)s1[it] - (unsigned char)s2[it]);
}
