#ifndef _FT_PRINT_F
# define _FT_PRINT_F
#define UNUSED(x) (void)(x)
#define TO_INT(x) (x - '0')
typedef unsigned long long ft_uint64_t;

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>


typedef struct t_listopt
{
	char	*opt_flag;
	int		opt_fwidth;
	int		opt_pre;
	char	*opt_len;
	char	c;
}			st_listopt;
typedef struct t_expdouble
{
	int		sign;
	int		expo;
	char	*frac;
}			st_expdb;
typedef struct	s_bits
{
    int			bit_e;
    int        	bit_m;
	int			bit_bias;
}   		t_bits;

typedef struct s_typeld
{
	unsigned long long fra:64;
	unsigned long e:15;
	int	s:1;
}			st_typeld;
typedef union u_data
{
	long double ld;
	st_typeld st_ld;
}			ut_data;


char        *ft_stradd(char *nbr1, char *nbr2);


//****** Generale

//Main Function
int		ft_call_type(char c, st_listopt *st_opt, va_list *ap);
int		ft_arg(char *str, st_listopt	*st_opt);
int		ft_printf(char *str_print, ...);

//Flag
char    *ft_checkflag(char *str);
int     ft_checkfw(char *str);
int     ft_checkpre(char *str, int *index);
char    *ft_checklen(char *str);

//Add and Remove
st_listopt		*ft_add_lstopt();
st_expdb		*ft_add_lstexp();

//****** Function Help
int     ft_check_char(char *str, char c);
int     ft_find_char(char *str, char c);
int     ft_check_str(const char *src, const char *needle);
int     ft_declen(int nbr);
void	ft_bchar(char *str,size_t n ,char c);
int     ft_putstrr(char *s, int free_str);
char	*ft_strjoir(char *s1, char *s2, int rm);
void	ft_rmchar(char *src, char c);
char    *ft_add_char(char *str, int index , char c, int i_free);
char    *ft_strrev(char *str, size_t len, int alloc);
char    *ft_shift_str(int r_l, char *str,int nbr_shift);
char    *ft_escap_str(char *str); /// may be
unsigned long long ft_power(int nbr, int pwr);
unsigned long long ft_power_nega(int nbr, int pwr);
char	*ft_strnew_char(size_t size, char c);
int     ft_all_zero(char *nbr);

//****** Function type
int     ft_type_perc(st_listopt *st_opt, va_list *ap);
int     ft_type_c(st_listopt *st_opt, va_list *ap);
int     ft_type_s(st_listopt *st_opt, va_list *ap);
int     ft_type_d(st_listopt *st_opt, va_list *ap);
int     ft_type_o(st_listopt *st_opt, va_list *ap);
int     ft_type_u(st_listopt *st_opt, va_list *ap);
int     ft_type_p(st_listopt *st_opt, va_list *ap);

// Function type s (c)
char    *ft_apply_with(char *resu, char *value, st_listopt *st_opt);
void    ft_applypre_s(char *resu, char *value, st_listopt *st_opt);

// Function type d
char    *ft_applyopt_d(char *resu, char *value, st_listopt *st_opt);
char    *ft_applywith_d(char *resu, char *value, st_listopt *st_opt);
char    *ft_applypre_d(char *value, int opt_pre, char *opt_flag);
void    ft_applymain_flag(char *r, char *n_v, st_listopt *st_op, int *index);
void    ft_applyflagp_d(char *resu, char **n_value,int *index, st_listopt *st_opt);
void    ft_applyflags_d(char *resu, char *n_value,int *index, st_listopt *st_opt);
char    *ft_apply_lenmod_d(long long int i_value, char *opt_len);

// Function type o
char     *ft_conv_base(uint64_t value, int base, int b_maj);
unsigned long long    ft_apply_lenmod_o(va_list *ap, char *opt_len);

// Function type u
char    *ft_apply_lenmod_u(unsigned long long i_value, char *opt_len);

// Function type x
int     ft_type_x(st_listopt *st_opt, va_list *ap, char c);
int		ft_applyopt_x(char **resu, char **value, st_listopt *st_opt);
void    ft_applyflagh_x(char **r, char **n_v, st_listopt *st_opt);
void    ft_correct_flagx(st_listopt *st_opt, char *flag, char c);

// Function type p
int     ft_type_p(st_listopt *st_opt, va_list *ap);

// Function type F
int     ft_type_f(st_listopt *st_opt, va_list *ap);
char     *ft_type_lf(t_bits *st_bits, va_list *ap, int b_lf);
char     *ft_type_Lf(t_bits *st_bits, va_list *ap);
char    *ft_resu_frac(st_expdb *st_exp, int len_frac); // get resu from Function
char    *ft_applyopt_f(char *value, st_listopt *st_opt); // Apply Opt
char    *ft_applypre_f(char *value, int opt_pre, char *opt_flag);
char    *ft_correct_pre(char *value, int index);
int     ft_cas_spesc(int sign, char *i_value, st_listopt *st_opt);
void    ft_appyflagp_f(char *resu, char *value, int *indx, st_listopt *st_opt);

// fT_itoa_u 
char		*ft_itoa_u(unsigned long long int n);
long long	int	ft_atoi_u(const char *str, int len);

char    *ft_get_bmemor(int len, void *value);
char    *ft_get_bmemorld(int len, st_typeld *st_ld);
char    *ft_conv_bin_s(char *str, int len, int sign);
int     ft_conv_bin(char *str, int len);

//****** Operation math in string

// ADDI
char    *ft_opr_add(char *nbr1, char *nbr2, int i_free, int i_spec_cal);
void	ft_opradd_h_len(char **nbr1, char **nbr2, int *len, int i_spec_cal);
// MULTI
char    *ft_oprmul_h_cal(char *nbr, char n, int nbr_zero);
char    *ft_opr_multi(char *nbr1, char *nbr2, int i_free);
// POWER
char    *ft_opr_pow(char *nbr, char *pow, int i_free);
char    *ft_opr_negapower(char *nbr, char *power, int i_free);

#endif