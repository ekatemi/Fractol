/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:39:53 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/23 18:18:24 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle
			&& ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
int main(void) {
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Bar Baz";
    char *ptr;
    ptr = ft_strnstr(largestring, smallstring, 50);
    if (ptr != NULL) {
        printf("Result is: %s\n", ptr);
    } else {
        printf("Substring not found.\n");
    }
	return  0;	
}*/
