/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:08:28 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 11:08:23 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s, int pcsn)
{
	int		size;
	char	*temp;

	size = 0;
	if (s == NULL)
		return (ft_putstr("(null)", pcsn));
	size = ft_strlenpcsn(s, pcsn);
	temp = (char *)malloc(sizeof(char) * (size + 1));
	ft_strncpy(temp, s, size);
	write(1, temp, size);
	free(temp);
	return (size);
}
