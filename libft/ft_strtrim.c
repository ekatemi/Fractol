/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:23:09 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/24 21:48:19 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//s1 string to trim, set of char to trim. Return copy of  trimmed str or NULL
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	size_t			end;
	unsigned int	s1_len;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = s1_len;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
int main(void)
{
	char str[] = " hello ";
	char set[] = " ";  // Characters to trim
	char *trimmed = ft_strtrim(str, set);

	if (trimmed != NULL)
	{
		printf("Original string: %s\n", str);
		printf("Trimmed string: %s\n", trimmed);
		free(trimmed);  // Free allocated memory
    } 
	else 
	{
		printf("Memory allocation failed.\n");
    }   
   	return 0;
}*/
