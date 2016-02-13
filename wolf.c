/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:22:18 by aratinau          #+#    #+#             */
/*   Updated: 2016/02/13 14:36:30 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_wall()
{
	int i;
	i = 0;
	while (i < WIDTH)
	{
		/*
		ft_putstr("ligne ");
		ft_putnbr(i);
		ft_putchar('\n');
		*/
		i++;
	}
}

int		main(void)
{
	t_env			e;
	t_cam			cam;
	cam.hauteur = 0;
	cam.orientation = 0;
	cam.direction = 0;
	cam.fov = 0;
	cam.pos_cam_x = 12;
	cam.pos_cam_y = 12;
	cam.dirX = -1;
	cam.dirY = 0;
	cam.planeX = 0;
	cam.planeY = 0.66;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf3d");

	int map[24][24] = {
	    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	    {1,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,0,0,0,0,2,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

/* ne pas oublier de secure les malloc */

	int nrows = 24;
	int ncolumns = 24;
	int **array;
	array = (int**)malloc(sizeof(int*) * (nrows * ncolumns));
	int i, j;
	i = 0;
	j = 0;
	int k;
	k = 0;
	while (i < nrows)
	{
		j = 0;
		array[i] = (int*)malloc(sizeof(int) * (nrows));
		while (j < ncolumns)
		{
			/*
			ft_putnbr(i);
			ft_putstr(" - ");
			ft_putnbr(j);
			ft_putstr(" : ");
			*/
			array[i][j] = map[i][j];

			/*
			ft_putnbr(map[i][j]);
			ft_putchar(' ');
			*/
			j++;
			k++;
		}
		i++;
	}

	e.map = array;

	i = 0;
	j = 0;
	while (i < nrows)
	{
		j = 0;
		while (j < ncolumns)
		{
			ft_putnbr(array[i][j]);
			ft_putstr(" - ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}

	int		sizeline;
	int		bbp;
	int		endian;

	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);

	e.data = mlx_get_data_addr(e.img, &bbp, &sizeline, &endian);
	e.sizeline = sizeline;
	e.bpp = bbp;
	e.color = 0xffffff;

	e.cam = &cam;


	mlx_key_hook(e.win, key_hook, &e);
	//mlx_mouse_hook(e.win, mouse_hook, &e); // fonction draw la dedans pour eviter l'expose
	//mlx_expose_hook(e.win, expose_hook, &e);

	// TODO : Printer les posX Y et autre de CAM en fonction de notre position et des deplacements avec le clavier
	
//          x  y
//	print_wall();
//	mur(&e);
	//castRays(&e);

 	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
