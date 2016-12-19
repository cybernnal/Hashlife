//
// Created by Tom BILLARD on 12/19/16.
//

#include <hlife.h>

void    print_map(t_env *env, t_pars *pars)
{
    int x = 0;
    int y = 0;

    while (y < env->y_max)
    {
        while (pars->map[y][x])
        {
            ft_putchar(pars->map[y][x]);
            ft_putchar(' ');
            x++;
        }
        ft_putendl("");
        x = 0;
        y++;
    }
}