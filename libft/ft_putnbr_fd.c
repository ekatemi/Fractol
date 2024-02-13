/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:55:11 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:20:20 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Outputs the integer ’n’ to the given file descriptor.*/
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	digit = '0';
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == -2147483648)
	{
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		ft_putchar_fd(digit, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		digit = (n % 10) + '0';
		ft_putchar_fd(digit, fd);
	}
}
/*
int main()
{
    ft_putnbr_fd(-12, 1);
    return 0;
}*/
