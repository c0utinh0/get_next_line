#include<stdio.h> 
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd, sz;
	char	*str;
	
	str = "line";
	fd = open("lorem_ipsum.txt", O_RDONLY);	
//	while (*str != '\0')
//	{
		str = get_next_line(fd);
		printf("%s", str);
//	}
	return (0);
}

