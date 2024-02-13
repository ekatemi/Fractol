/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:06:39 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/15 20:17:42 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
int	main(void)
{
	char	test_char;

	test_char = 48;
	if (ft_isalpha(test_char) != 0)
	{
		printf("Is alpha");
	}
	else
		printf("Nope");
	return (0);
}*/
