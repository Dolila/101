/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 01:22:05 by jofayard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/06 03:31:22 by jofayard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include <fcntl.h>

# define BUFF_SIZE 1

typedef struct s_coord s_coord;
struct		s_coord
{
	int				x;
	int				y;
	int				z;
	s_coord			*next;
};


typedef struct s_mem s_mem;
struct		s_mem
{


	s_coord			*first;
};


int		get_next_line(int const fd, char **line);

#endif
