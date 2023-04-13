#include "main.h"
/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */



ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, rd, wr;

	char *buffer;
	
	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	rd = read(fd, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	if (fd == -1 || rd == -1 || wr == -1 || wr != rd)
	{
		free(buffer);
		return(0);
	}

	free(buffer);
	close(fd);

	return(wr);
}




/*ssize_t read_textfile(const char *filename, size_t letters);

int main(void)
{
	ssize_t w, r, o (int fd, void *buf,size_t count);


	if (filename) = NULL
	return (0);

	w (write,O_WRONLY);
	r (read,O_RDONLY);
	O (open,fopen);

	if (o == -1 || r == -1 || w == -1 || w != -1)
		ptintf("w,r,o \n (-1)");

		return (0)


		close(fd)

		return 0;
}*/

