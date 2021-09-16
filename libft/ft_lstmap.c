/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:19:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/07/31 10:04:15 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;

	mapped = NULL;
	if (lst)
	{
		mapped = (t_list *)malloc(sizeof(t_list));
		if (mapped)
		{
			mapped->content = f(lst->content);
			mapped->next = ft_lstmap(lst->next, (*f), (*del));
		}
	}
	return (mapped);
}
