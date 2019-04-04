/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:13:48 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:13:51 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

///// ft_type_d : main function for type d,i
int     ft_type_d(st_listopt *st_opt, va_list *ap)
{
    long long int   i_value;
    char            *resu;
    char            *value;

    resu = NULL;
    value = NULL;
    i_value = va_arg(*ap, long long int);
    st_opt->c = 'd';
    ////// Length modifier
    value = ft_apply_lenmod_d(i_value, st_opt->opt_len);
    if (ft_atoi(value) == 0 && st_opt->opt_pre == 0 && st_opt->opt_fwidth == -1) //// case of 0
    {
        if (value != NULL)
            free(value);
        if (ft_check_char(st_opt->opt_flag, '+') == 1)
            return (ft_putstrr("+", 0));
        if (ft_check_char(st_opt->opt_flag, ' ') == 1)
            return (ft_putstrr(" ", 0));
        return 0;
    }
    ft_correct_flagx(st_opt, st_opt->opt_flag, 'd');
    resu = ft_applywith_d(resu, value, st_opt);
    resu = ft_applyopt_d(resu, value, st_opt);
    /// free value and resu;
    if (value != NULL)
        free(value);
    return (ft_putstrr(resu, 1));
}

///// ft_applyoption_d : apply option for d => pre / flag 
char    *ft_applyopt_d(char *resu, char *value, st_listopt *st_opt) /// > 25 + 2
{
    char    *n_value;
    int     len_v;
    int     index;

    index = 0;
    len_v = ft_strlen(value);
    /// Cas Pre and Without ==> create n_value and fill it with value
    n_value = value;
    if (st_opt->opt_pre != -1)
    {
        len_v = (value[0] == '+' || value[0] == '-') ? len_v - 1 : len_v;
        if (st_opt->opt_pre >= len_v)
            n_value = ft_applypre_d(value, st_opt->opt_pre, st_opt->opt_flag);
    }
    else
    {
        n_value = ft_strnew(len_v);
        ft_memcpy(n_value, value, len_v);
    }
    len_v = ft_strlen(n_value);
    ///////**** Flags
    // get index for flag '-'
    if (st_opt->opt_fwidth > len_v && ft_check_char(st_opt->opt_flag, '-') != 1)
        index = st_opt->opt_fwidth - len_v;
    // main flag
    ft_applymain_flag(resu, n_value, st_opt, &index);
    // Case if n_value = "0" swap with " "
    n_value[0] = (st_opt->c != 'o' && n_value[0] == '0' && n_value[1] == '\0' 
        && st_opt->opt_pre == 0) ? ' ' : n_value[0]; 
    // Get final result
    ft_memcpy(&resu[index], n_value, len_v);
    /// free
    (n_value != value) ? ft_strdel(&n_value) : NULL;
    return (resu);
}

//// ft_apply_len modifier_d : apply len modifier for d
char    *ft_apply_lenmod_d(long long int i_value, char *opt_len) /// Done
{
    char    *value;

    if (opt_len == NULL)
        value = ft_itoa((int )i_value);
    else if (ft_check_str(opt_len ,"hh"))
        value = ft_itoa((signed char)i_value);
    else if (ft_check_char(opt_len ,'h'))
        value = ft_itoa((short int ) i_value);
    else if (ft_check_str(opt_len ,"ll")) 
        value = ft_itoa((long long int ) i_value);
    else if (ft_check_char(opt_len ,'l'))
        value = ft_itoa((long int )i_value);
    else
        value = ft_itoa((int )i_value);
    return value;
}
