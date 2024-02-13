/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:57:42 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/15 22:41:25 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//size_t it is unsigned integer and it is used to represent
//sizes of arrays, memory allocations
//const used here to ensure that the function doesnt alterate the array
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
/*
int	main (void)
{
	const char *str = "Hello";
	size_t length = ft_strlen(str);
// z is size_t and u is unsigned
	printf("Length of the string is: %zu\n", length);
	return (0);
}*/
