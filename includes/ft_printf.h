/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:09:20 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 15:46:33 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(n) ((n < 0) ? -n : n)

# define IND	"+-#0 .123456789hljz"

typedef struct	s_char
{
	char	*flg;
	short	width;
	short	pcsn;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		z;
	int		j;
	char	spec;
	short	slen;
}				t_char;

# define SPECS	"%sSpdDioOuUxXcC"

/*
** s		: String of characters
** S		: Wide Character String
** p      : Pointer address
** d or i : Signed decimal integer
** D		: Long Long MAAAAAN
** o 		: Signed octal
** O		: Long octal
** u		: Unsigned decimal integer
** U		: Long Long MAAAAAN
** x      : Unsigned hexadecimal integer
** X      : Unsigned hexadecimal integer (upper)
** c or C : Character
*/

# define FLAGS	"#0-+ "

/*
** HASH  : Used with o, x or X specifiers the value is preceeded with
**          0, 0x or 0X respectively for values different than zero.
**          By default, if no digits follow, no decimal point is written.
** ZERO  : Left-pads the number with zeroes (0) instead of spaces
**          when padding is specified
** MINUS : Left-justify within the given field width;
**          Right justification is the default
** SPACE : If no sign is going to be written, a blank space is inserted
**          before the value.
** PLUS  : Forces to preceed the result with a plus or minus sign (+ or -),
**          even for positive numbers. By default, only negative numbers are
**          preceded with a minus (-) sign.
*/

# define CFLAGS	"hljz"

/*
** Modifies the length of the data type.
** The following chart shows the types used to interpret the corresponding
** specifier with and without the length specifier.
**
** length  | d i           | u o O x X             | c      | s        | p
** -----------------------------------------------------------------------------
** (none)  | int           | unsigned int           | int    | char*    | void*
** hh      | signed char   | unsigned char          |        |          |
** h       | short int     | unsigned short int     |        |          |
** l       | long int      | unsigned long int      | wint_t | wchar_t* |
** ll      | long long int | unsigned long long int |        |          |
** j       | intmax_t      | uintmax_t              |        |          |
** z       | size_t        | size_t                 |        |          |
*/

int				ft_char(t_char *ract, void *c);
int				ft_find_spec(t_char *ract, va_list arg);
int				ft_format(char **form, va_list arg);
int				ft_hex(t_char *ract, void *n);
int				ft_liter(t_char *ract, char c);
int				ft_nbr(t_char *ract, void *n);
int				ft_oct(t_char *ract, void *n);
int				ft_point(t_char *ract, void *n);
int				ft_printf(const char *format, ...);
int				ft_str(t_char *ract, void *s);
int				ft_ub(t_char *ract, void *n);

#endif
