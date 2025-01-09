#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(int fd, char *solution_buffer);
char	*ft_new_line_finder(char *solution_buffer);
char	*get_next_line(int fd);

int	main(void)
{
	int fd = open("quijote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error while opening the file\n");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Extracted line: %s", line);
		free(line);
	}

	close(fd);
	return (0);
}