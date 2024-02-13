/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:02:25 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/15 21:20:41 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	return ((c <= '9' && c >= '0') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
}
/*
int main (void)
{
	char c;

	c = '$';
	if (ft_isalnum(c) != 0)
		printf("is alfanumeric");
	else
		printf("other");
	return (0);
}*/
