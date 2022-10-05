/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:07:39 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/03 02:18:45 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list `lst` and applies the function `f` to the content of each
** element. Creates a new list resulting of the successive applications of the
** function `f`. The `del` function is used to delete the content of an element
** if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new_node;
	t_list			*ret_lst;
	t_list			*temp_lst;

	if (!lst)
		return (0);
	ret_lst = ft_lstnew(f(lst->content));
	if (!ret_lst)
		return (0);
	temp_lst = lst->next;
	while (temp_lst)
	{
		new_node = ft_lstnew(f(temp_lst->content));
		if (!new_node)
		{
			ft_lstclear(&ret_lst, del);
			return (0);
		}
		ft_lstadd_back(&ret_lst, new_node);
		temp_lst = temp_lst->next;
	}
	return (ret_lst);
}
