//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

t_qtree     *qtree_lvl_up(t_qtree *qtree)
{
    t_qtree *qret;

    qret = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret, sizeof(t_qtree));
    qret->ne = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->ne, sizeof(t_qtree));
    qret->nw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->nw, sizeof(t_qtree));
    qret->se = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->se, sizeof(t_qtree));
    qret->sw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->sw, sizeof(t_qtree));
    //TODO qret->nw->nw, ne, sw = pointer to empty pattern from hash table
    //TODO qret->ne->nw, ne, se = pointer to empty pattern from hash table
    //TODO qret->sw->nw, sw, se = pointer to empty pattern from hash table
    //TODO qret->nw->ne, se, sw = pointer to empty pattern from hash table
    qret->nw->se = qtree->nw;
    qret->ne->sw = qtree->ne;
    qret->sw->ne = qtree->sw;
    qret->se->nw = qtree->se;
    qret->nw->level = qtree->level + 1;
    qret->sw->level = qtree->level + 1;
    qret->ne->level = qtree->level + 1;
    qret->se->level = qtree->level + 1;
    qret->level = qtree->level + 2;
    //TODO hash all quadrant: the 4 subnode + current new node
    return (qret);
}