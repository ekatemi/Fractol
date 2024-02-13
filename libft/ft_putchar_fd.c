/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:21:28 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:23:06 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Outputs the character ’c’ to the given file descriptor.

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int fd = 1;
	char c = 'K';
	ft_putchar_fd(c, fd);
	return (0);
}*/
