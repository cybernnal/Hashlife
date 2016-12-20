//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

void        r_print(t_qtree *qtree, t_hlife x_zero, t_hlife x_max, t_hlife y_zero, t_hlife y_max, t_pars *pars)
{
    if (qtree->level == 0)
    {
        pars->map[(int)y_zero][(int)x_zero] = qtree->leaf;
        return ;
    }

    r_print(qtree->nw, x_zero, x_zero + ((x_max - x_zero) / 2), y_zero, y_zero + ((y_max - y_zero) / 2), pars); //TODO x/y is good?

    r_print(qtree->ne, x_zero + ((x_max - x_zero) / 2), x_max, y_zero, y_zero + ((y_max - y_zero) / 2), pars);

    r_print(qtree->sw, x_zero, x_zero + ((x_max - x_zero) / 2), y_zero + ((y_max - y_zero) / 2), y_max, pars);

    r_print(qtree->se, x_zero + ((x_max - x_zero) / 2), x_max, y_zero + ((y_max - y_zero) / 2), y_max, pars);

}

void        print_qtree(t_qtree *qtree)
{
    char **tab;
    int i = 0;
    int max = (int)pow(2, qtree->level);
    t_pars  pars;

    tab = (char**)ft_memalloc(sizeof(char*) * max);
    while (i < max)
        tab[i++] = (char*)ft_memalloc(sizeof(char) * max);
    pars.map = tab;
   r_print(qtree, 0, max, 0, max, &pars);
    i = 0;
    int j = 0;
    while (i < max)
    {
        while (j < max)
        {
            ft_putnbr(pars.map[i][j]);
            ft_putchar(' ');
            j++;
        }
        j = 0;
        ft_putendl("");
        i++;
    }
}