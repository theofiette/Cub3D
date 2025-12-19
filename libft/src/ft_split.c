/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:39:23 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/13 14:07:41 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_c(char s, char c)
{
	return (s == c);
}

static int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (s && *s)
	{
		while (is_c(*s, c) && *s)
			s++;
		if (*s++)
			count++;
		while (!is_c(*s, c) && *s)
			s++;
	}
	return (count);
}

char	**free_split(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

static char	*malloc_word( const char *s, char c)
{
	int		len;
	char	*new_word;
	int		i;

	len = 0;
	while (*s && is_c(*s, c))
		s++;
	while (*s && !is_c(*s, c))
	{
		len++;
		s++;
	}
	new_word = malloc(sizeof(char) * len + 1);
	if (!new_word)
		return (0);
	s -= len;
	i = 0;
	while ((s + i) < (s + len))
		*new_word++ = *(s + i++);
	*new_word = 0;
	return (new_word - len);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**new_tab;
	char	**start;

	nb_words = count_word(s, c);
	new_tab = malloc((nb_words + 1) * sizeof(char *));
	if (!new_tab || nb_words == 0)
		return (ft_free_split(new_tab), NULL);
	start = new_tab;
	while (s && *s)
	{
		while (*s && is_c(*s, c))
			s++;
		if (nb_words--)
		{
			*new_tab = malloc_word(s, c);
			if (!*new_tab)
				return (free_split(start));
			while (*s && !is_c(*s, c))
				s++;
			new_tab++;
		}
	}
	*new_tab = 0;
	return (start);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = "hello!";
// 	char c = ' ';
// 	char **tab;
// 	tab = ft_split(str, c);
// 	int i = 0;
// 	printf("%d",count_word(str, c));
// 	while (i < count_word(str, c) + 1)
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i++]);
// 	}
// 	free(tab);
// 	return (0);
// }