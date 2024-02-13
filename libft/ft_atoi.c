/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:58:28 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 23:20:52 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	res = res * sign;
	return (res);
}
/*
int main(void)
{
	printf("Original atoi %d\n", atoi("  768  -2  -777"));
	printf("Original atoi %d\n", atoi(" -   -2"));
	printf("Original atoi %d\n", atoi("  ++  -2"));
	printf("Original atoi %d\n", atoi("    -    2"));
	printf("Original atoi %d\n", atoi("    -ass2"));
	printf("Original atoi %d\n", atoi("    +ass2"));
	printf("My atoi %d\n", ft_atoi("  768  -2  -777"));
	printf("My atoi %d\n", ft_atoi(" -   -2"));
	printf("My atoi %d\n", ft_atoi("  ++  -2"));
	printf("My atoi %d\n", ft_atoi("    -    2"));
	printf("My atoi %d\n", ft_atoi("    -ass2"));
	printf("My atoi %d\n", ft_atoi("    +ass2"));
	return 0;
}*/
