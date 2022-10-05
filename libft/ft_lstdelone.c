/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:52:27 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 22:21:33 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as parameter an element and frees the memory of the element's content
** using the function `del` given as a parameter and free the element.
** The memory of`next` must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
