/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   3main.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 01:26:43 by jofayard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/06 04:00:45 by jofayard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

s_mem	*inilst()
{
	s_coord *element;
	s_mem	*liste;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
	if (!(element == NULL || liste == NULL))
		return NULL;
	element->x = 100;
	element->y = 100;
	element->z = 0;
	element->next = NULL;
	liste->first = element;
	return (liste);
}

void	lstadd(s_mem *liste, int x, int y, int z)
{
	s_coord *new;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->x = x;
	new->y = y;
	new->z = z;
	liste->first = new;
}

char	*ft_strcat2(char *dest, char *src)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (dest[size])
		size++;
	while (src[i])
	{
		dest[size] = src[i];
		size++;
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

char	*stock_file(int fd)
{
	char	*line;
	char	*file;
	int		i;
	char	*tmp;

	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(tmp = malloc(sizeof(ft_strlen(file) + 1))))
			return (NULL);
		tmp = file;
		if (!(file = malloc(sizeof(ft_strlen(line) * i + 1))))
			return (NULL);
		file = tmp;
		ft_strcat2(file, line);
		i++;
	}
	return (file);
}



int		main(int ac, char **av)
{
	int		fd;
	char	*file;

	fd = open(av[1], O_RDONLY);
	file = stock_file(fd);
	close(fd);
	ft_putendl(file);
	return (0);
}
