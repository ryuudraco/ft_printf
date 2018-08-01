/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:48 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 00:28:44 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int 	ft_isuma(char **s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_putchar(char c);
int		ft_putstr(char const *s, int pcsn);
int		ft_putwstr(wchar_t *wides, int pcsn);
int		ft_strchr(const char *str, int c);
void	ft_strdel(char **as);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *s);
int		ft_strlenpcsn(const char *s, int pcsn);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif