/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:39:53 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:29:26 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*allocates sufficient memory for a copy of the string s1, does the copy, and
returns a pointer to it. The pointer may subsequently be used as an argument 
to the function free(3).
If insufficient memory is available, NULL is returned and errno is set to 
ENOMEM.
The strndup() function copies at most n characters from the string s1 always 
NUL terminating the copied string.*/

#include <string.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	size_t			size;
	unsigned int	i;
	char			*copy;

	i = 0;
	size = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char *ptr = "Katia";
	char *res = ft_strdup(ptr);
	if (res == NULL)
		printf("Memory allocation failed");
	else
		printf("%s", res);
	return (0);
}*/
