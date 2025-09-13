#include "main.h"

/**
 * error_exit - prints an error message to stderr and exits with a code
 * @code: exit status
 * @msg: format string for error message
 * @filename: file name related to the error
 */
void error_exit(int code, const char *msg, const char *filename)
{
	dprintf(STDERR_FILENO, msg, filename);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exit with error codes
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while (1)
	{
		r = read(fd_from, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}
		if (r == 0)
			break;

		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %s\n", argv[1]);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %s\n", argv[2]);

	return (0);
}
