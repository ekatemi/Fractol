#include "fractol.h"
// add libft!!!!!
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
        return ;
	
	while (*s)
	{
		write(fd, s++, 1);
	}
}