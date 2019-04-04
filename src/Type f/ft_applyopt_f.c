/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyopt_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:17:11 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:17:14 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

//// ft_apply_option_f : apply all option for type f : Pre & Width & '0' & '-' & '+'
char    *ft_applyopt_f(char *value, st_listopt *st_opt) // Done
{
    char    *n_value;
    char    *resu;
    int     len_v;
    int     index;

    index = 0;
    st_opt->opt_pre = (st_opt->opt_pre == -1) ? 6 : st_opt->opt_pre;
    n_value = ft_applypre_f(value, st_opt->opt_pre, st_opt->opt_flag); /// opt pre
    ft_strdel(&value);
    len_v = ft_strlen(n_value);
    if (st_opt->opt_fwidth > len_v) /// opt Width
    {
        resu = ft_strnew_char(st_opt->opt_fwidth, ' ');
        if (ft_check_char(st_opt->opt_flag, '0') == 1) /// Flag 0
            ft_bchar(resu, st_opt->opt_fwidth, '0');
        if (ft_check_char(st_opt->opt_flag, '-') != 1) /// Flag -
            index = st_opt->opt_fwidth - len_v;
    }
    else
        resu = ft_strnew_char(len_v, ' ');
    if (ft_check_char(st_opt->opt_flag, '+') == 1 || n_value[0] == '-') /// Flag +
        ft_appyflagp_f(resu, n_value, &index, st_opt);
    ft_memcpy(&resu[index], n_value, len_v);
    /// free n_value
    (n_value != NULL) ? ft_strdel(&n_value) : NULL;
    return (resu);
}

//// ft_correct_precision : cut n_value and add 1 if necessary 
char    *ft_correct_pre(char *value, int index) // Done
{
    int     index_p;
    int     rest;

    index--;
    rest = 1;
    index_p = 0;
    if (value[index + 1] != '\0' && value[index + 1] >= '5')
    {
        while(rest != 0)
        {
            index = (value[index] == '.') ? index - 1 : index;
            rest = (value[index] < '9') ? 0 : 1;
            value[index] = (value[index] < '9') ? value[index] + 1 : '0';
            if (index == 0 && rest != 0)
                value = ft_strjoir("1" , value, 2);
            index--;
        }
    }
    return (value);
}

//// ft_applyprecision_f : apply precision for type f and 
char    *ft_applypre_f(char *value, int opt_pre, char *opt_flag) // Done
{
    int     index;
    char    *n_value;
    int     i_sign;
    char    c;

    index = 0;
    i_sign = 0;
    c = 0;
    if ((index = ft_find_char(value, '.')) != -1)
        index += (opt_pre == 0) ? ((ft_check_char(opt_flag, '#') == 1) ? 1 : 0) : (opt_pre + 1);
    else
        index = (int)ft_strlen(value);
    if (ft_check_char(opt_flag, '+') == 1 && value[0] != '-' && (c = '+') != 0)
        i_sign = 1;
    else if (ft_check_char(opt_flag, ' ') == 1 && value[0] != '-')
    {
        c = ' ';
        i_sign = 1;
    }
    n_value = ft_strnew_char(index + i_sign, '0');
    n_value[0] = (c != 0) ? c : 0;
    if (opt_pre < (int )ft_strlen(value))
        value = ft_correct_pre(value, index);
    ft_memcpy(&n_value[i_sign], value, index);
    return (n_value);
}

void    ft_appyflagp_f(char *resu, char *value, int *indx, st_listopt *st_opt) // Done
{
    if (st_opt->opt_fwidth > (int)ft_strlen(value))
    {
        if (ft_check_char(st_opt->opt_flag, '0') == 1)
        {
            resu[0] = (value[0] == '-') ? '-' : '+';
            if (value[0] == '-')
                ft_rmchar(value, '-');
            else if (value[0] == '+')
                ft_rmchar(value, '+');
            (*indx)++;
        }
    }
}