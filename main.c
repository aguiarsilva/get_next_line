
#include "get_next_line.h" //malloc(ft_calloc) and read functions
#include <fcntl.h>         //open function
#include <stdio.h>         //printf function

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("lines_around_10.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening File!");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(3);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]: %s\n", count, next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}
