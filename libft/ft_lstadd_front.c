/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <aquesada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:00:28 by aquesada          #+#    #+#             */
/*   Updated: 2021/12/02 22:00:00 by aquesada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the element `new` at the beginning of the list. */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = *alst;
	else
		new->next = NULL;
	*alst = new;
}
