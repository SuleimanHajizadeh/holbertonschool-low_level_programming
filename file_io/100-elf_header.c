#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * err_98 - executing when error occurs
 *
 * Return: void
 */
void err_98(void)
{
	dprintf(STDERR_FILENO, "Error\n");
	exit(98);
}

/**
 * print_magic - prints the ELF magic numbers
 * @e_ident: pointer to an array containing the ELF magic numbers
 *
 * Return: void
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
}

/**
 * get_osabi - retrieves a string describing the ELF OS/ABI
 * @o: the OS/ABI identifier
 *
 * Return: string describing the OS/ABI
 */
const char *get_osabi(unsigned char o)
{
	switch (o)
	{
	case ELFOSABI_SYSV:     return "UNIX - System V";
	case ELFOSABI_LINUX:    return "UNIX - Linux";
	case ELFOSABI_FREEBSD:  return "UNIX - FreeBSD";
	case ELFOSABI_NETBSD:   return "UNIX - NetBSD";
	default:                return "<unknown>";
	}
}

/**
 * get_type - retrieves a string describing the ELF file type
 * @t: the type identifier
 *
 * Return: string describing the file type
 */
const char *get_type(uint16_t t)
{
	switch (t)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL:  return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN:  return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default:      return "<unknown>";
	}
}

/**
 * main - Entry point
 * @argc: count of argv
 * @argv: arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		err_98();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_98();

	read(fd, &header, sizeof(header));
	close(fd);
	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
	header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
		err_98();
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	printf("  Class:                             ELF%d\n",
			header.e_ident[EI_CLASS] * 32);
	printf("  Data:                              %s\n",
		header.e_ident[EI_DATA] == 1 ? "2's complement, little endian"
		: "2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			get_osabi(header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header.e_ident[EI_OSABI]);
	printf("  Type:                              %s\n", get_type(header.e_type));
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)header.e_entry);
	return (0);
}
