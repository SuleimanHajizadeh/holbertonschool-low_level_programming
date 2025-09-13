/*
 * File: 100-elf_header.c
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_magic - prints the ELF magic bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
}

/**
 * get_osabi - returns string for OS/ABI
 */
const char *get_osabi(unsigned char o)
{
	switch (o)
	{
	case ELFOSABI_SYSV: return "UNIX - System V";
	case ELFOSABI_HPUX: return "UNIX - HP-UX";
	case ELFOSABI_NETBSD: return "UNIX - NetBSD";
	case ELFOSABI_LINUX: return "UNIX - Linux";
	case ELFOSABI_SOLARIS: return "UNIX - Solaris";
	case ELFOSABI_FREEBSD: return "UNIX - FreeBSD";
	default: static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", o);
		return buf;
	}
}

/**
 * get_type - returns string for file type
 */
const char *get_type(uint16_t t)
{
	switch (t)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default: static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", t);
		return buf;
	}
}

/**
 * main - displays the ELF header info
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	/* Read ELF identification bytes */
	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	/* Verify ELF magic */
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	printf("ELF Header:\n");
	print_magic(e_ident);

	/* Print Class */
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	/* Print Data */
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");

	/* Print Version */
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");

	/* OS/ABI and ABI Version */
	printf("  OS/ABI:                            %s\n", get_osabi(e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	/* Read rest of header according to class */
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't seek file %s\n", argv[1]);
		exit(98);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr *h32 = malloc(sizeof(Elf32_Ehdr));
		if (!h32)
		{
			close(fd);
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(98);
		}
		r = read(fd, h32, sizeof(Elf32_Ehdr));
		if (r != sizeof(Elf32_Ehdr))
		{
			free(h32);
			close(fd);
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
			exit(98);
		}
		printf("  Type:                              %s\n", get_type(h32->e_type));
		printf("  Entry point address:               0x%x\n", h32->e_entry);
		free(h32);
	}
	else
	{
		Elf64_Ehdr *h64 = malloc(sizeof(Elf64_Ehdr));
		if (!h64)
		{
			close(fd);
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(98);
		}
		r = read(fd, h64, sizeof(Elf64_Ehdr));
		if (r != sizeof(Elf64_Ehdr))
		{
			free(h64);
			close(fd);
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
			exit(98);
		}
		printf("  Type:                              %s\n", get_type(h64->e_type));
		printf("  Entry point address:               0x%lx\n", h64->e_entry);
		free(h64);
	}

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}

	return (0);
}
/*
 * File: 100-elf_header.c
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_magic - prints the ELF magic bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
}

/**
 * get_osabi - returns string for OS/ABI
 */
const char *get_osabi(unsigned char o)
{
	switch (o)
	{
	case ELFOSABI_SYSV: return "UNIX - System V";
	case ELFOSABI_HPUX: return "UNIX - HP-UX";
	case ELFOSABI_NETBSD: return "UNIX - NetBSD";
	case ELFOSABI_LINUX: return "UNIX - Linux";
	case ELFOSABI_SOLARIS: return "UNIX - Solaris";
	case ELFOSABI_FREEBSD: return "UNIX - FreeBSD";
	default: static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", o);
		return buf;
	}
}

/**
 * get_type - returns string for file type
 */
const char *get_type(uint16_t t)
{
	switch (t)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default: static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", t);
		return buf;
	}
}

/**
 * main - displays the ELF header info
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	/* Read ELF identification bytes */
	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	/* Verify ELF magic */
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	printf("ELF Header:\n");
	print_magic(e_ident);

	/* Print Class */
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	/* Print Data */
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");

	/* Print Version */
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");

	/* OS/ABI and ABI Version */
	printf("  OS/ABI:                            %s\n", get_osabi(e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	/* Read rest of header according to class */
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't seek file %s\n", argv[1]);
		exit(98);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr *h32 = malloc(sizeof(Elf32_Ehdr));
		if (!h32)
		{
			close(fd);
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(98);
		}
		r = read(fd, h32, sizeof(Elf32_Ehdr));
		if (r != sizeof(Elf32_Ehdr))
		{
			free(h32);
			close(fd);
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
			exit(98);
		}
		printf("  Type:                              %s\n", get_type(h32->e_type));
		printf("  Entry point address:               0x%x\n", h32->e_entry);
		free(h32);
	}
	else
	{
		Elf64_Ehdr *h64 = malloc(sizeof(Elf64_Ehdr));
		if (!h64)
		{
			close(fd);
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(98);
		}
		r = read(fd, h64, sizeof(Elf64_Ehdr));
		if (r != sizeof(Elf64_Ehdr))
		{
			free(h64);
			close(fd);
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
			exit(98);
		}
		printf("  Type:                              %s\n", get_type(h64->e_type));
		printf("  Entry point address:               0x%lx\n", h64->e_entry);
		free(h64);
	}

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}

	return (0);
}
