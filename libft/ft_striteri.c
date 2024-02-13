/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:52:03 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 21:31:15 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Applies the function ’f’ on each character of the string passed as argument, 
passing its index as first argument. Each character is passed by
address to ’f’ to be modified if necessary.*/

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	print_index_and_char(unsigned int index, char *c)
{
    printf("Index: %u, Char: %c\n", index, *c);
}
int main()
{
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    ft_striteri(str, &print_index_and_char);
    return 0;
}*/
