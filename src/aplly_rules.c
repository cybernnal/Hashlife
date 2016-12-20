//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

static int      count_hit_nw(t_qtree *qtree)
{
    int hit = 0;

    hit += qtree->nw->nw->leaf;
    hit += qtree->nw->ne->leaf;
    hit += qtree->nw->sw->leaf;
    hit += qtree->ne->nw->leaf;
    hit += qtree->ne->sw->leaf;
    hit += qtree->sw->nw->leaf;
    hit += qtree->sw->se->leaf;
    hit += qtree->se->nw->leaf;
    return (hit);
}
static int      count_hit_ne(t_qtree *qtree)
{
    int hit = 0;

    hit += qtree->nw->ne->leaf;
    hit += qtree->nw->se->leaf;
    hit += qtree->ne->nw->leaf;
    hit += qtree->ne->ne->leaf;
    hit += qtree->ne->se->leaf;
    hit += qtree->sw->se->leaf;
    hit += qtree->se->nw->leaf;
    hit += qtree->se->ne->leaf;
    return (hit);
}
static int      count_hit_sw(t_qtree *qtree)
{
    int hit = 0;

    hit += qtree->nw->sw->leaf;
    hit += qtree->nw->se->leaf;
    hit += qtree->ne->sw->leaf;
    hit += qtree->sw->nw->leaf;
    hit += qtree->sw->sw->leaf;
    hit += qtree->sw->se->leaf;
    hit += qtree->se->nw->leaf;
    hit += qtree->se->sw->leaf;
    return (hit);
}
static int      count_hit_se(t_qtree *qtree)
{
    int hit = 0;

    hit += qtree->nw->se->leaf;
    hit += qtree->ne->sw->leaf;
    hit += qtree->ne->se->leaf;
    hit += qtree->sw->ne->leaf;
    hit += qtree->sw->se->leaf;
    hit += qtree->se->ne->leaf;
    hit += qtree->se->sw->leaf;
    hit += qtree->se->se->leaf;
    return (hit);
}

t_qtree      *apply_rules(t_qtree *node, t_env *env)
{
    t_qtree     *qret;

    qret = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret, sizeof(t_qtree));
    qret->nw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->nw, sizeof(t_qtree));
    qret->ne = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->ne, sizeof(t_qtree));
    qret->sw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->sw, sizeof(t_qtree));
    qret->se = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->se, sizeof(t_qtree));
    if ((node->nw->se->leaf == 0 && ft_strchr(env->b, count_hit_nw(node) + 48)) || (node->nw->se->leaf == 1 && ft_strchr(env->s, count_hit_nw(node) + 48)))// TODO try if it's good
        qret->nw->leaf = 1;
    if ((node->ne->sw->leaf == 0 && ft_strchr(env->b, count_hit_ne(node) + 48)) || (node->ne->sw->leaf == 1 && ft_strchr(env->s, count_hit_ne(node) + 48)))
        qret->ne->leaf = 1;
    if ((node->sw->ne->leaf == 0 && ft_strchr(env->b, count_hit_sw(node) + 48)) || (node->sw->ne->leaf == 1 && ft_strchr(env->s, count_hit_sw(node) + 48)))
        qret->sw->leaf = 1;
    if ((node->se->nw->leaf == 0 && ft_strchr(env->b, count_hit_se(node) + 48)) || (node->se->nw->leaf == 1 && ft_strchr(env->s, count_hit_se(node) + 48)))
        qret->nw->leaf = 1;
    qret->level = 1;
    return (qret); //TODO hash now? !
}