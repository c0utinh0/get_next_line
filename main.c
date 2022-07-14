#include<stdio.h> 
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd, sz;
	char	*str;
	
	str = "line";
	fd = open("41_with_nl", O_RDONLY);	
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	return (0);
}

