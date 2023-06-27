/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:15:22 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/20 22:15:22 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp_s;
	unsigned char		tmp_c;

	tmp_s = (unsigned const char *)s;
	tmp_c = (unsigned char)c;
	while (n--)
		if (*tmp_s++ == tmp_c)
			return ((void *)(tmp_s - 1));
	return (NULL);
}
