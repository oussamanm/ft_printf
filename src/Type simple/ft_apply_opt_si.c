
#include "../../includes/ft_printf.h"

////**  Type s and c **/////

// width tyep 's' and 'c'
char    *ft_apply_with(char *resu, char *value, st_listopt *st_opt) // Done
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
void    ft_applypre_s(char *resu, char *value , st_listopt *st_opt) // Done
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
