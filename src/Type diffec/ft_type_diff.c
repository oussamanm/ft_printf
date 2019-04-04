/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:21:52 by onouaman          #+#    #+#             */
/*   Updated: 2019/02/27 11:21:54 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int     ft_type_o(st_listopt *st_opt, va_list *ap)
{
    unsigned long long int  i_value;
    char                    *resu;
    char                    *value;

    resu = NULL;
    value = NULL;
    i_value = 0;
    st_opt->c = 'o';
    i_value = ft_apply_lenmod_o(ap, st_opt->opt_len);
    if (i_value == 0) //// case of 0
    {
        if (st_opt->opt_fwidth > st_opt->opt_pre && st_opt->opt_pre <= 0)
            value = ft_strnew_char(1, '0');
        else if (st_opt->opt_pre == 0)
        {
            if (ft_check_char(st_opt->opt_flag ,'#') == 1)
                return (ft_putstrr("0", 0));
            return (ft_putstrr("", 0));
        }     
    }
    ////// Length modifier
    value = (i_value != 0) ? ft_conv_base(i_value, 8, 0) : value;
    if (ft_check_char(st_opt->opt_flag ,'#') == 1 && ft_strcmp(value, "0") != 0)
        value = ft_strjoir("0", value , 2);
    resu = ft_applywith_d(resu, value, st_opt);
    resu = ft_applyopt_d(resu, value, st_opt);
    // free value ;
    (value != NULL) ? ft_strdel(&value) : NULL;
    return (ft_putstrr(resu, 1));
}

int     ft_type_u(st_listopt *st_opt, va_list *ap)
{
    unsigned long long int  i_value;
    char                    *resu;
    char                    *value;

    resu = NULL;
    value = NULL;
    i_value = va_arg(*ap, unsigned long long int);
    ////// Apply opt
    value = ft_apply_lenmod_u(i_value, st_opt->opt_len);
    if (ft_atoi(value) == 0 && st_opt->opt_pre == 0) //// case of 0
    {
        if (value != NULL)
            free(value);
        if (ft_check_char(st_opt->opt_flag, ' ') == 1)
            return (ft_putstrr(" ", 0));
        return 0;
    }
    //// remove flag not exist in type u
    if (ft_check_char(st_opt->opt_flag, '+') == 1)
        ft_rmchar(st_opt->opt_flag, '+');

    resu = ft_applywith_d(resu, value, st_opt);
    resu = ft_applyopt_d(resu, value, st_opt);
    // free value and resu;
    if (value != NULL)
        ft_strdel(&value);
    return (ft_putstrr(resu, 1));
}

int     ft_type_x(st_listopt *st_opt, va_list *ap, char c) /// Done
{
    unsigned long long int  i_value;
    char                    *resu;
    char                    *value;
    int                     index;

    resu = NULL;
    index = 0;
    st_opt->c = c;
    i_value = va_arg(*ap , unsigned long long int);
    //i_value = ft_apply_lenmod_o(ap, st_opt->opt_len);
    if (st_opt->opt_pre == 0 && i_value == 0)
    {
        if (st_opt->opt_fwidth == -1)
            return 0;
        return (ft_putstrr(ft_strnew_char(st_opt->opt_fwidth, ' '), 1));
    }
    ////// Get Binary
    value = ft_conv_base(i_value, 16, (c == 'x') ? 0 : 1);
    ////// Correct Flag ex : rm '0' if it has pre 
    ft_correct_flagx(st_opt, st_opt->opt_flag, 'x');
    ///// Apply pre all Opt
    i_value = ft_applyopt_x(&resu, &value, st_opt);
    //// Apply flag '#'
    //printf("value1 = %p \n",value);
    ft_applyflagh_x(&resu, &value, st_opt);
    //// Remp Resu
    i_value = ft_strlen(value);
    if (st_opt->opt_fwidth > (int )i_value && ft_check_char(st_opt->opt_flag, '-') != 1)
        index = st_opt->opt_fwidth - i_value;
    ft_memcpy(&resu[index], value, i_value);
    //printf("value2 = %p \n",value);
    // free value :
    //(value != NULL) ? free(value) : NULL;
    return (ft_putstrr(resu, 1));
}

int     ft_type_p(st_listopt *st_opt, va_list *ap)
{
    unsigned long long int  i_value;
    char                    *resu;
    char                    *value;
    int                     rtn;

    resu = NULL;
    value = NULL;
    i_value = va_arg(*ap , unsigned long long int);
    //i_value = ft_apply_lenmod_o(ap, st_opt->opt_len);
    ////// Length modifier
    value = ft_conv_base(i_value, 16, 0);
    //if (ft_check_char(st_opt->opt_flag ,'#') == 1)
    value = ft_strjoir("0x",value ,2);
    resu = ft_applywith_d(resu, value, st_opt);
    resu = ft_applyopt_d(resu, value, st_opt);
    rtn = ft_putstrr(resu, 1);
    // free value ;
    if (value != NULL)
        ft_strdel(&value);
    return (rtn);
}