

#include "fractol.h"

void	ft_err(char *str)
{
	ft_putendl("error:");
	ft_putendl(str);
	exit(1);
}

void	ft_help(void)
{
	ft_putendl("help:");
	ft_putendl("./fractol [-h] [-res x y] [mandelbrot] [julia] [burningship]");
	ft_putendl("available fractals:");
	ft_putendl("- mandelbrot");
	ft_putendl("- julia");
	ft_putendl("- burningship");
}
