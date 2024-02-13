/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:54:55 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:37:50 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copies up to dstsize - 1 characters from the string src to dst, 
//NUL-terminating the result if dstsize is not 0.

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	while (*src && (i < size - 1))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (srclen);
}
/*
int main() {
    char src[] = "Ekaterina";
    char dst[5];  // Destination buffer
    size_t length = ft_strlcpy(dst, src, 5);
    printf("Copied string: %s\n", dst);
    printf("Length of source string: %zu\n", length);
    return 0;
}*/
