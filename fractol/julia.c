

#include "fractol.h"

int		julia(int x, int y, t_window *win)
{
	t_float	vals[8];
	int		i;
	t_input	*in;

	in = win->input;
	vals[0] = (t_float)in->curposx / (in->resx * 0.5) - 1;
	vals[1] = (t_float)in->curposy / (in->resy * 0.5) - 1;
	vals[2] = ((t_float)x * ((t_float)win->width / (t_float)win->height) -
			win->width * 0.5) * in->zoom + in->posx;
	vals[3] = ((t_float)y - win->height * 0.5) * in->zoom + in->posy;
	i = -1;
	while (++i < in->iters)
	{
		vals[4] = (vals[2] * vals[2] - vals[3] * vals[3]) + vals[0];
		vals[5] = (vals[2] * vals[3] + vals[2] * vals[3]) + vals[1];
		if ((vals[4] * vals[4] + vals[5] * vals[5]) > 4)
			break ;
		vals[2] = vals[4];
		vals[3] = vals[5];
	}
	return (color(i, in->iters, vals, in->option));
}

void	u_julia(t_window *win, void *core)
{
	int x;
	int y;

	y = -1;
	while (++y < win->height)
	{
		x = -1;
		while (++x < win->width)
			win->canvas[y * win->width + x] = julia(x, y, win);
	}
	mlx_put_image_to_window(core, win->id, win->canvasid, 0, 0);
}
