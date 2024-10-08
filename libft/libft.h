/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:33:48 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:22:58 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include "get_next_line.h"

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0
# define CLEAR " \e[1;H\e[2J"
# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_iswhitespace(char c);
void	ft_replace_white_space(char *line);
void	ft_skip_wspaces(char **ptr);
size_t	ft_strlen(const char *str);
size_t	ft_strssize(char **strs);
long	ft_atol(const char *str);
void	*ft_bzero(char *str, int size);
void	*ft_memset(void *str, int c, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *ptr, size_t len);
char	*ft_strdelspace(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_rstrnstr(char *haystack, char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, const char *base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	**ft_lst_to_strs(t_list *lst);
void	ft_free_strings(char **strs);
void	ft_free_and_null(void *ptr_adrs);
char	**ft_strsdup(char **strs, size_t size);
int		ft_dprintf(int fd, const char *str, ...);
int		print_str_fd(va_list args, int fd);
int		print_n_base10_fd(va_list args, char c, int fd);
char	*ft_utoa(unsigned int n);
int		ft_putnbr_base_fd(size_t nb, char *base, size_t base_len, int fd);
int		print_p_fd(va_list args, int fd);
void	ft_printstrs(char **strs, int fd);
long	ft_strtol(char *str, char **endptr, int base);

#endif
