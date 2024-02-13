/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:14:49 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 22:26:59 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*contiguously allocates enough space for count objects that are size bytes of
memory each and returns a pointer to the allocated memory. The allocated 
memory is filled with bytes of value zero.*/

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(count * size);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (ptr)
		ft_bzero (ptr, count * size);
	return (ptr);
}
/*
int main(void)
{
    size_t count = 5;
    size_t size = 8;
	size_t i = 0;
    int *str = (int *)ft_calloc(count, size);

    //check if str exists
	if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Allocated memory for %zu elements of size %zu.\n", count, size);

    // Print the allocated array
    printf("Array elements:\n");
    
	while (i++ < count)
    {
        printf("%d\n ", str[i]);
    }

    // Free allocated memory
    free(str);

    return 0;
}*/
