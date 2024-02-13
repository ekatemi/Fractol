/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:53:20 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 21:52:44 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
/*s  Applies the function ’f’ to each character of the string ’s’, and passing
 its index as first argument to create a new string (with malloc(3)) resulting
from successive applications of ’f’.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len_s + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char add_one(unsigned int index, char c)
{
    return c + (char)index;
}

int main()
{
    char input[] = "hello";

    printf("Input string: %s\n", input);

    char *result = ft_strmapi(input, add_one);

    if (result)
    {
        printf("Mapped string: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
