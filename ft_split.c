/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:36:34 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/29 22:36:34 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static inline
char	**ft_deallocate(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(result[j++]);
	free(result);
	return (NULL);
}

static inline
char	*ft_sub(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len - start) + 1);
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < (len - start))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static inline
char	*ft_get_word(const char *str, char c, int word)
{
	static size_t	i = 0;
	static size_t	j = 0;
	char	*result;

	while (str[i] && str[i] == c)
		i++;
	j = i;
	while (str[i])
	{
		if (str[i] == c)
		{
			result = ft_sub(str, j, i);
			if (word == 0)
				i = 0;
			return (result);
		}
		i++;
	}
	result = ft_sub(str, j, i);
	i = 0;
	return (result);
}

static inline
int	ft_count(const char *str, char c)
{
	size_t	num_of_words;
	size_t	i;

	if (!str[0])
		return (0);
	num_of_words = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			num_of_words++;
			while (str[i] && str[i] == c)
				i++;
			continue;
		}
		i++;
	}
	if (str[i - 1] != c)
		num_of_words++;
	return (num_of_words);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int	num_of_words;
	size_t	i;

	if (!str)
		return (NULL);
	num_of_words = ft_count(str, c);
	result = (char **)malloc(sizeof(char *) * (num_of_words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (num_of_words--)
	{
		result[i] = ft_get_word(str, c, num_of_words);
		if (!result[i])
			return (ft_deallocate(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
