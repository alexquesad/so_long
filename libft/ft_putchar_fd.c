/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:27:22 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 21:38:23 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the character `c` to the given file descriptor. */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
