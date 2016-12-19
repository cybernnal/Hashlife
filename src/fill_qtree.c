//
// Created by Tom BILLARD on 12/19/16.
//

#include <hlife.h>

static t_qtree    *fill_r(t_pars *pars, t_hlife x_zero, t_hlife x_max, t_hlife y_zero, t_hlife y_max, t_hlife level)
{
    t_qtree     *qtree;

    qtree = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qtree, sizeof(t_qtree));

    qtree->level = level;

    if (x_max - x_zero == 2)
    {
       // qtree->leaf = pars->map[y][x] ... <- TODO <- keep leaf on uint?
        //TODO hash and store leaf
        return (qtree);
    }

    qtree->nw = fill_r(pars, x_zero, x_max / 2, y_zero, y_max / 2, level + 1);

    qtree->ne = fill_r(pars, x_max / 2, x_max, y_zero, y_max / 2, level + 1);

    qtree->sw = fill_r(pars, x_zero, x_max / 2, y_max / 2, y_max, level + 1);

    qtree->se = fill_r(pars, x_max / 2, x_max, y_max / 2, y_max, level + 1);
    //TODO hash and store node (combin betwen all 4 subnode)
}

void     fill_qtree(t_env *env, t_pars *pars)
{
    t_hlife     side = (env->x_max > env->y_max ? env->x_max : env->y_max);

    side += (side % 2 == 0 ?  2 : 3);
    env->qtree = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(env->qtree, sizeof(t_qtree));
    env->qtree = fill_r(pars, 0, side, 0, side, 0);
}