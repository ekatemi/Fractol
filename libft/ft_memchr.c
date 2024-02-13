/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:38:03 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:41:15 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locates the first occurrence of c (converted to an unsigned char) in string s.

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr_s;
	char		ch;

	ptr_s = (const char *)s;
	ch = (char)c;
	while (n > 0)
	{
		if (*ptr_s == ch)
			return ((void *)ptr_s);
		n--;
		ptr_s++;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "Hello how are you";
    char *pos = ft_memchr(str, 'e', 9);
    if (pos == NULL)
        printf("Not found\n");
    else
        printf("pos = %c\n", *pos);
    return 0;
}*/
