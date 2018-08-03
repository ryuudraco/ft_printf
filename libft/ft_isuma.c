/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:24:42 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 11:06:06 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isuma(char **s)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while ((*s)[i] >= '0' && (*s)[i] <= '9')
	{
		result = result * 10 + (*s)[i] - '0';
		i++;
	}
	(*s) = &(*s)[i];
	return (result);
}
