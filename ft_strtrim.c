/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:17:23 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/20 22:17:23 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(char c, const char *set)
{
	while (*set != '\0')
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*r;
	size_t	ep;

	if (s == NULL || set == NULL)
		return (NULL);
	while (is_char(*s, set) && *s != '\0')
		s++;
	ep = ft_strlen(s);
	while (is_char(s[ep - 1], set) && ep != 0)
		ep--;
	r = (char *)malloc(sizeof(char) * (ep + 1));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s, ep + 1);
	return (r);
}
