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

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

double ft_atod(char *nptr)
{
    int sign = 1;
    int has_dec = 0;
    double res = 0.0;  // Change the type to double
    double decimalPlaces = 1.0;

    while (*nptr && ft_isspace(*nptr))
        nptr++;
    
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    
    while (*nptr && ((*nptr >= '0' && *nptr <= '9') || *nptr == '.'))
    {
        if (*nptr == '.')
        {
            has_dec = 1;
            nptr++;
        }

        if (has_dec)
        {
            decimalPlaces /= 10.0;
            res = res + (*nptr - '0') * decimalPlaces;
        }
        else 
            res = res * 10 + (*nptr - '0');

        nptr++;
    }

    res = res * sign;
    return res;
}