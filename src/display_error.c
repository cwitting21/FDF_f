#include "../includes/fdf.h"

t_mlx				*display_error(t_mlx *mlx, int mode)
{
	
	if (mode == 0)
		return (0);
	else if (mode == 1)
		ft_putendl("\e[35;1mUsage: ./fdf <map> <mode( \"0\" or \"1\" )>\n\n\
		\t|a11 .. a1j .. a1n|\n\
		\t|... .. ... .. ...|\n\
		\t|ai1 .. aij .. ain| - valid type of map [m x n]\n\
		\t|... .. ... .. ...|\n\
		\t|am1 .. amj .. amn|\n\n\
		\tmode 0: planimetric projection\n\
		\tmode 1: isometric projection\033[0m");
	else if (mode == 2)
		ft_putendl("\e[31mALLOC ERROR\033[0m");
	else if (mode == 3)
		ft_putendl("\e[31mREADING ERROR\033[0m");
	else if (mode == 4)
		ft_putendl("\e[31mINCORRECT MODE\033[0m");
	else if (mode == 5)
		ft_putendl("\e[31mINVALID MAP\033[0m");
	clean(mlx);
	return (NULL);
}