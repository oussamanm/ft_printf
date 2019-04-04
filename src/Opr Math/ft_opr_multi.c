
#include "../../includes/ft_printf.h"

//// ft_oprmul_h_cal : 
char    *ft_oprmul_h_cal(char *nbr, char n, int nbr_zero) /// Done
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

char    *ft_opr_multi(char *nbr1, char *nbr2, int i_free) /// Done
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