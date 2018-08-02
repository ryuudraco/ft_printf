/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:30:08 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 12:10:11 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_str(t_char *ract, void *s)
{
	int len;

	ract->slen = (s != NULL) ? ft_strlen((char *)s) : 6;
	len = 0;
	ract->slen = !ract->pcsn ? ract->width : ract->slen;
	if ((ract->flg)[2] == '0')
		(ract->flg)[0] = '0';
	while ((ract->flg)[3] != '-' && ract->width > ract->slen)
		(len += ft_putchar((ract->flg)[0])) && (ract->width)--;
	while ((ract->flg)[3] != '-' && ract->width > ract->pcsn &&
		ract->pcsn != -1 && (ract->slen > ract->pcsn))
		len += ft_putchar((ract->flg)[0]) && ract->width--;
	if (ract->spec == 's' && !ract->l)
		len += ft_putstr((char *)s, ract->pcsn);
	else if (ract->spec == 'S' || (ract->spec == 's' && ract->l))
		len += ft_putwstr((wchar_t *)s, ract->pcsn);
	while ((ract->flg)[3] == '-' && ract->width > ract->slen)
		len += ft_putchar(' ') && ract->width--;
	while ((ract->flg)[3] == '-' && ract->width > ract->pcsn &&
		ract->pcsn != -1 && (ract->slen-- - ract->pcsn))
		len += ft_putchar(' ');
	return (len);
}
