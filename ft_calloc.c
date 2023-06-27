/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:13:44 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/27 22:33:36 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void 	*s;
	size_t	temp;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1,1));
	temp = nmemb * size;
	if (temp / size != nmemb)
		return (NULL);
	s = malloc(temp);
	if (!s)
		return (NULL);
	ft_bzero(s, temp);
	return (s);
}