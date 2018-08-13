/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:55:47 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 15:48:10 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void		initializer(t_char *ract)
{
	ract->flg = ft_strdup(" *****");
	ract->width = -1;
	ract->pcsn = -1;
	ract->h = 0;
	ract->hh = 0;
	ract->l = 0;
	ract->ll = 0;
	ract->z = 0;
	ract->j = 0;
}

static void		ft_flg(char **flag, t_char *ract)
{
	if (**flag == '#')
		(ract->flg)[1] = '#';
	else if (**flag == '0')
		(ract->flg)[2] = '0';
	else if (**flag == '-')
		(ract->flg)[3] = '-';
	else if (**flag == '+')
		(ract->flg)[4] = '+';
	else if (**flag == ' ')
		(ract->flg)[5] = ' ';
}

static int		ft_doublecheck(char *form, char c)
{
	int n;

	n = 0;
	while (ft_strchr(IND, *form))
	{
		if (*form == c)
			n++;
		form++;
	}
	if (n % 2 == 0)
		return (1);
	else
		return (0);
}

static void		ft_conversion(char **form, t_char *ract)
{
	if (**form == 'h' && !(ract->h) && !(ract->hh))
	{
		if (ft_doublecheck(*form, 'h'))
			ract->hh = 1;
		else
			ract->h = 1;
	}
	if (**form == 'l' && !(ract->l) && !(ract->ll))
	{
		if (ft_doublecheck(*form, 'l'))
			ract->ll = 1;
		else
			ract->l = 1;
	}
	if (**form == 'z')
		ract->z = 1;
	if (**form == 'j')
		ract->j = 1;
}

int				ft_format(char **form, va_list arg)
{
	t_char ract;

	initializer(&ract);
	while ((ft_strchr(IND, **form)))
	{
		(ft_strchr(FLAGS, **form)) ? ft_flg(form, &ract) : 0;
		if (ft_strchr("123456789", **form))
		{
			ract.width = ft_isuma(form);
			continue ;
		}
		if (**form == '.' && (*form)++)
		{
			ract.pcsn = ft_isuma(form);
			continue ;
		}
		(ft_strchr(CFLAGS, **form)) ? ft_conversion(form, &ract) : 0;
		(*form)++;
	}
	if (ft_strchr(SPECS, **form))
		ract.spec = **form;
	else
		ract.spec = **form;
	return (ft_find_spec(&ract, arg));
}
