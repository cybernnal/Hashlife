//
// Created by tom billard on 15/12/2016.
//

#include <fcntl.h>
#include <hlife.h>

static void     get_max(t_env *env, char *line)
{
    int i = 0;
    int j = 0;

    while (line[i] && !ft_isdigit(line[i]))
        i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        env->x_max *= 10;
        env->x_max += line[i] - 48;
        i++;
    }
    while (line[i] && !ft_isdigit(line[i]))
        i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        env->y_max *= 10;
        env->y_max += line[i] - 48;
        i++;
    }
    while (line[i] && !ft_isdigit(line[i]))
        i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        env->b[j] = line[i];
        j++;
        i++;
    }
    env->b[j] = '\0';
    j = 0;
    while (line[i] && !ft_isdigit(line[i]))
        i++;
    while (line[i] && ft_isdigit(line[i]))
    {
        env->s[j] = line[i];
        j++;
        i++;
    }
    env->s[j] = '\0';
}

void pars_map(char *argv, t_env *env, t_pars *pars)
{
    int         fd;
    char        *line;
    int         i = 0;
    int         nb = 0;
    int         x = 0;
    int         y = 0;

    if ((fd = open(argv, O_RDONLY)) < 0)
        ft_error("open error");
    while (get_next_line(fd, &line))
    {
        if (!line)
            ft_error("read error");
        if (line[0] != '#')
            break ;
        free(line);
    }
    if (line[0] == 'x')
        get_max(env, line);
    else
        ft_error("map error");
    if (env->x_max <= 0 || env->y_max <= 0)
        ft_error("x/y error");
    pars->map = (char**)ft_memalloc(sizeof(char*) * env->y_max);
    pars->map[y] = (char*)ft_memalloc(sizeof(char) * env->x_max);
    ft_bzero(pars->map[y], (size_t)env->x_max);
    while (get_next_line(fd, &line))
    {
        if (!line)
            ft_error("read error");
        while (line[i])
        {
            if (line[i] == 'b')
            {
                pars->map[y][x] = '0';
                x++;
            }
            else if (line[i] == 'o')
            {
                pars->map[y][x] = '1';
                x++;
            }
            else if (line[i] == '$')
            {
                pars->map[y][x] = '\0';
                x = 0;
                y++;
                pars->map[y] = (char*)ft_memalloc(sizeof(char) * env->x_max);
                ft_bzero(pars->map[y], (size_t)env->x_max);
            }
            else if (ft_isdigit(line[i]))
            {
                while (ft_isdigit(line[i]))
                {
                    nb *= 10;
                    nb += line[i] - 48;
                    i++;
                }
                while (nb > 0)
                {
                    if (line[i] == 'b')
                        pars->map[y][x++] = '0';
                    else if (line[i] == 'o')
                        pars->map[y][x++] = '1';
                    else if (line[i] == '$')
                    {
                        pars->map[y][x] = '\0';
                        x = 0;
                        y++;
                        pars->map[y] = (char*)ft_memalloc(sizeof(char) * env->x_max);
                        ft_bzero(pars->map[y], (size_t)env->x_max);
                    }
                    nb--;
                }
                nb = 0;
            }
            i++;
        }
        i = 0;
        free(line);
    }
    free(line);
    if ((close(fd)) != 0)
        ft_error("close fd error");
}