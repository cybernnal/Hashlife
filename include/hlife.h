/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:40:53 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:13:54 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include "../libft/libft.h"
#include <errno.h>
#include <stdbool.h>
#include <SDL_types.h>

/*#define WIN_X   1375
#define WIN_Y   1375

# define L_C(X, x1, x2, y1, y2) ((int)(((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)
# define L_CF(X, x1, x2, y1, y2) ((float)(((float)((X - x1) * (y2 - y1))) / (float)(x2 - x1)) + y1)

#define WHITE   (Uint32) ((255 << 16) + (255 << 8) + 255)
#define RED     (Uint32) ((255 << 16) + (0 << 8) + 0)
#define GREEN   (Uint32) ((0 << 16) + (255 << 8) + 0)
#define BLEU    (Uint32) ((0 << 16) + (0 << 8) + 255)
#define PURPUL  (Uint32) ((108 << 16) + (2 << 8) + 119)
#define ORANGE  (Uint32) ((250 << 16) + (164 << 8) + 1)
#define MAGENTA (Uint32) ((255 << 16) + (0 << 8) + 255)
#define CYAN    (Uint32) ((0 << 16) + (255 << 8) + 255)
#define BROWN   (Uint32) ((139 << 16) + (69 << 8) + 19)
*/

/*
typedef struct              s_window
{
    SDL_Window              *window;
    SDL_Event               event;
    SDL_Renderer            *renderer;
    SDL_Texture             *image;
    Uint32                  *img_ptr;
    int                     is_init;
}                           t_window;

typedef struct      		s_tab
{
    int            			tab[4];
    int            			intput;
    int            			output;
    struct s_tab   			*next;
}                   		t_tab;
*/

typedef float 				t_hlife;
typedef bool               t_leaf;

typedef struct 				s_qtree
{
    struct s_qtree          *nw;
    struct s_qtree          *ne;
    struct s_qtree          *sw;
    struct s_qtree          *se;
    struct s_qtree          *next;
    t_leaf                  leaf;
    t_hlife                 level;
}                           t_qtree;

typedef struct              s_pars
{
    t_hlife 				x_max;
    t_hlife 				y_max;
    t_hlife 				x_zero;
    t_hlife 				y_zero;
    char                    **map;
}                           t_pars;

typedef struct				s_env
{
	t_hlife 				x_max;
    t_hlife 				y_max;
    char                    b[10];
    char                    s[10];
	t_qtree			        *qtree;//TODO keep here??
}							t_env;

typedef struct              s_table
{
    void                    *hash;
    t_qtree                 *pointer;
    struct s_table          *next;
}                           t_table;

void        				print_qtree(t_qtree *qtree);
t_qtree                     *get_next_gen(t_qtree *qtree, t_env *env);
t_qtree                     *apply_rules(t_qtree *node, t_env *env); // aplly rule on leaf
t_qtree                     *qtree_lvl_up(t_qtree *qtree);//add a lvl to the qtree
void                        free_qtree(t_qtree *qtree);
void                        pars_map(char *argv, t_env *env, t_pars *pars);//pars .rle file to 2d array
int							ft_error(char *str);
void 					    print_map(t_env *env, t_pars *pars);// print 2d array
void 		    			fill_qtree(t_env *env, t_pars *pars);// fill new qtree with map just parsed

#endif