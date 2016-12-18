/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:20:11 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 18:23:08 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int		ft_error(char * str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}
