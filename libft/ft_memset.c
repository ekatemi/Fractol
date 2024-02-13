/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:53:21 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:40:09 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//writes len bytes of value c (converted to an unsigned char) to the string b.

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = c;
	return (b);
}
/*
int main(void)
{
    char buffer[10];
    memset(buffer, 'c', 10);
    int i = 0;
    while (i < 10)
    {
        printf("%c", buffer[i]);
        i++;
    }
    printf("\n");
    char str[10];
    ft_memset(str, 'c', 10);
    int j = 0;
    while (j < 10)
    {
        printf("%c", str[j]);
        j++;
    }
    return 0;
}*/
