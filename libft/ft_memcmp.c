/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:04 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:43:57 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares byte string s1 against byte string s2.  Both strings are assumed to
//be n bytes long.

#include <stdio.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u1 = (const unsigned char *)s1;
	const unsigned char	*u2 = (const unsigned char *)s2;

	while (n > 0)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		u1++;
		u2++;
		n--;
	}
	return (0);
}
/*
int main(void)
{
    const char str1[] = "AAAaa";
    const char str2[] = "aaa";
    int res = ft_memcmp(str1, str2, 3);
    if (res == 0)
    {
      printf("Equal");
    }
    else if (res > 0)
      printf("S1 bigger");
    else
      printf("S2 bigger");
    return 0;
}*/
