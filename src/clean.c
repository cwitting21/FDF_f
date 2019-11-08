#include "../includes/fdf.h"

void				clean(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->fd >= 0)
		{
			close(mlx->fd);
			mlx->fd = -1;
		}
		mlx = free_mlx_ptr(&mlx);	
	}
}