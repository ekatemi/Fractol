/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:55:09 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:18:50 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Allocates (with malloc(3)) and returns a string representing the integer 
received as an argument. Negative numbers must be handled. -2147483648*/

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	num_digits(int n)
{
	int	num;

	num = 0;
	if (n <= 0)
		num += 1;
	while (n != 0)
	{
		n = n / 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	tmp_n;
	int		size_nbr;

	size_nbr = num_digits(n);
	tmp_n = n;
	if (tmp_n < 0)
		tmp_n *= -1;
	str = malloc(sizeof(char) * (size_nbr + 1));
	if (!str)
		return (NULL);
	str[size_nbr] = '\0';
	size_nbr--;
	while (tmp_n > 0)
	{
		str[size_nbr] = (tmp_n % 10) + '0';
		tmp_n /= 10;
		size_nbr--;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
/*
int main()
{
  int num = -2147483648;
  char *number = ft_itoa(num);
  printf("%s", number);
  free(number);
  return 0;
}*/
