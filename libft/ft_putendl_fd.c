/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:12:13 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:42:55 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the string ’s’ to the given file descriptor followed by a newline.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
	}
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	char *str = "Katia";
	ft_putendl_fd(str, 1);
	return (0);
}*/
