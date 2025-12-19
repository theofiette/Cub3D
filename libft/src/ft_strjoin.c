/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:29:08 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/30 13:30:01 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_calloc((s1_len + s2_len + 1), 1);
	if (!new_str)
		return (0);
	ft_strlcat(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s2_len + s1_len + 1);
	return (new_str);
}

// #include <stdio.h>
// int	main()
// {
// 	char *s1 = "Hello ";
// 	char *s2 = "World";
// 	char *new_str;
// 	new_str = ft_strjoin(s1, s2);
// 	printf("%s",new_str);
// 	free(new_str);
// }