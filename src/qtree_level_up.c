//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>


static t_qtree         *init_r_qempty(t_hlife level)
{
    t_qtree *qtree;

    qtree = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qtree, sizeof(t_qtree));
    qtree->level = level;
    if (level == 0)
        return (qtree);
    qtree->nw = init_r_qempty(level - 1);
    qtree->ne = init_r_qempty(level - 1);
    qtree->sw = init_r_qempty(level - 1);
    qtree->se = init_r_qempty(level - 1);
    return (hash_table(qtree->nw, qtree->ne, qtree->sw, qtree->se, qtree));
}

static t_qtree         *get_empty_node(t_hlife level)
{
     t_qtree      *qempty = NULL;// TODO non static refait a chaque fois pas bon !!!!!!!!!!!!!!!
    static t_hlife      exlvl;

    if (!qempty && (exlvl = level))
       return ((qempty = init_r_qempty(level)));
    if (level == qempty->level && (exlvl = level))
        return (qempty);
    if (level == qempty->nw->level && (exlvl = level))
        return (qempty->nw);
    if (level == qempty->level + 1)
    {
        t_qtree *tmp;
        tmp = (t_qtree*)ft_memalloc(sizeof(t_qtree));
        ft_bzero(tmp, sizeof(t_qtree));
        tmp->nw = qempty;
        tmp->ne = qempty;
        tmp->sw = qempty;
        tmp->se = qempty;
        tmp->level = level;
        exlvl = level;
        return (hash_table(tmp->nw, tmp->ne, tmp->sw, tmp->se, tmp));
    }
    printf("error level: %lli, exlvl: %lli, qempty lvl : %lli \n", level, exlvl, qempty->level);
    return (t_qtree *)(ft_error("creat empty error"));
}

t_qtree     *qtree_lvl_up(t_qtree *qtree)
{
    t_qtree *qret;

  /*  qret = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret, sizeof(t_qtree));
    qret->ne = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->ne, sizeof(t_qtree));
    qret->nw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->nw, sizeof(t_qtree));
    qret->se = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->se, sizeof(t_qtree));
    qret->sw = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret->sw, sizeof(t_qtree));*/

 /*   qret->level = qtree->level + 1;

    qret->nw = get_empty_node(qret->level - 1);
//    qret->nw->ne = get_empty_node(qret->level - 2);
//    qret->nw->sw = get_empty_node(qret->level - 2);
    qret->ne = get_empty_node(qret->level - 1);
//    qret->ne->ne = get_empty_node(qret->level - 2);
//    qret->ne->se = get_empty_node(qret->level - 2);
    qret->sw = get_empty_node(qret->level - 1);
//    qret->sw->sw = get_empty_node(qret->level - 2);
//    qret->sw->se = get_empty_node(qret->level - 2);
    qret->se = get_empty_node(qret->level - 1);
//    qret->se->se = get_empty_node(qret->level - 2);
//    qret->se->sw = get_empty_node(qret->level - 2);*/
    qret = get_empty_node(qtree->level + 1);
    //TODO qret->nw->nw, ne, sw = pointer to empty pattern from hash table
    //TODO qret->ne->nw, ne, se = pointer to empty pattern from hash table
    //TODO qret->sw->nw, sw, se = pointer to empty pattern from hash table
    //TODO qret->se->ne, se, sw = pointer to empty pattern from hash table
    qret->nw->se = qtree->nw;
    qret->ne->sw = qtree->ne;
    qret->sw->ne = qtree->sw;
    qret->se->nw = qtree->se;
    qret->nw->level = qtree->level;
    qret->sw->level = qtree->level;
    qret->ne->level = qtree->level;
    qret->se->level = qtree->level;
    //TODO hash all quadrant: the 4 subnode + current new node
    return (hash_table(qret->nw, qret->ne, qret->sw, qret->se, qret));
}