/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:26:57 by onouaman          #+#    #+#             */
/*   Updated: 2019/02/27 21:26:59 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

////**  Type s and c **/////

// width tyep 's' and 'c'
char    *ft_apply_with(char *resu, char *value, st_listopt *st_opt)
{
    int     len;

    len = (int)ft_strlen(value);
    if (st_opt->opt_fwidth > len || (st_opt->opt_fwidth < len && 
        st_opt->opt_pre != -1 && st_opt->opt_fwidth > st_opt->opt_pre))
    {
        resu = ft_strnew(st_opt->opt_fwidth);
        len = st_opt->opt_fwidth;
    }
    else
    {
        if (st_opt->opt_pre != -1 && st_opt->opt_pre < len)
            len = st_opt->opt_pre;
        resu = ft_strnew(len);
    }
    ft_bchar(resu, len, ' ');
    return (resu);
}

// Precision
void    ft_applypre_s(char *resu, char *value , st_listopt *st_opt)
{
    char    *n_value;
    size_t  len_value;
    int     reste;

    len_value = ft_strlen(value);
    n_value = value;
    reste = 0;
    /// cas pre < len (cut value)
    if (st_opt->opt_pre < (int  )len_value && st_opt->opt_pre != -1)
        n_value = ft_strsub(value, 0, st_opt->opt_pre);
    if (st_opt->opt_fwidth > (int )ft_strlen(n_value))
    {
        reste = st_opt->opt_fwidth - (int )ft_strlen(n_value);
        /// Apply flag '-'
        if (st_opt->opt_flag != NULL && ft_check_char(st_opt->opt_flag, '-') == 1)
            reste = 0;
    }
    ft_memcpy(&resu[reste], n_value, ft_strlen(n_value));
    if (n_value != value && n_value)
        free(n_value);
}

//////**  Type x X **/////
int    ft_applyopt_x(char **resu, char **value, st_listopt *st_opt)
{
    int     len;
    char    *n_value;
    char    c;
    int     len_v;

    c = ' ';
    n_value = *value;
    len_v = (int )ft_strlen(*value);
    len = len_v;
    if (st_opt->opt_fwidth > len_v && st_opt->opt_fwidth > st_opt->opt_pre)
    {
        if (ft_check_char(st_opt->opt_flag, '0') == 1 && st_opt->opt_pre == -1)
            c = '0';
        len = st_opt->opt_fwidth;
    }
    if (st_opt->opt_pre != -1 && st_opt->opt_pre > len_v)
    {
        if (st_opt->opt_pre > st_opt->opt_fwidth)
        {
            len = st_opt->opt_pre;
            c = '0';
        }
        n_value = ft_strnew_char(st_opt->opt_pre, '0');
        ft_memcpy(&n_value[st_opt->opt_pre - len_v], *value, len_v);
        len_v = ft_strlen(n_value);
    }
    *resu = ft_strnew_char(len, c);
    //if (*value != NULL)
    //    ft_strdel(value);
    *value = n_value;
    return (len_v);
}

void    ft_applyflagh_x(char **r, char **n_v, st_listopt *st_opt)
{
    int     len;
    int     i;

    i = 0;
    len = (int )ft_strlen(*n_v);
    if (ft_check_char(st_opt->opt_flag, '#') == 1)
    {
        /// Check if Value sll 0's
        while (*n_v && (*n_v)[i] != '\0')
        {
            if ((*n_v)[i] != '0')
            {
                i = -1;
                break ;
            }
            i++;
        }
        /// Case with and flag '0'
        if (i == -1 && st_opt->opt_fwidth > len && ft_check_char(st_opt->opt_flag, '0') == 1)
            *r = ft_memcpy(*r, (st_opt->c == 'x' ? "0x" : "0X"), 2);
        else if (i == -1)
            *n_v = ft_strjoir((st_opt->c == 'x' ? "0x" : "0X"), *n_v, 2);
    }
}

void    ft_correct_flagx(st_listopt *st_opt, char *flag, char c)
{
    int i;

    i = 0;
    if (c == 'x' || c == 'd' || c == 'i')
    {
        if (st_opt->opt_pre != -1 || ft_check_char(flag, '-') == 1)
        {
            ft_rmchar(flag, '0');
        }

    }
}


//////**  Type o **/////

char    *ft_apply_lenmod_u(unsigned long long i_value, char *opt_len)
{
    char    *value;

    if (opt_len == NULL)
        return (ft_itoa_u(i_value));
    if (ft_check_str(opt_len ,"hh"))
        value = ft_itoa_u((unsigned char )i_value);
    else if (ft_check_char(opt_len ,'h'))
        value = ft_itoa_u((unsigned short int ) i_value);
    else if (ft_check_str(opt_len ,"ll")) 
        value = ft_itoa_u((unsigned long long int ) i_value);
    else if (ft_check_char(opt_len ,'l'))
        value = ft_itoa_u((unsigned long int )i_value);
    else
        value = ft_itoa_u(i_value);
    return value;
}


///////** Type u **//////

unsigned long long    ft_apply_lenmod_o(va_list *ap, char *opt_len)
{
    unsigned long long int i_value;

    i_value = va_arg(*ap, unsigned long long);
    if (opt_len == NULL)
        return (i_value);
    if (ft_check_str(opt_len ,"hh"))
        i_value = (unsigned char ) i_value;
    else if (ft_check_char(opt_len ,'h'))
        i_value = (unsigned short int) i_value;
    else if (ft_check_str(opt_len ,"ll")) 
        i_value = (unsigned long long int) i_value;
    else if (ft_check_char(opt_len ,'l'))
        i_value = (unsigned long int) i_value;
    return i_value;
}