/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   5get_next_line.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 18:18:55 by jofayard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/06 03:32:49 by jofayard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_read(char **str, int fd)
{
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[ret] = '\0';
	tmp = *str;
	*str = ft_strjoin(*str, buff);
	if (*tmp)
		free(tmp);
	return (ret);
}

static int	ft_join_line(char **str, char **line, char *s)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (*s == '\n')
		ret = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (ret == 0 && ft_strlen(*str) != 0)
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (ret == 0 && (ft_strlen(*str) == 0))
		return (0);
	tmp = *str;
	*str = ft_strjoin(s + 1, "");
	free(tmp);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*tmp;
	static char	*str;

	if (str == 0)
		str = "";
	if (line == 0 || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		tmp = str;
		while (*tmp != 0 || ret < BUFF_SIZE)
		{
			if (*tmp == '\n' || *tmp == 0 || *tmp == -1)
				return (ft_join_line(&str, line, tmp));
			tmp++;
		}
		ret = ft_read(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
