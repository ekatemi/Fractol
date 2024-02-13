/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:43:08 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:44:25 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int main()
{
    char str[] = "12fgrfglgm,trhgrt";
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    ft_bzero(str, len - 1);
    int i = 0;
    while (i < len)
    {
        printf("Str[%d] = %c\n", i, str[i]);
        i++;
    }
    return 0;
}*/
