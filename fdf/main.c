/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 14:00:37 by jofayard     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/09 16:29:58 by jofayard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include "libft.h"

/*void	ft_putchar(char c)
  {
  write(1, &c, 1);
  }*/

int	deal_key(int key, void *param)
{
	ft_putendl("ceci est un test");
	ft_putnbr_endl(key);
	return (0);
}

/*void	ligne(int xi, int yi, int xf, int yf)
  {
  int	dx;
  int dy;
  int cumul;
  int x;
  int y;

  dx = xf - xi;
  dy = yf - yi;
  allume_pixel(x, y);
  cumul = dx / 2;
  x = xi + 1;
  while (x <= xf)
  {
  cumul = cumul + dx;
  x++;
  if (cumul >= dx)
  {
  cumul = cumul - dx;
  y++;
  }
  allume_pixel (x,y);
  }
  }*/



int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		j;
	int		xa = atoi(av[1]);
	int		ya = atoi(av[2]);
	int		xb = atoi(av[3]);
	int		yb = atoi(av[4]);
	int		x;
	int		y = ya;
	int		dx = xb - xa;
	int		dy = yb - ya;
	int		incrE = 2 * dy;
	int		incrNE = 2 * (dy - dx);
	int		e = 2 * dy - dx;

	j = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");

	/*	while (j < 300)
		{	
		mlx_pixel_put (mlx_ptr, win_ptr, j, 50, 0xFF0000);
		mlx_pixel_put (mlx_ptr, win_ptr, j, 450, 0xFFFF00);
		j++;
		}
		mlx_key_hook(win_ptr, deal_key, (void *)0);*/
	x = xa;
	while (x <= xb)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
		if (e >= 0)
		{
			y = y + 1;
			e = e + incrNE;
		}
		else
			e = e + incrE;
		x++;
	}
	mlx_loop(mlx_ptr);
	return(0);
}


