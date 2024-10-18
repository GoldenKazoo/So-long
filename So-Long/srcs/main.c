/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/18 21:52:58 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h> // pour open()

int	ft_check_arg_fd(int argc, char **argv, t_data *data)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error, to use: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len <= 4 || ft_strncmp(argv[1] + len - 4, ".ber", len) != 0
		|| ft_strncmp(argv[1] + len - 5, "/.ber", len) == 0)
	{
		ft_printf("Error: invalid file\n");
		return (1);
	}
	data -> fd = open(argv[1], O_RDONLY);
	if (data -> fd < 0)
	{
		ft_printf("Error: can't open file");
		return (1);
	}
	return (0);
}

void	ft_check_arg(int argc, char **argv, t_data *data)
{
	if (!data)
		exit (1);
	if (argv[1] == NULL)
	{
		ft_printf("Error, to use: %s <map_file.ber>\n", argv[0]);
		free(data);
		exit (1);
	}
	if (ft_check_arg_fd(argc, argv, data) == 1)
	{
		free(data);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_check_arg(argc, argv, data);
	data->player_tile = malloc(sizeof(t_img));
	data->empty_tile = malloc(sizeof(t_img));
	data->wall_tile = malloc(sizeof(t_img));
	data->obj_tile = malloc(sizeof(t_img));
	data->exit_tile = malloc(sizeof(t_img));
	data = ft_data_init(data, data -> fd);
	if (!data)
		exit(1);
	if (check_map_accessibility(data) == 0)
	{
		ft_close_window(data);
		ft_print_error(10, data);
	}
	if (!data)
	{
		return (1);
	}
	ft_paint_map(data);
	ft_key_hooks(data);
	mlx_hook(data->win, 17, 0, (int (*)())ft_close_window, data);
	mlx_loop(data->mlx);
	ft_free_all(data);
	return (0);
}
