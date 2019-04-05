#include "../../includes/ft_printf.h"

//// ft_opradd_h_len : get len fot str
char     *ft_opradd_h_len(char **nbr1, char **nbr2, int *len, int i_spec_cal) /// Done
{
    char    *str1;
    char    *str2;
    int     len1;
    int     len2;
    char    *str;

    len1 = ft_strlen(*nbr1);
    len2 = ft_strlen(*nbr2);
    *len = (len1 > len2) ? len1 : len2;
    str1 = ft_strnew_char(*len, '0');
    str2 = ft_strnew_char(*len, '0');
    if (i_spec_cal != 1)
    {
        (len1 == *len) ? ft_strcpy(str1,*nbr1) : ft_strcpy(&str1[*len - len1], *nbr1);
        (len2 == *len) ? ft_strcpy(str2,*nbr2) : ft_strcpy(&str2[*len - len2], *nbr2);
    }
    (*nbr1 != NULL) ? ft_strdel(nbr1) : NULL;
    (*nbr2 != NULL) ? ft_strdel(nbr2) : NULL;
    *nbr1 = str1;
    *nbr2 = str2;
    *len =  (str1[0] == 0 || str2[0] == 0) ? -1 : *len;
    str = ft_strnew_char(*len, '0');
    (*len)--;
    return (str);
}

char    *ft_opr_add(char *nbr1, char *nbr2, int i_free, int i_spec_cal) /// Done  and //// i_spec_cal == 0  : simple calcule else : without resepecting order
{
    int     len;
    int     o_len;
    int     sum;
    int     res;
    char    *str;

    res = 0;    
    str = ft_opradd_h_len(&nbr1 , &nbr2, &len, i_spec_cal); // get len fot str and correct nbr1 and nbr2
    o_len = len++;
    while (--len >= 0)
    {
        sum = (nbr1[len] - '0') + (nbr2[len] - '0') + res;
        res = (sum > 9) ? ((sum <= 19) ? 1 : 2) : 0;
        sum -= (sum > 9) ? ((sum <= 19) ? 10 : 20) : 0;
        str[len] = sum + '0';
        if (len == 0 && res != 0)
        {
            ft_memmove(&str[1], &str[0], o_len + 1);
            str[0] = res + '0';
        }
    }
    (i_free == 1 || i_free == 3) ? ft_strdel(&nbr1) : NULL;
    (i_free == 2 || i_free == 3) ? ft_strdel(&nbr2) : NULL;
    (i_spec_cal == 0) ? ft_escap_str(str) : NULL;
    return (str);
}
