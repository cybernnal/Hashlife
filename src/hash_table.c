//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

t_qtree     *hash_table(t_qtree *q1, t_qtree *q2, t_qtree *q3, t_qtree *q4, t_qtree *node)
{
    static t_table  *table;
    static t_table  *first = NULL;
    static t_hlife  c = 0;
    void            *hash = 0;// TODO = hash(q1, q2, q3, q4); // TODO do hashing function
    t_table         *tmp;

    table = first;
    while (table)
    {
        if (table->hash == hash)
        {
            ft_memdel((void**)&node);
            return (table->pointer);
        }
        table = table->next;
    }
    //TODO push front or push back or sort?
    tmp = (t_table*)ft_memalloc(sizeof(t_table));
    ft_bzero(tmp, sizeof(t_table));
    tmp->pointer = node;
    tmp->hash = hash;
    tmp->next = first;
    first = tmp; // TODO << here push front
    c++;
    return (node);
}