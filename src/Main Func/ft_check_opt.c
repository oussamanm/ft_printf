/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:37:05 by onouaman          #+#    #+#             */
/*   Updated: 2019/02/26 17:37:06 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char    *ft_checkflag(char *str) // Main : return string of flag cln
{
    int     i;
    char    *resu;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '-' && str[i] != '+' && str[i] != '0' &&
            str[i] != ' ' && str[i] != '#')
        {
            if (i == 0)
                return (NULL);
            else
                break ;
        }
        i++;
    }
    resu = ft_strsub(str, 0, i);
    return (resu);
}

int     ft_checkfw(char *str) // Main : return int of with  cln
{
    int     i;
    int    resu;
    char    *temp;

    i = 0;
    temp = NULL;
    while (str[i] != '\0' && ft_isdigit(str[i]))        
        i++;
    if (i == 0)
        return (-1);
    temp = ft_strsub(str, 0, i);
    resu = ft_atoi(temp);
    if (temp != NULL)
        ft_strdel(&temp);
    return (resu);
}

int     ft_checkpre(char *str, int *index) // Main : return int of prec cln
{
    int     i;
    int     resu;
    char    *temp;

    i = 0;
    temp = NULL;
    if (str[0] != '\0' && str[0] == '.')
    {
        i++;
        while (str[i] != '\0' && ft_isdigit(str[i]))        
            i++;
    }
    if (i == 0)
        return (-1);
    resu = 1;
    if (i > 1)
    {
        temp = ft_strsub(str, 1, i);
        resu = ft_atoi(temp);
    }
    else if (i == 1)
        resu = 0;
    *index += i; 
    ft_strdel(&temp);
    return (resu);
}

char    *ft_checklen(char *str) // Main : return string of len cln
{
    int     i;
    char    *resu;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != 'h' && str[i] != 'l' && str[i] != 'L')
        {
            if (i == 0)
                return (NULL);
            else
                break ;
        }
        i++;
    }
    resu = ft_strsub(str, 0, i);
    return (resu);
}