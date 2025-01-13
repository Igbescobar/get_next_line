#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	read_from_file(void)
{
	int		fd;
	char	*line;

	fd = open("quijote.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

void	read_from_stdin(void)
{
	char	*line;

	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		read_from_file();
	}
	else if (argc == 1)
	{
		read_from_stdin();
	}
	return (0);
}