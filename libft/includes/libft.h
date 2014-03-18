/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:01:21 by apetit            #+#    #+#             */
/*   Updated: 2014/02/07 20:26:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1
# define OCTAL_BASE "01234567"
# define HEXA_BASE_MIN "0123456789abcdef"
# define HEXA_BASE_CAP "0123456789ABCDEF"

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_node
{
	void			*data;
	size_t			data_size;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlist
{
	size_t			lenght;
	struct s_node	*head;
	struct s_node	*tail;
}					t_dlist;

void	*ft_memset(void *b, int c, size_t n);
void	ft_bzero(void *b, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *dest, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void* s1, const void* s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));

void	*ft_realloc(void *ptr, int size, int type_size);
void	ft_putnbr_base(unsigned int nb, char *base);
char	*ft_strrev(char *str);
int		ft_abs(int nb);
int		get_next_line(int const fd, char ** line);
int		ft_is_int(char const *str);
void	ft_putnbr_uint(unsigned int n);
void	ft_lstswap(t_list **lst_a, t_list **lst_b);
void	ft_lstdelfirst(t_list **alst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstgetlast(t_list *lst);
int		ft_printf(const char *format, ...);

/* Doubly Linked List */
t_dlist	*ft_dlst_new(void);
t_dlist	*ft_dlst_append(t_dlist *dlist, void *data, size_t data_size);
t_dlist	*ft_dlst_prepend(t_dlist *dlist, void *data, int data_size);
t_dlist	*ft_dlst_insert(t_dlist *dlist, void *data, int data_size, int pos);
void	ft_dlst_del(t_dlist **dlist);
size_t	ft_dlst_len(t_dlist *dlist);

char	*ft_strtolower(char *str);
char	*ft_strtoupper(char *str);
char	*ft_strdel_double_sp(char *str);
int		ft_isspace(int c);
char	*ft_strdup_tabtosp(const char *str);
char	*ft_strdup_delchar(char *str, int c);
char	**ft_chartab2inc(char **tab);
int		power(int nbr, int power);

#endif
