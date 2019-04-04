#include "../../includes/ft_printf.h"

static	unsigned long long int	ft_strleni_u(unsigned long long int nb)
{
	long long int resu;

	resu = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		resu++;
	}
	return (resu);
}

char					*ft_itoa_u(unsigned long long int n)
{
	unsigned long long int	lennbr;
	char			*str;
	lennbr = ft_strleni_u(n);
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_strnew(lennbr + 1);
	str[lennbr--] = '\0';
	while (n != 0)
	{
		str[lennbr] = (n % 10) + '0';
		n = n / 10;
		lennbr--;
	}
	return (str);
}

static	int	ft_isnbr_u(char s)
{
	return (s >= 48 && s <= 57);
}

long long	int	ft_atoi_u(const char *str, int len)
{
	int i;
	long long int r;

	i = 0;
	r = 0;
	while (i < len && str[i] != '\0')
	{
		if (ft_isnbr_u(str[i]))
			r = r * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (r);
}
