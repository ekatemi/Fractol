/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:50 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/15 23:04:14 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - ('a' - 'A');
	}
	return (c);
}
/*
int main(void)
{
	int letter;

	letter = '3';
	printf("converted: %c\n", ft_toupper(letter));
	return (0);	
}*/
