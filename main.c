#include<stdio.h> 
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char	*str;

	fd = open("41_with_nl", O_RDONLY);	

	str = "linhalinha";
//		printf("%s", get_next_line(fd));
//		printf("%s", get_next_line(fd));
//		printf("%s", get_next_line(fd));
//		printf("%s", get_next_line(fd));

	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}

	return (0);
}

