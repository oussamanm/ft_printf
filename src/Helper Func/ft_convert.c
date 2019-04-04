/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 22:15:04 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/06 22:15:05 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/// Conversion func
char     *ft_conv_base(ft_uint64_t value, int base, int b_maj) /// Done
{
    ft_uint64_t     d;
    int    r;
    char buff[21];
    int     i;

    ft_bzero(buff, 21);
    d = 1;
    i = 0;
    while (value != 0)
    {
        r = value % base;
        value /= base;
        if (r >= 10 && r < 16)
        {
            r += 87;
            r -= (b_maj == 1) ? 32 : 0;
            buff[i++] = r;
        }
        else
            buff[i++] = r + '0';
        d = d * 10;
    }
    buff[0] = (i == 0) ? '0' : buff[0];
    i = (i == 0) ? 1 : i;
    return (ft_strrev(buff, i, 1));
}

//// ft_convert_to_bin : Convert to Binary (used to convert expon)
int     ft_conv_bin(char *str, int len) /// Done
{
    int     rtn;
    int     i;

    i = 0;
    rtn = 0;
    len--;
    while (len >= 0)
    {
        if (str[i++] == '1')
            rtn += ft_power(2, (len));
        len--;
    }
    return rtn;
}

//// ft_conv_bin_s : Convert to Binary (use : To Get MANTISSA)
char    *ft_conv_bin_s(char *str, int len, int sign) /// Done
{
    char    *rtn;
    int     i;

    i = 0;
    len--;
    rtn = ft_strnew_char(1,'1');
    if (sign == 2)
        str++;
    while (i <= len)
    {
        if (str[i] == '1')
            rtn = ft_opr_add(ft_opr_multi(rtn , "10", 1), ft_opr_pow("5", ft_itoa(i + 1), 2), 3, 0); /// freee
        else
            rtn = ft_opr_multi(rtn , "10", 1);
        i++;
    }
    return rtn;
}

//// ft_get_bin_memor_ld : Get Binary from memory of a long double
char    *ft_get_bmemorld(int len, st_typeld *st_ld) /// Done
{
    char                *i_value;
    int                 i;
    int                 j;

    j = 0;
    i_value = ft_strnew(len);
    i = 0;
    while(i >= 0)
        i_value[j++] = (1 & ((st_ld->s) >> i--)) ? '1' : '0';
    i = 14;
    while(i >= 0)
        i_value[j++] = (1 & ((st_ld->e) >> i--)) ? '1' : '0';
    i = 63;
    while(i >= 0)
        i_value[j++] = (1 & ((st_ld->fra) >> i--)) ? '1' : '0';
    return (i_value);
}

//// ft_get_bin_memor : Get Binary from memory
char    *ft_get_bmemor(int len, void *value) //// Done
{
    char                *i_value;
    int                 i;
    int                 j;
    unsigned long long  *f;

    i = len;
    j = 0;
    f = (unsigned long long *)value;
    i_value = ft_strnew(len);
    while (i >= 0)
        i_value[j++] = (1 & (*f >> i--)) ? '1' : '0';
    return (i_value);
}
