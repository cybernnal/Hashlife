//
// Created by Tom BILLARD on 12/19/16.
//

#include <hlife.h>

static t_hlife        two_pow(t_hlife nb)
{
    t_hlife pow = 1;

    while (pow <= nb)
        pow *= 2;
    return (pow);
}

static int      get_pow_two(int nb)
{
    int i = 0;

    while (nb)
    {
        nb /= 2;
        i++;
    }
    return (i);
}

static t_qtree    *fill_r(t_env *env, t_pars *pars, t_hlife x_zero, t_hlife x_max, t_hlife y_zero, t_hlife y_max, t_hlife level)
{
    t_qtree     *qtree;

    qtree = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qtree, sizeof(t_qtree));

    qtree->level = level;

    if (level == 0)
    {
        x_zero = x_zero - pars->x_zero;
        y_zero = y_zero - pars->y_zero;
        /*qtree->nw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
        ft_bzero(qtree->nw, sizeof(t_qtree));
        qtree->ne = (t_qtree*)ft_memalloc(sizeof(t_qtree));
        ft_bzero(qtree->ne, sizeof(t_qtree));
        qtree->sw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
        ft_bzero(qtree->sw, sizeof(t_qtree));
        qtree->se = (t_qtree*)ft_memalloc(sizeof(t_qtree));
        ft_bzero(qtree->se, sizeof(t_qtree));*/

        if (x_zero >= 0 && x_zero < env->x_max && y_zero >= 0 && y_zero < env->y_max && pars->map[(int)y_zero][(int)x_zero] == '1') // TODO  if seems good
            qtree->leaf = 1;
     /*   if (x_zero + 1 >= 0 && x_zero + 1 < env->x_max && y_zero >= 0 && y_zero < env->y_max && pars->map[y_zero][x_zero + 1] == '1')
            qtree->ne->leaf = 1;
        if (x_zero >= 0 && x_zero < env->x_max && y_zero + 1 >= 0 && y_zero + 1 < env->y_max && pars->map[y_zero + 1][x_zero] == '1')
            qtree->sw->leaf = 1;
        if (x_zero + 1 >= 0 && x_zero + 1 < env->x_max && y_zero + 1 >= 0 && y_zero + 1 < env->y_max && pars->map[y_zero + 1][x_zero + 1] == '1')
            qtree->se->leaf = 1;*/
        // TODO check if it's good ^ ^ ^ ^ ^ ^ ^ ^ ^
        // TODO leaf: hash if hash exist link pointer else store // hash : combin  all 4 t_leaf* (pointer) apply mod
        // TODO remove pointer on leaf or hash it and store leaf as 0 : 1 and all pointer on only 2 boolean?
        return (hash_table(qtree->nw, qtree->ne, qtree->sw, qtree->se, qtree));
    }

    qtree->nw = fill_r(env, pars, x_zero, x_zero + ((x_max - x_zero) / 2), y_zero, y_zero + ((y_max - y_zero) / 2), level - 1); //TODO x/y is good?

    qtree->ne = fill_r(env, pars, x_zero + ((x_max - x_zero) / 2), x_max, y_zero, y_zero + ((y_max - y_zero) / 2), level - 1);

    qtree->sw = fill_r(env, pars, x_zero, x_zero + ((x_max - x_zero) / 2), y_zero + ((y_max - y_zero) / 2), y_max, level - 1);

    qtree->se = fill_r(env, pars, x_zero + ((x_max - x_zero) / 2), x_max, y_zero + ((y_max - y_zero) / 2), y_max, level - 1);
    //TODO  node : hash if hash exist link pointer else store // hash : combin  all 4 subnode* (pointer) apply mod
    return (hash_table(qtree->nw, qtree->ne, qtree->sw, qtree->se, qtree));
}

void     fill_qtree(t_env *env, t_pars *pars) // TODO check all func if there'r good
{
    t_hlife     side = (env->x_max > env->y_max ? env->x_max : env->y_max);

    side = two_pow(side);

    pars->x_zero = (side - pars->x_max) / 2;
    pars->y_zero = (side - pars->y_max) / 2;
    pars->x_max = side - pars->x_zero;
    pars->y_max = side - pars->y_max;

    env->qtree = fill_r(env, pars, 0, side, 0, side, get_pow_two((int)side) - 1);
}