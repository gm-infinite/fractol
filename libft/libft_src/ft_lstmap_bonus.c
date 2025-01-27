/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:56:09 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tempnode;
	t_list	*newlist;
	void	*content;

	if (!f || !del || !lst)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst -> content);
		tempnode = ft_lstnew(content);
		if (!tempnode)
		{
			ft_lstclear(&newlist, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, tempnode);
		lst = lst -> next;
	}
	return (newlist);
}
