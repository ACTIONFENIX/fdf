/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:37:37 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/21 22:30:31 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include "array.h"

# define STDOUT 1

# define BUFF_SIZE		32

# define READ_SUCCESS	1
# define READ_END		0
# define READ_FAILURE  -1
# define READ_ING		2

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			buff[BUFF_SIZE + 1];
	t_list			*multifd;
}					t_gnl;

struct				s_flags_specificator
{
	unsigned int flags_minus: 1;
	unsigned int flags_plus: 1;
	unsigned int flags_space: 1;
	unsigned int flags_sharp: 1;
	unsigned int flags_zero: 1;
	unsigned int flags_empty: 3;
};

extern char			g_printf_modifiers[5][3];

struct				s_printf_specificator
{
	struct s_flags_specificator	flags;
	int							width;
	int							precision;
	bool						precision_activated;
	char						modifier[3];
	char						cast[3];
	int							fd;
};

struct				s_cast
{
	char	*code;
	int		(*func)(va_list *, struct s_printf_specificator *);
};

extern struct s_cast	g_cast_func[13];

int					ft_isupper(int c);

int					ft_islower(int c);

int					ft_isspace(int c);

size_t				ft_strspn(const char *str, const char *substr);

size_t				ft_strcspn(const char *str, const char *substr);

void				ft_lstpushback(t_list **begin, t_list *lst);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_atoi(const char *str);

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *str);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t num);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t num);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strstr(const char *str, const char *substr);

char				*ft_strnstr(const char *str, const char *substr,
					size_t len);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t len);

void				*ft_memset(void *ptr, int val, size_t num);

void				ft_bzero(void *b, size_t len);

void				*ft_memcpy(void *dest, const void *src, size_t num);

void				*ft_memccpy(void *dest, const void *src, int c, size_t num);

void				*ft_memmove(void *dest, const void *src, size_t num);

void				*ft_memchr(const void *ptr, int val, size_t num);

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char*));

void				ft_striteri(char *s, void (*f)(unsigned int, char*));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

size_t				ft_lstsize(t_list *lst);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_max(int a, int b);

int					ft_min(int a, int b);

long int			ft_lmax(long int a, long int b);

long int			ft_lmin(long int a, long int b);

long long int		ft_llmax(long long int a, long long int b);

long long int		ft_llmin(long long int a, long long int b);

bool				ft_isnan(double d);

bool				ft_isinf(double d);

double				ft_pow(double base, int exponent);

union				u_dtostr_double
{
	double					d;
	unsigned long long int	i;
};

bool				ft_double_is_negative(double d);

char				*dtostr(double d, int precision);

double				ft_decimal(double d);

char				*ldtostr(long double d, int precision);

long double			ft_ldecimal(long double d);

char				*ft_dtostr_isnan_or_inf(double d);

int					ft_abs(int n);

long int			ft_labs(long int n);

long long int		ft_llabs(long long int n);

int					ft_ulltoa_base_size(unsigned long long int val, int base);

void				ft_ulltoa_base(char *str, unsigned long long int val,
		const char *abase);

void				ft_strfilln(char *str, char c, int n);

int					get_next_line(const int fd, char **line);

char				*ft_strndup(const char *str, size_t n);

void				ft_pcpy(void *to, const void *from);

int					ft_printf(const char *format, ...);

int					fd_printf(int fd, const char *format, ...);

int					printf_core(int fd, const char *format, va_list *params);

void				printf_parse_flags_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec);

void				printf_parse_width_specificator(va_list *params,
		const char *format, const char *format_end,
		struct s_printf_specificator *spec);

void				printf_parse_precision_specificator(va_list *params,
		const char *format, const char *format_end,
		struct s_printf_specificator *spec);

void				printf_parse_modifier_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec);

void				printf_parse_cast_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec);

const char			*printf_parse_specificator(va_list *params,
		const char *format, struct s_printf_specificator *spec);

int					printf_print_raw_string(const char **ptr, int fd);

int					printf_write_width(struct s_printf_specificator *spec,
		const char *str, int n, char delim);

int					printf_write_with_specificator(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hhd(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hd(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_ld(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lld(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_d(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_d(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hho(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_ho(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lo(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_llo(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_o(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_o(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hhu(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hu(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lu(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_llu(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_u(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_u(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hhx(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hx(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lx(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_llx(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_x(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_x(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hhb(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_hb(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lb(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_llb(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_b(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_b(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_c(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_s(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_p(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_f(va_list *params,
		struct s_printf_specificator *spec);

int					printf_write_lf(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_f(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_pr(va_list *params,
		struct s_printf_specificator *spec);

int					printf_cast_default(va_list *params,
		struct s_printf_specificator *spec);

char				*ft_printf_lltoa(long long int n, int leading_zeros,
		int sign);

int					printf_numbers_count(long long int n);

void				printf_toupper(char *pc);

int					printf_bx_leading_zeros(
		struct s_printf_specificator *spec, unsigned long long int x, int base);

void				ft_memswap(void *dest, void *src, void *buffer,
		size_t size);

bool				is_atoi_number(char *str);

char				*skip_atoi_number(char *str);

int					ft_sign(int n);

int					is_atox_digit(char c);

unsigned int		ft_atox(const char *str);

char				*skip_atox_number(char *str);

#endif
