//
// Created by tom billard on 20/12/2016.
//

#include <hlife.h>

//typedef long long int   t_hash;

t_hash         hash_it(t_qtree *a, t_qtree *b, t_qtree *c, t_qtree *d)
{
    t_hash t = (t_hash)a + (t_hash)b + (t_hash)c + (t_hash)d;
    char *str = (char*)&t;
    t_hash hash = 5381;
    t_hash cc;

    while ((cc = *str++))
        hash = ((hash << 5) + hash) + cc; /* hash * 33 + c */
    return (hash);
}

//    return (((int)a ^ (int)b) ^ ((int)c ^ (int)d));

t_qtree     *hash_table(t_qtree *q1, t_qtree *q2, t_qtree *q3, t_qtree *q4, t_qtree *node)
{
    return (node);
    static t_table  *table;
    static t_table  *first = NULL;
    static t_hlife  c = 0;
    t_hash           hash = hash_it(q1, q2, q3, q4);// TODO = hash(q1, q2, q3, q4); // TODO do hashing function // what type of data
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