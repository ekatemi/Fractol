/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:46:48 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/24 19:05:48 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//The memmove() function copies len bytes from string src to string dst.  The
//two strings may overlap; the copy is always done in a non-destructive man-
//ner.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*u_dest;
	const unsigned char	*u_src;
	unsigned char		*dest_lastidx;
	const unsigned char	*src_lastidx;

	u_dest = dest;
	u_src = src;
	dest_lastidx = u_dest + (n - 1);
	src_lastidx = u_src + (n - 1);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		while (n-- > 0)
			*u_dest++ = *u_src++;
	}
	else
	{
		while (n--)
			*dest_lastidx-- = *src_lastidx--;
	}
	return (dest);
}
/*
int main() {
    char str[] = "Hello, World!";
    char *src = str;
    char *dest = str + 5;  // Overlapping memory
    printf("Original string: %s\n", str);
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    size_t n = strlen(src);
    ft_memmove(dest, src, n);
    printf("After memmove:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    return 0;
}*/
