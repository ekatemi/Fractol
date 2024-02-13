/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:19:08 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/18 19:37:24 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// const char *s is a null term string, int c is a char to search
// returns a pointer to the first occurance or NULL if it is not found

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return ((void *)0);
}
/*
int	main (void)
{
	const char *str = "";
	int char_to_find = '\0';
	char *res = ft_strchr(str, char_to_find);
	if (res != ((void *)0))
	{
		printf("function returns: %s \n", res);
	}
	else
		printf("Character %c is not found.", char_to_find);
	return (0);
}*/
