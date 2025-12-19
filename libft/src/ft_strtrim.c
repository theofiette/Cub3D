/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:55:31 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 12:45:31 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_inset(char c, const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_inset(s1[start], set))
		start++;
	while (end > start && is_inset(s1[end - 1], set))
		end--;
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = 0;
	return (new_str);
}

// int main()
// {
// 	char *str = "  \t \t \n   \n\n\n\t";
// 	char *set = " \n\t";
// 	char *new_str;
// 	new_str = ft_strtrim(str, set);
// 	printf("%s\n",new_str);
// 	return (0);
// }