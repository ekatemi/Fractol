/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:22:15 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:38:36 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
//The memcpy() function copies n bytes from memory area src to memory area 
//dst. If dst and src overlap, behavior is undefined.  Applications in which 
//dst and src might overlap should use memmove(3) instead.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == 0 && src == 0)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
/*
int	main(void)
{
	char source[] = "Hello world";
	char dest[20];

	//using standart memcpy
	
	memcpy(dest, source, ft_strlen(source) + 1);
	printf("standart memcpy: %s\n", dest);
	
	//using ft_memcpy

	ft_memcpy(dest, source, ft_strlen(source) + 1);
	printf("My ft_ memcpy: %s\n", dest);
	return (0);
}*/
