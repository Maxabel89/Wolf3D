/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:20:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:45:00 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <sys/types.h>
# include <inttypes.h>
# include <stddef.h>
# include <stdarg.h>

# define MIN(a,b)		(((a) < (b)) ? (a) : (b))
# define MAX(a,b)		(((a) > (b)) ? (a) : (b))
# define ABS(a)			(((a) < 0) ? -(a) : (a))
# define BUFF_SIZE 8
# define FTULONG	unsigned long long int

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** FT_PRINTF STRUCTURES
*/
typedef FTULONG	t_ulong;

typedef struct		s_format
{
	char			name;
	void			(*func)();
	char			*disabled;
}					t_format;

typedef struct		s_opt
{
	char			*flags;
	char			width;
	char			preci;
	int				preci_set;
	const char		*length;
	t_format		*format;
}					t_opt;

typedef struct		s_str
{
	char			*content;
	int				length;
	int				alloc_length;
}					t_str;
/*
** GET NEXT LINE STRUCTURES
*/
typedef struct		s_gnl
{
	char			buf[BUFF_SIZE];
	int				i;
	int				r;
	int				s;
}					t_gnl;

typedef struct		s_norme
{
	int				f;
	char			*n;
	int				l;
	int				t;
}					t_norme;

/*
** LIBFT FUNCTIONS
*/
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_strisalpha(char *str);
int					ft_str_isnumber(char *str);
int					ft_str_isempty(char const *str, char c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putexit(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_idx(const char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strupper(char *str);
void				ft_strlower(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_swap(int a, int b);
int					get_next_line(int const fd_const, char **line);
/*
** FT_PRINTF STRUCTURES
*/
int					ft_printf(const char *format, ...);
int					ft_strext(t_str *str, int	need);
void				add_str(t_str *str, const char *add, int size, t_opt *opt);
void				ft_stradd_c(t_str *str, char c);
void				ft_stradd_d(t_str *str, double d, int preci);
void				ft_stradd(t_str *str, const char *add);
void				ft_stradd_de(t_str *str, double d, int preci);
void				ft_stradd_i(t_str *str, int nbr);
void				ft_stradd_l(t_str *str, const char *add, int len);
void				ft_str_insc(t_str *str, char c, int index);
void				ft_str_insl(t_str *str, const char *ins, int index, int l);
void				ft_str_ins(t_str *str, const char *ins, int index);
void				ft_strtrim_c(t_str *str, const char *trim);
void				ft_initstr(t_str *str);
int					ft_strput(t_str *str);
void				add_nchar(t_str *out, char c, int len, t_opt *opt);
unsigned int		ft_wstrlen(wchar_t *wstr);
int					ft_wstrconv(char *buff, wchar_t *wstr);
int					ft_wstrnconv(char *buff, wchar_t *wstr, int n);
int					ft_wtoa(char *buff, wchar_t w);
void				clear_dis(t_opt *opt);
int					is_separator(char c);
int					ft_atoin(const char *str, int len);
void				flag_list(t_format *flag);
void				flag_list2(t_format *flag);
void				flag_list3(t_format *flag);
void				format_len(char **tab);
int					get_length(t_opt *opt, const char *format);
void				pad_preci(t_str *str, int start, t_opt *opt);
void				parsef(t_str *out, const char *format, va_list *ap);
void				flag_c(t_str *out, t_opt *opt, va_list *ap);
void				flag_d(t_str *out, t_opt *opt, va_list *ap);
void				flag_o(t_str *out, t_opt *opt, va_list *ap);
void				flag_p(t_str *out, t_opt *opt, va_list *ap);
void				flag_percent(t_str *out, t_opt *opt, va_list *ap);
void				flag_s(t_str *out, t_opt *opt, va_list *ap);
void				flag_u(t_str *out, t_opt *opt, va_list *ap);
void				flag_x(t_str *out, t_opt *opt, va_list *ap);
long long int		get_arg(t_opt *opt, va_list *ap);
t_ulong				get_unsigned_arg(t_opt *opt, va_list *ap);
long double			get_float_arg(t_opt *opt, va_list *ap);
char				*ft_itobase(t_ulong nb, const char *base);

#endif
