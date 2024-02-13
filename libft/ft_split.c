/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:49:50 by emikhayl          #+#    #+#             */
/*   Updated: 2023/09/26 21:25:29 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s == c)
			inside_word = 0;
		else if (inside_word == 0)
		{
			count++;
			inside_word = 1;
		}
		s++;
	}
	return (count);
}

static char	**free_matrix(char **arr_of_words, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		free(arr_of_words[i]);
		i++;
	}
	free(arr_of_words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_of_words;
	int		i;
	size_t	size_word;

	i = 0;
	arr_of_words = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr_of_words)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size_word = 0;
			while (s[size_word] && s[size_word] != c)
				size_word++;
			arr_of_words[i++] = ft_substr(s, 0, size_word);
			if (!arr_of_words[i - 1])
				return (free_matrix(arr_of_words, i - 1));
			s = s + size_word;
		}
	}
	arr_of_words[i] = (NULL);
	return (arr_of_words);
}
/*
int	main()
{
	const char	*str = " Hello darkness my old friend ";
	char		c = ' ';
	char		**arr_of_words;
	int			i;
	arr_of_words = ft_split(str, c);
	if (!arr_of_words)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	i = 0;
	while (arr_of_words[i])
	{
		printf("%s\n", arr_of_words[i]);
		free(arr_of_words[i]);
		i++;
	}
	free(arr_of_words);
	return 0;
}*/
