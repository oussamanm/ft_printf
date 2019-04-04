/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyopt_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:11:18 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:11:21 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

///// ft_apply_with_d : Apply width 
char    *ft_applywith_d(char *resu, char *value, st_listopt *st_opt) // Done
{
    int     len;
    int     i;

    i = 0;
    len = (int)ft_strlen(value);
    if (st_opt->opt_fwidth > len && st_opt->opt_fwidth > st_opt->opt_pre)
    {
        resu = ft_strnew(st_opt->opt_fwidth);
        ft_bchar(resu, st_opt->opt_fwidth, ' ');
    }
    else if (st_opt->opt_pre > len)
    {
        if (value[0] == '-' || ft_check_char(st_opt->opt_flag, '+') == 1)
            i = 1;
        resu = ft_strnew(st_opt->opt_pre + i);
        ft_bchar(resu, st_opt->opt_pre, '0');
    }
    else
    {
        if (ft_check_char(st_opt->opt_flag, ' ') == 1 && value[0] != '-')
            len++;
        resu = ft_strnew(len);
        ft_bchar(resu, len, ' ');
    }
    return (resu);
}

///// ft_applypre_d : Apply pre and add sign 
char    *ft_applypre_d(char *value, int opt_pre, char *opt_flag) // Done
{
    char    *n_value;
    int     len_value;
    int     len_v;
    int     bln_nega;

    n_value = value;
    bln_nega = (value[0] == '-') ? 1 : 0;
    value = (value[0] == '+' || value[0] == '-') ? value + 1 : value;
    len_v = (int )ft_strlen(value);
    if (bln_nega == 1 || ft_check_char(opt_flag, '+') == 1 ||
     (value[0] == 0 && ft_check_char(opt_flag, '+') == 1))
    {
        len_value = opt_pre + 1;
        n_value = ft_strnew(len_value);
        ft_bchar(n_value, len_value,'0');
        n_value[0] = (bln_nega == 0) ? '+' : '-';
    }
    else
    {
        len_value = opt_pre;
        n_value = ft_strnew(len_value);
        ft_bchar(n_value, len_value,'0');
    }
    ft_memcpy(&n_value[len_value - len_v], value, len_v);
    return (n_value);
}

///// ft_apply_main_flag : apply flag '0','+',' '
void    ft_applymain_flag(char *r, char *n_v, st_listopt *st_op, int *index) // Done
{
    int len_value;
    len_value = ft_strlen(n_v);

    /// Flag '0'
    if (ft_check_char(st_op->opt_flag, '0') == 1 && st_op->opt_pre == -1 && st_op->opt_fwidth > len_value)
        ft_bchar(r, st_op->opt_fwidth, '0');
    /// Flag '+'
    if (st_op->opt_pre == -1 || (st_op->opt_pre < len_value && ft_isdigit(n_v[0]) == 1))
        ft_applyflagp_d(r, &n_v, index, st_op);
    /// Flag ' '
    ft_applyflags_d(r, n_v, index, st_op);
}

// Flags '+'
void    ft_applyflagp_d(char *resu, char **n_value, int *index, st_listopt *st_opt) /// Done
{
    if (ft_check_char(st_opt->opt_flag, '+') == 1 && (*n_value)[0] != '-') /// Check to Add + /// conditon removed st_opt->opt_pre == -1 && ***************
    {
        if (*index == 0)
            resu[(*index)++] = '+';
        else
        {
            if (ft_check_char(st_opt->opt_flag, '0') == 1 &&
             st_opt->opt_fwidth > (int)ft_strlen(*n_value))
                resu[0] = '+'; /*change *n_value[0] with resu[0] in example |%+08d|\n", 13 */
            resu[*index - 1] = (*n_value[0] != '+') ? '+' : resu[*index - 1];
        }
    }
    if ((*n_value)[0] == '-' && ft_check_char(st_opt->opt_flag, '0') == 1) /// Check to Add '-' in case of using (flage +) or (value < 0 && flag '0')
    {
        if (st_opt->opt_fwidth <= (int)ft_strlen(*n_value))
            return ;
        else if ((st_opt->opt_fwidth != -1 && st_opt->opt_pre == -1  &&
            ft_check_char(st_opt->opt_flag, '0') == 1) ||
            st_opt->opt_pre > ((int)ft_strlen(*n_value) - 1))
        {
            resu[0] = '-';
            ft_rmchar(*n_value, '-');
            (*index)++;
        }
    }
}

// ft_applyflagspace_d : apply Flag ' '
void    ft_applyflags_d(char *resu, char *n_v, int *indx, st_listopt *st_opt)  /// Done
{
    int     len_value;

    len_value = ft_strlen(n_v);
    if (ft_check_char(st_opt->opt_flag, ' ') == 1)
    {
        if (n_v[0] != '-')
        {
            if (*indx == 0)
                resu[(*indx)++] = ' ';
            else
                resu[0] = ' ';
        }
    }
}
