/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:46:15 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:28:40 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hlife.h"

static  t_env        *sig(void)
{
    static t_env env;

    return (&env);
}

int		main(int argc, char  **argv)
{
	t_env	*env;
    int  i = 2;

	if (argc < 1)
		ft_error("too few args");
    env = sig();
    ft_bzero(env, sizeof(t_env));
	return (0);
}
