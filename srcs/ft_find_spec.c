/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:07:41 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 09:51:14 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_find_spec(t_char *ract, va_list arg)
{
	int	i;

	i = 0;
	if (ract->spec == '%')
		i = ft_liter(ract, '%');
	else if (ract->spec == 's' || ract->spec == 'S')
		i = ft_str(ract, va_arg(arg, void *));
	else if (ract->spec == 'p')
		i = ft_point(ract, va_arg(arg, void *));
	else if (ract->spec == 'd' || ract->spec == 'D' || ract->spec == 'i')
		i = ft_nbr(ract, va_arg(arg, void *));
	else if (ract->spec == 'o' || ract->spec == 'O')
		i = ft_oct(ract, va_arg(arg, void *));
	else if (ract->spec == 'u' || ract->spec == 'U')
		i = ft_ub(ract, va_arg(arg, void *));
	else if (ract->spec == 'x' || ract->spec == 'X')
		i = ft_hex(ract, va_arg(arg, void *));
	else if (ract->spec == 'c' || ract->spec == 'C')
		i = ft_char(ract, va_arg(arg, void*));
	else
		i = (ft_char(ract, va_arg(arg, void *)));
	ft_strdel(&(ract->flg));
	return (i);
}
