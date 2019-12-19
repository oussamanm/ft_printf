/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:13:14 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/16 21:48:45 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# define UNUSED(x) (void)(x)
# define TO_INT(x) (x - '0')
# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct			s_listopt
{
	char				*opt_flag;
	int					opt_fwidth;
	int					opt_pre;
	char				*opt_len;
	char				c;
}						t_listopt;
typedef struct			s_expdb
{
	int					sign;
	int					expo;
	char				*frac;
}						t_expdb;
typedef struct			s_bits
{
	int					bit_e;
	int					bit_m;
	int					bit_bias;
}						t_bits;
typedef struct			s_typeld
{
	unsigned long long	fra:64;
	unsigned long		e:15;
	int					s:1;
}						t_typeld;
typedef union			u_data
{
	long double			ld;
	t_typeld			st_ld;
}						t_data;

int						ft_call_type(char *str, t_listopt *st_opt,
		va_list *ap);
int						ft_arg(char *str, t_listopt	*st_opt);
int						ft_printf(char *str_print, ...);
int						ft_check_argv(char *str, int *i, t_listopt *st_opt,
		va_list *ap);
char					*ft_checkflag(char *str);
int						ft_checkfw(char *str);
int						ft_checkpre(char *str, int *index);
char					*ft_checklen(char *str);
t_listopt				*ft_add_lstopt();
t_expdb					*ft_add_lstexp();
int						ft_check_char(char *str, char c);
int						ft_find_char(char *str, char c);
int						ft_check_str(const char *src, const char *needle);
int						ft_declen(int nbr);
void					ft_bchar(char *str, size_t n, char c);
int						ft_putstrr(char *s, int free_str);
char					*ft_strjoir(char *s1, char *s2, int rm);
void					ft_rmchar(char *src, char c);
char					*ft_add_char(char *str, int index, char c, int i_free);
char					*ft_strrev(char *str, size_t len, int alloc);
char					*ft_shift_str(int r_l, char *str, int nbr_shift);
char					*ft_escap_str(char *str);
unsigned long long		ft_power(int nbr, int pwr);
unsigned long long		ft_power_nega(int nbr, int pwr);
char					*ft_strnew_char(size_t size, char c);
int						ft_all_zero(char *nbr);
int						ft_checkz_f(t_expdb *st_exp, t_bits *st_b);
char					*ft_typef_help(t_listopt *st_opt, t_bits *st_bits,
		va_list *ap);
int						ft_type_perc(t_listopt *st_opt, va_list *ap);
int						ft_type_c(t_listopt *st_opt, va_list *ap);
int						ft_type_s(t_listopt *st_opt, va_list *ap);
int						ft_type_d(t_listopt *st_opt, va_list *ap);
int						ft_type_o(t_listopt *st_opt, va_list *ap);
int						ft_type_u(t_listopt *st_opt, va_list *ap);
int						ft_type_p(t_listopt *st_opt, va_list *ap);
int						ft_type_x(t_listopt *st_opt, va_list *ap, char c);
char					*ft_apply_with(char *resu, char *value,
		t_listopt *st_opt);
void					ft_applypre_s(char *resu, char *value,
		t_listopt *st_opt);
char					*ft_applyopt_d(char *resu, char *value,
		t_listopt *st_opt, int index);
char					*ft_applywith_d(char *resu, char *value,
		t_listopt *st_opt);
char					*ft_applypre_d(char *value, int opt_pre,
		char *opt_flag);
void					ft_applymain_flag(char *r, char *n_v, t_listopt *st_op,
		int *index);
void					ft_applyflagp_d(char *resu, char **n_value, int *index,
		t_listopt *st_opt);
void					ft_applyflags_d(char *resu, char *n_value, int *index,
		t_listopt *st_opt);
char					*ft_apply_lenmod_d(long long int i_value,
		char *opt_len);
char					*ft_conv_base(uint64_t value, int base, int b_maj);
unsigned long long		ft_apply_lenmod_o(va_list *ap, char *opt_len);
char					*ft_apply_lenmod_u(unsigned long long i_value,
		char *opt_len);
int						ft_applyopt_x(char **resu, char **value,
		t_listopt *st_opt, char c);
void					ft_applyflagh_x(char **r, char **n_v,
		t_listopt *st_opt);
void					ft_correct_flagx(t_listopt *st_opt, char *flag,
		char c);
int						ft_type_f(t_listopt *st_opt, va_list *ap);
char					*ft_type_lf(t_bits *st_bits, va_list *ap, int b_lf);
char					*ft_type_ldf(t_bits *st_bits, va_list *ap);
char					*ft_resu_frac(t_expdb *st_exp,
		int len_frac, t_bits *st_b);
char					*ft_applyopt_f(char *value, t_listopt *st_opt);
char					*ft_applypre_f(char *value, int opt_pre,
		char *opt_flag);
char					*ft_correct_pre(char *value, int index);
int						ft_cas_spesc(int sign, char *i_value,
		t_listopt *st_opt);
void					ft_appyflagp_f(char *resu, char *value, int *indx,
		t_listopt *st_opt);
char					*ft_itoa_u(unsigned long long int n);
long long int			ft_atoi_u(const char *str, int len);
char					*ft_get_bmemor(int len, void *value);
char					*ft_get_bmemorld(int len, t_typeld *st_ld);
char					*ft_conv_bin_s(char *str, int len, int sign);
int						ft_conv_bin(char *str, int len);
char					*ft_opr_add(char *nbr1, char *nbr2, int i_free,
		int i_spec_cal);
char					*ft_opradd_h_len(char **nbr1, char **nbr2, int *len,
		int i_spec_cal);
char					*ft_oprmul_h_cal(char *nbr, char n, int nbr_zero);
char					*ft_opr_multi(char *nbr1, char *nbr2, int i_free);
char					*ft_opr_pow(char *nbr, char *pow, int i_free);
char					*ft_opr_negapower(char *nbr, char *power, int i_free);
int						printcolor(char *color);
int						checkcolor(char *str);
int						ft_type_k();
int						ft_type_b(char c, va_list *ap);
char					*ft_stradd(char *nbr1, char *nbr2);
#endif
