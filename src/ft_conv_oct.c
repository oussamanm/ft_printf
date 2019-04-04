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

#include "../includes/ft_printf.h"

/// Conversion func
char     *ft_conv_base(ft_uint64_t value, int base, int b_maj)
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
            if (b_maj == 1)
                r -= 32;
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
int     ft_conv_bin(char *str, int len)
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


char    *ft_conv_bin_s(char *str, int len, int sign) /// To Get MANTISSA
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

char    *ft_get_bmemorld(int len, st_typeld *st_ld) // get Binary of a value LONG DOUBLE
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
char    *ft_get_bmemor(int len, void *value) // get Binary of a value
{
    char                *i_value;
    int                 i;
    int                 j;
    unsigned long long  *f;

    i = len;
    j = 0;
    f = (unsigned long long *)value;
    i_value = ft_strnew(len);
    while(i >= 0)
        i_value[j++] = (1 & (*f >> i--)) ? '1' : '0';
    return (i_value);
}

///********** Opr math

//// Opr ==> Add
void     ft_opradd_h_len(char **nbr1, char **nbr2, int *len, int i_spec_cal) // get len fot str
{
    char    *str1;
    char    *str2;
    int     len1;
    int     len2;

    len1 = ft_strlen(*nbr1);
    len2 = ft_strlen(*nbr2);
    *len = (len1 > len2) ? len1 : len2;
    str1 = ft_strnew_char(*len, '0');
    str2 = ft_strnew_char(*len, '0');
    if (i_spec_cal == 1) /// may should remove all this situa
    {
        ft_memcpy(str1, *nbr1, len1);
        ft_memcpy(str2, *nbr2, len2);
    }
    else
    {
        (len1 == *len) ? ft_strcpy(str1,*nbr1) : ft_strcpy(&str1[*len - len1], *nbr1);
        (len2 == *len) ? ft_strcpy(str2,*nbr2) : ft_strcpy(&str2[*len - len2], *nbr2);
    }
    (*nbr1 != NULL) ? ft_strdel(nbr1) : NULL;
    (*nbr2 != NULL) ? ft_strdel(nbr2) : NULL;
    *nbr1 = str1;
    *nbr2 = str2;
    *len =  (str1[0] == 0 || str2[0] == 0) ? -1 : *len;
}
char    *ft_opr_add(char *nbr1, char *nbr2, int i_free, int i_spec_cal) /// > 25  and //// i_spec_cal == 0  : simple calcule else : without resepecting order
{
    int     len,o_len;
    int     sum;
    int     res;
    char    *str;

    res = 0;    
    ft_opradd_h_len(&nbr1 , &nbr2, &len, i_spec_cal); // get len fot str and correct nbr1 and nbr2
    str = ft_strnew_char(len, '0');
    len--;
    o_len = len;
    while (len >= 0)
    {
        sum = (nbr1[len] - '0') + (nbr2[len] - '0') + res;
        if (sum <= 9)
        {
            str[len--] = sum + '0';
            res = 0;
            continue ;
        }
        sum -= (sum <= 19) ? 10 : 20;
        res = (sum <= 19) ? 1 : 2;
        str[len] = sum + '0';
        if (len == 0 && res != 0)
        {
            ft_memmove(&str[1], &str[0], o_len + 1);
            str[0] = res + '0';
        }
        len--;
    }
    if (i_free == 1 || i_free == 3)
        ft_strdel(&nbr1);
    if (i_free == 2 || i_free == 3)
        ft_strdel(&nbr2);
    if (i_spec_cal == 0)
        ft_escap_str(str);
    return (str);
}

//// Opr ==> Power
char    *ft_opr_pow(char *nbr, char *pow, int i_free)
{
    int     i_pow;
    int     i;
    char    *str;

    i = 0;
    i_pow = ft_atoi(pow);
    if (i_pow == 0)
        return (ft_strnew_char(1,'1'));
    if (ft_all_zero(nbr))
        return (ft_strnew_char(1,'0'));
    str = ft_strnew(i_pow);
    i_pow--;
    ft_strcpy(str, nbr);
    while (i < i_pow)
    {
        str = ft_opr_multi(str, nbr, 1); ////free
        i++;
    }
    if (nbr != NULL && (i_free == 1 || i_free == 3))
        ft_strdel(&nbr);
    if (pow != NULL && (i_free == 2 || i_free == 3))
        ft_strdel(&pow);
    return (str);
}
char    *ft_opr_negapower(char *nbr, char *power, int i_free)
{
    int     i_power;
    int     i_lennbr;
    char    *rtn;

    i_lennbr = ft_strlen(nbr);
    i_power = ft_atoi(power);
    rtn = ft_strnew_char(i_power, '0');
    ft_strcpy(&rtn[i_power - i_lennbr], nbr);
    if (i_free == 1)
        ft_strdel(&nbr);
    return (rtn);
}

//// Opr ==> Multi
char    *ft_oprmul_h_cal(char *nbr, char n, int nbr_zero)
{
    int     i,len;
    int     mul;
    int     res;
    char    *resu;

    i = 0;
    res = 0;
    len = ft_strlen(nbr);
    resu = ft_strnew_char(nbr_zero + len + 1, '0');
    len--;
    while (len >= 0)
    {
        mul = (nbr[len] - '0') * (n - '0') + res;
        res = (mul < 9) ? 0 : (mul / 10);
        resu[len + 1] =  (mul < 9) ? (mul + '0') : ((mul % 10) + '0');
        if (len == 0 && res != 0)
            resu[len] = res + '0';
        len--;
    }
    return (resu);
}

char    *ft_opr_multi(char *nbr1, char *nbr2, int i_free)
{
    char    *rtn;
    char    *resu;
    int     i;
    int     j;

    j = 0;
    i = ft_strlen(nbr2) - 1;
    resu = ft_strnew_char(1, '0');
    if (nbr1 == NULL || nbr2 == NULL || ft_all_zero(nbr1) || ft_all_zero(nbr2))
        i = -1;
    while (i >= 0)
    {
        rtn = ft_oprmul_h_cal(nbr1, nbr2[i], j++);
        resu = ft_opr_add(resu, rtn, 3, 0);
        i--;
    }
    if (i_free == 1 || i_free == 3)
        ft_strdel(&nbr1);
    if (i_free == 2 || i_free == 3)
        ft_strdel(&nbr2);
    return (resu);
}