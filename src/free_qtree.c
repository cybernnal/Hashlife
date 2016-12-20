//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

void        free_qtree(t_qtree *qtree)
{
    if (qtree->level == 2)
    {
        ft_memdel((void**)&qtree->ne);
        ft_memdel((void**)&qtree->se);
        ft_memdel((void**)&qtree->sw);
        ft_memdel((void**)&qtree->nw);
        ft_memdel((void**)&qtree->next);
        return;
    }
    if (qtree->nw)
        free_qtree(qtree->nw);
    if (qtree->ne)
      free_qtree(qtree->ne);
    if (qtree->sw)
        free_qtree(qtree->sw);
    if (qtree->se)
        free_qtree(qtree->se);

   /* ft_memdel((void**)&qtree->ne);
    ft_memdel((void**)&qtree->se);
    ft_memdel((void**)&qtree->sw);
    ft_memdel((void**)&qtree->nw);
    ft_memdel((void**)&qtree->next);*///TODO keep or del?
    ft_memdel((void**)&qtree);
}