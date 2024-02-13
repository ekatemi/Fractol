/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:38:10 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/18 19:53:01 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char *str1 = "Hello!";
	const char *str2 = "Hola!";

	if (ft_strncmp(str1, str2, 1) == 0)
	{
		printf("Equal");
	}
	else 
		printf("Not equal");

	return (0);
}*/
