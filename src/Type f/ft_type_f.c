/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:14:44 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:14:46 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/// ft_type_f : Main function for type f
int     ft_type_f(st_listopt *st_opt, va_list *ap) /// Done
{
    char        *i_value;
    int         rtn; // if Resul is NaN or Infi
    st_expdb    *st_exp;
    t_bits      st_bits;

    st_exp = ft_add_lstexp();
    i_value = ft_typef_help(st_opt, &st_bits, ap);
    st_exp->sign = TO_INT(i_value[0]);
    st_exp->expo = ft_conv_bin(&i_value[1], st_bits.bit_e) - st_bits.bit_bias;
    rtn = (st_exp->expo == 128) ? ft_cas_spesc(st_exp->sign, &i_value[st_bits.bit_e + 1], st_opt) : 0; /// add condition down if rtn == 0
    if (rtn == 0)
    {
        if (ft_check_char(st_opt->opt_len, 'L') == 1)
            st_exp->frac = ft_conv_bin_s(&i_value[st_bits.bit_e + 1], st_bits.bit_m, 2); /// remove (-1) in  .bit_e - 1
        else
            st_exp->frac = ft_conv_bin_s(&i_value[st_bits.bit_e + 1], st_bits.bit_m, 0);
        st_exp->frac = ft_resu_frac(st_exp, (ft_strlen(st_exp->frac) - 1)); /// get resu with point float
        ft_strdel(&i_value);
        i_value = ft_applyopt_f(st_exp->frac, st_opt);
    }
    else
        (i_value != NULL) ? ft_strdel(&i_value) : NULL;
    (st_exp != NULL) ? free(st_exp) : NULL;
    return ((rtn == 0) ? ft_putstrr(i_value, 1) : rtn);
}

/// Fill i_value with binary && fill struct bit position
char     *ft_type_lf(t_bits *st_bits, va_list *ap, int b_lf) /// Done
{
    char        *i_value;
    float       fvalue;
    double      dvalue;

    if (b_lf == 1) // double
    {
        dvalue = va_arg(*ap, double);
        i_value = ft_get_bmemor(63, &dvalue);
        (*st_bits).bit_e = 11;
        (*st_bits).bit_m = 52;
        (*st_bits).bit_bias = 1023;
        return (i_value);
    }
    // else float
    fvalue = va_arg(*ap, double);
    i_value = ft_get_bmemor(31, &fvalue);
    (*st_bits).bit_e = 8;
    (*st_bits).bit_m = 23;
    (*st_bits).bit_bias = 127;
    return (i_value);
}
char     *ft_type_Lf(t_bits *st_bits, va_list *ap) /// Done
{
    char            *i_value;
    long double     value;
    ut_data         u_ld;

    value = va_arg(*ap, long double);
    u_ld.ld = value;
    i_value = ft_get_bmemorld(79, &u_ld.st_ld);
    (*st_bits).bit_e = 15;
    (*st_bits).bit_m = 63;
    (*st_bits).bit_bias = 16383;
    return (i_value);
}

/// Calcule Fraction & expo To get result
char    *ft_resu_frac(st_expdb *st_exp, int len_frac) /// Don
{
    int     index_p;
    char    *temp;

    (ft_all_zero(&st_exp->frac[1]) == 1) ? ft_strdel(&st_exp->frac) :  NULL;
    if (st_exp->expo > 0)
        st_exp->frac = ft_opr_multi(st_exp->frac, (st_exp->frac != NULL) ? ft_opr_pow("2", ft_itoa(st_exp->expo), 2) : NULL, 3);///free
    else /// expo < 0 ==> fra * 5^(ex) and add expo to len_frac
    {
        st_exp->frac = ft_opr_multi(st_exp->frac, (st_exp->frac != NULL) ? ft_opr_pow("5", ft_itoa(st_exp->expo * -1), 2) : NULL, 3);////free
        len_frac += (st_exp->expo * -1); /// - 1 bricole
    }
    index_p = ft_strlen(st_exp->frac) - len_frac;
    if (index_p > 0)
        st_exp->frac = ft_add_char(st_exp->frac, index_p, '.', 1);
    else if (index_p == 0)
        st_exp->frac = ft_strjoir("0.", st_exp->frac, 2);
    else if (index_p < 0)
    {
        temp = ft_strjoir("0.", ft_strnew_char((index_p * -1), '0'), 2);
        st_exp->frac = ft_strjoir(temp, st_exp->frac, 3);
    }
    st_exp->frac = (st_exp->sign == 1) ? 
        ft_strjoir("-", st_exp->frac, 2) : st_exp->frac;
    return (st_exp->frac);
}

/// Case NaN and Infi and -Infi
int     ft_cas_spesc(int sign, char *i_value, st_listopt *st_opt) /// Done
{
    /// check NaN
    char    *n_value;

    n_value = ft_strnew(4);
    while (*i_value != '\0')
    {
        if (*i_value == '1')
            break ;
        i_value++;
    }
    if (*i_value && *i_value == '1')
        ft_strcpy(n_value, "nan");
    else
        (sign == 0) ? ft_strcpy(n_value, "inf") : ft_strcpy(n_value, "-inf");
    //// remove flag not exist
    ft_rmchar(st_opt->opt_flag, '+');
    ft_rmchar(st_opt->opt_flag, ' ');
    ft_rmchar(st_opt->opt_flag, '#');
    n_value = ft_applyopt_f(n_value, st_opt);
    return(ft_putstrr(n_value, 1));
}
