/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:17:18 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 21:55:52 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a new element. The variable `content` is initialized
** with the value of the parameter `content`. The variable `next` is
** initialized to NULL. 
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
