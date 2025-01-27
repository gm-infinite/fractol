/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:20:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/10 16:13:43 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);

# ifndef LIBFTPRINTF_H
#  define LIBFTPRINTF_H

typedef struct s_flags
{
	int		width;
	int		dot_size;
	int		zero_or_space;
	int		after_or_before;
	int		space_plus;
	int		alternative;
	int		type_to_print;
	int		print_length;
}			t_flags;

typedef struct s_trueprint
{
	int		space_before_value;
	char	sign;
	int		zerox;
	int		zero_before_value;
	int		space_after_value;
}			t_trueprint;

typedef struct s_vavalue
{
	int				value_int;
	unsigned int	value_unint;
	void			*value_pointer;
	char			*value_string;
}					t_vavalue;

int		ft_printf(const char *s, ...);

void	ft_flagreset(t_flags *flag);
int		ft_flagsset(const char *s, t_flags *flag);
int		ft_mstrchr(const char *s, char c);
void	ft_trueprintreset(t_trueprint *tp);
void	ft_trueprintset(t_flags *flags, va_list *args, \
t_trueprint *tp, t_vavalue *material);
void	ft_vavaluereset(t_vavalue *vv);
void	ft_vavalueset(t_vavalue *vavalue, va_list *args, t_flags *flags);

int		ft_charsize(char value);
int		ft_stringsize(char *value);
int		ft_deciintsize(int value, t_flags *flags);
int		ft_hexasize(unsigned int value, t_flags *flags);
int		ft_pointersize(void *value);
int		ft_unsintsize(unsigned int value, t_flags *flags);

void	ft_vputstr(char *s, t_flags *flags);
void	ft_vputchar(char c, t_flags *flags);
void	ft_puthexa(unsigned int n, t_flags *flags);
void	ft_puthexau(unsigned int n, t_flags *flags);
void	ft_putunsnbr(unsigned int n, t_flags *flags);
void	ft_putnbr(long n, t_flags *flags);
void	ft_lenputstr(char *s, t_flags *flags, int len);
void	ft_putpointer(void *nb, t_flags *flags);
# endif

#endif