/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:15:03 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/09 17:26:01 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ends;

	ends = s;
	while (*ends)
	{
		ends++;
	}
	while (ends >= s)
	{
		if (*ends == (char)c || (*ends == '\0' && (char)c == '\0'))
		{
			return ((char *)ends);
		}
		ends--;
	}
	return (NULL);
}
