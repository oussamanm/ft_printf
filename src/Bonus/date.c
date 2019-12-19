/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:14:36 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/12 06:08:50 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

int			ft_checkchar_frm(char c)
{
	if (c != 'd' && c != 'm' && c != 'M' && c != 'y' &&
			c != 'h' && c != 's' && c != ' ' && c != '-')
		return (0);
	return (1);
}

int			ft_get_frm(char **resu, char *format)
{
	if (!ft_strncmp(format, "dd", 2))
		*resu = ft_strjoir(*resu, "1", 1);
	else if (!ft_strncmp(format, "MM", 2))
		*resu = ft_strjoir(*resu, "2", 1);
	else if (!ft_strncmp(format, "yy", 2))
		*resu = ft_strjoir(*resu, "3", 1);
	else if (!ft_strncmp(format, "hh", 2))
		*resu = ft_strjoir(*resu, "4", 1);
	else if (!ft_strncmp(format, "mm", 2))
		*resu = ft_strjoir(*resu, "5", 1);
	else if (!ft_strncmp(format, "ss", 2))
		*resu = ft_strjoir(*resu, "6", 1);
	else
		return (1);
	return (2);
}

char		*ft_check_frm(char *str)
{
	char	*format;
	int		i;
	char	*resu;

	i = 0;
	str++;
	while (str[i] != '\0' && str[i] != '}')
		i++;
	if (str[i] != '}' || i == 0 || (format = ft_strsub(str, 0, i)) == NULL)
		return (NULL);
	i = 0;
	resu = ft_strnew(1);
	while (format[i] != '\0')
	{
		if (!ft_checkchar_frm(format[i]))
		{
			ft_strdel(&format);
			ft_strdel(&resu);
			return (NULL);
		}
		i += ft_get_frm(&resu, &format[i]);
	}
	ft_strdel(&format);
	return (resu);
}

int			ft_print_res(char c, struct tm *mytime)
{
	int rtn;

	rtn = 0;
	if (c == '1')
		rtn = ft_printf("%.2d", mytime->tm_mday);
	else if (c == '2')
		rtn = ft_printf("%.2d", mytime->tm_mon + 1);
	else if (c == '3')
		rtn = ft_printf("%d", mytime->tm_year);
	else if (c == '4')
		rtn = ft_printf("%.2d", mytime->tm_hour + 1);
	else if (c == '5')
		rtn = ft_printf("%.2d", mytime->tm_min);
	else if (c == '6')
		rtn = ft_printf("%.2d", mytime->tm_sec + 1);
	return (rtn);
}

int			ft_type_k(char *str)
{
	int			rtn;
	char		*format;
	time_t		stime;
	struct tm	*mt;

	time(&stime);
	mt = gmtime(&stime);
	rtn = 0;
	format = (str[1] && str[1] == '{') ? ft_check_frm(&str[1]) : NULL;
	mt->tm_year += 1900;
	if (format == NULL)
		ft_printf("%.2d-%.2d-%d", ++(mt->tm_mday), ++(mt->tm_mon), mt->tm_year);
	if (format == NULL)
		return (10);
	str = format;
	while (*format != '\0' && ft_isdigit(*format))
	{
		if (TO_INT(*format) > 3 && *(format - 1) && TO_INT(*(format - 1)) < 4)
			rtn += ft_putstrr(" ", 0);
		else
			rtn += (rtn != 0) ? ft_putstrr("-", 0) : 0;
		rtn += ft_print_res(*(format++), mt);
	}
	ft_strdel(&str);
	return (rtn);
}
