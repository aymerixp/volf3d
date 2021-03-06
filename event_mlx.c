/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:02:56 by aratinau          #+#    #+#             */
/*   Updated: 2016/02/19 17:20:12 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		is_plane(int x, int y, t_env *e)
{
	// je ne sais pas pourquoi x et y doivent etre inverses pour que ca marche
	//ft_putstr("\nle suivant est : ");
	//ft_putnbr(e->map[y][x]);
	if (e->map[y][x] == 0)
		return (1);
	return (0);
}

void	color_str(char *s, char *opt)
{
	ft_putstr("\033[");
	ft_putstr(opt);
	ft_putstr("m");
	while (*s != '\0')
		ft_putchar(*s++);
	ft_putstr("\033[0m");
}

int				key_press_hook(int key_code, t_env *e)
{
	if (key_code == 126) // touche haut // action : AVANCER
		e->control->up = 1;
	if (key_code == 123) // gauche
		e->control->left = 1;
	if (key_code == 124) // droite
		e->control->right = 1;

	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);

	return (0);
}

int				key_release_hook(int key_code, t_env *e)
{
	if (key_code == 53)
		exit (0);

	if (key_code == 126) // touche haut // action : AVANCER
		e->control->up = 0;
	if (key_code == 123) // gauche
		e->control->left = 0;
	if (key_code == 124) // droite
		e->control->right = 0;


	print_cam(e);
	ft_putstr("\n==================================================================\n");
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			if (j == e->cam->pos_cam_x && i == e->cam->pos_cam_y)
				color_str("X", "32");
			else
				ft_putnbr(e->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
ft_putnbr(e->cam->test);
	ft_putstr("\n==================================================================\n");
	return (0);
}

int			loop_hook(t_env *e)
{
	if (e->control->up == 1) // touche haut // action : AVANCER
	{
		if (e->cam->direction == 0)
		{
			// [+x ;  y]
			if (is_plane(e->cam->pos_cam_x + 1, e->cam->pos_cam_y, e))
			{
				e->cam->pos_cam_x++;
			}
		}
		if (e->cam->direction == 45)
		{
			// [+x ; +y]
			if (is_plane(e->cam->pos_cam_x + 1, e->cam->pos_cam_y + 1, e))
			{
				e->cam->pos_cam_x++;
				e->cam->pos_cam_y++;
			}
		}
		if (e->cam->direction == 90)
		{
			// [x ; +y]
			if (is_plane(e->cam->pos_cam_x, e->cam->pos_cam_y + 1, e))
			{
				e->cam->pos_cam_y++;
			}
		}
		if (e->cam->direction == 135)
		{
			// [-x ; +y]
			if (is_plane(e->cam->pos_cam_x - 1, e->cam->pos_cam_y + 1, e))
			{
				e->cam->pos_cam_x--;
				e->cam->pos_cam_y++;
			}
		}
		if (e->cam->direction == 180)
		{
			// [-x ;  y]
			if (is_plane(e->cam->pos_cam_x - 1, e->cam->pos_cam_y, e))
			{
				e->cam->pos_cam_x--;
			}
		}
		if (e->cam->direction == 225)
		{
			// [-x ; -y]
			if (is_plane(e->cam->pos_cam_x - 1, e->cam->pos_cam_y - 1, e))
			{
				e->cam->pos_cam_x--;
				e->cam->pos_cam_y--;
			}
		}
		if (e->cam->direction == 270)
		{
			// [x ; -y]
			if (is_plane(e->cam->pos_cam_x, e->cam->pos_cam_y - 1, e))
			{
				e->cam->pos_cam_y--;
			}
		}
		if (e->cam->direction == 315)
		{
			// [+x ; -y]
			if (is_plane(e->cam->pos_cam_x + 1, e->cam->pos_cam_y - 1, e))
			{
				e->cam->pos_cam_x++;
				e->cam->pos_cam_y--;
			}
		}
	}
	if (e->control->left == 1) // gauche
	{
	if (e->cam->orientation == 0)
			e->cam->orientation = 359;
		else
			e->cam->orientation--;
	}
	if (e->control->right == 1) // droite
	{
		if (e->cam->orientation == 359)
			e->cam->orientation = 0;
		else
			e->cam->orientation++;
	}

	count_dist(e);
	ft_putnbr(e->cam->test);
	cast_rays(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		pixel_put_coord(e, x, y);
	}

	// permet de redessiner
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
