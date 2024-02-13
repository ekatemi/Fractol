/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:49:58 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:36:13 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*appends string src to the end of dst. It will append at most 
 dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless 
 dstsize is 0 or the original dst string was longer than dstsize (in practice 
 this should not happen as it means that either dstsize is incorrect or
 that dst is not a proper string). */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	res;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize <= dstlen)
		res = srclen + dstsize;
	else
		res = srclen + dstlen;
	if (dstsize == 0)
		return (res);
	while (src[i] && dstlen < dstsize - 1)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (res);
}
/*
int main(void)
{

	char src[] = "how are you?";
	char dst[30] = "Hello world"; 11

	size_t length = ft_strlcat(dst, src, 40);
	printf("Result is %s\nLength is %zu characters\n", dst, length);
}*/
