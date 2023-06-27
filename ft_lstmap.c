/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:15:09 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/20 22:15:09 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*cnt;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		cnt = f(lst->content);
		tmp = ft_lstnew(cnt);
		if (tmp == NULL)
		{
			del(cnt);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
