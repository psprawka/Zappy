/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:35:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/22 17:13:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define NORMAL			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGNETA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define PINK			"\033[38;5;200m"
# define ORANGE			"\033[38;5;208m"
# define PURPLE			"\033[38;5;55m"
# define MAROON			"\033[38;5;88m"
# define GREY			"\033[38;5;246m"

long int		ft_atoi(char *s);
char			*ft_ftoa(double n);
char			*ft_itoa(int nbr);
char			*ft_strjoin(char *s1, char *s2, bool sfree);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
void			ft_bzero(void *s, unsigned int n);
char			*ft_strnew(size_t size);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen_chr(char *str, char c);
char			*ft_strncpy(char *str, int size);
int				ft_strstr(char *str, char *to_find);
char			*ft_strncat(char *dest, char *src, size_t nb);
char			*ft_strchr(char *str, char to_find);
char			*ft_strsub(char *s, unsigned int start, size_t len);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

int				ft_wstrlen(wchar_t *ws);
char			*ft_strrev(char *str);
void			*ft_memalloc(size_t size);
char			*ft_convert_hex(unsigned long int nb, int type);
char			*ft_convert_octal(unsigned long int nb);
char			*ft_convert_uni(wchar_t wide);

int				ft_printf(const char *format, ...);
int				gnl(const int fd, char **line);

#endif
