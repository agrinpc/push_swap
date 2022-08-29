#include "libft.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("txt", O_RDONLY);
	str = "str";
	while (str)
	{
		str = get_next_line(fd);
		ft_printf("%s", str);
	}
}