//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

t_qtree             *new_node(t_qtree *nw, t_qtree *ne, t_qtree *sw, t_qtree *se)
{
    t_qtree     *qret;

    qret = (t_qtree*)ft_memalloc(sizeof(t_qtree));
    ft_bzero(qret, sizeof(t_qtree));
    qret->nw = nw;
    qret->ne = ne;
    qret->sw = sw;
    qret->se = se;
    qret->level = nw->level + 1;
    // TODO hash and if node just created exist return free and return pointer from hash tab
    // TODO else store in hash table and return it
    return (qret);
}

t_qtree             *r_on_horizon(t_qtree *w, t_qtree *e, t_env *env)
{
    return (get_next_gen(new_node(w->ne, e->nw, w->se, e->sw), env));
}

t_qtree             *r_on_vertical(t_qtree *n, t_qtree *s, t_env *env)
{
    return (get_next_gen(new_node(n->sw, n->se, s->nw, s->ne), env));
}

t_qtree             *r_on_midle(t_qtree *nw, t_qtree *ne, t_qtree *sw, t_qtree *se, t_env *env)
{
    return (get_next_gen(new_node(nw->se, ne->sw, sw->ne, se->nw), env));
}

t_qtree             *get_next_gen(t_qtree *qtree, t_env *env)
{
    t_qtree     *n00;
    t_qtree     *n01;
    t_qtree     *n02;
    t_qtree     *n10;
    t_qtree     *n11;
    t_qtree     *n12;
    t_qtree     *n20;
    t_qtree     *n21;
    t_qtree     *n22;
    t_qtree     *qtmp1;
    t_qtree     *qtmp2;
    t_qtree     *qtmp3;
    t_qtree     *qtmp4;

    if (qtree->next)
        return (qtree->next);
    if (qtree->level == 2)
        return ((qtree->next = apply_rules(qtree, env)));//TODO hash here or in aplyy rules func

    n00 = get_next_gen(qtree->nw, env);
    n01 = r_on_horizon(qtree->nw, qtree->ne, env);//TODO skip one level (2)>> ?? fixed??
    n02 = get_next_gen(qtree->ne, env);
    n10 = r_on_vertical(qtree->nw, qtree->sw, env);
    n11 = r_on_midle(qtree->nw, qtree->ne, qtree->sw, qtree->se, env);
    n12 = r_on_vertical(qtree->ne, qtree->se, env);
    n20 = get_next_gen(qtree->sw, env);
    n21 = r_on_horizon(qtree->sw, qtree->se, env);
    n22 = get_next_gen(qtree->se, env);

    qtmp1 = get_next_gen(new_node(n00, n01, n10, n11), env);
    qtmp2 = get_next_gen(new_node(n01, n02, n11, n12), env);
    qtmp3 = get_next_gen(new_node(n10, n11, n20, n21), env);
    qtmp4 = get_next_gen(new_node(n11, n12, n21, n22), env);
/*
    qtmp1 = new_node(n00, n01, n10, n11);
    qtmp2 = new_node(n01, n02, n11, n12);
    qtmp3 = new_node(n10, n11, n20, n21);
    qtmp4 = new_node(n11, n12, n21, n22);*/
    return ((qtree->next = new_node(qtmp1, qtmp2, qtmp3, qtmp4)));
}