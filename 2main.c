/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   2main.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 16:46:36 by jofayard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/06 01:18:02 by jofayard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

void	rectangle(void *mlx_ptr, void *win_ptr)
{
	int		x;
	int		y;

	y = 100;
	x = 100;
	while (x <= 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
		x++;
	}
	while (y <= 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
		y++;
	}
	y = 100;
	x = 100;
	while (y <= 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
		y++;
	}
	while (x <= 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
		x++;
	}
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
	rectangle(mlx_ptr, win_ptr);
	mlx_string_put(mlx_ptr, win_ptr, 800, 800, 0x00FF00, "SALUT");
	mlx_loop(mlx_ptr);

	return(0);
}
