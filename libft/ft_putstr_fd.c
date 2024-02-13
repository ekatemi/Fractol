/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:50:20 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:22:28 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Outputs the string ’s’ to the given file descriptor.

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(s);
	while (size > 0)
	{
		ft_putchar_fd(*s++, fd);
		size--;
	}
}
/*
int	main(void)
{
	char *str = "Katia";
	ft_putstr_fd(str, 1);
	return (0);
}*/
