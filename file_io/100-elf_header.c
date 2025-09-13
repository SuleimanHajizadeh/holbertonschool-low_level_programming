#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

/**
 * err_98 - prints error and exits with 98
 */
void err_98(void)
{
	dprintf(STDERR_FILENO, "Error\n");
	exit(98);
}

/**
 * print_magic - prints ELF magic numbers
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
 * main - displays ELF header info
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
		err_98();

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_98();

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		err_98();

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		err_98();

	printf("ELF Header:\n");
	print_magic(e_ident);

	/* Class */
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	/* Data */
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");

	/* Version */
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");

	/* OS/ABI */
	printf("  OS/ABI:                            %s\n",
	       get_osabi(e_ident[EI_OSABI]));

	/* ABI Version */
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);

	/* Read remaining header according to class */
	if (lseek(fd, 0, SEEK_SET) == -1)
		err_98();

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;
		r = read(fd, &h32, sizeof(h32));
		if (r != sizeof(h32))
			err_98();

		printf("  Type:                              %s\n", get_type(h32.e_type));
		printf("  Entry point address:               0x%x\n",
		       h32.e_entry);
	}
	else
	{
		Elf64_Ehdr h64;
		r = read(fd, &h64, sizeof(h64));
		if (r != sizeof(h64))
			err_98();

		printf("  Type:                              %s\n", get_type(h64.e_type));
		printf("  Entry point address:               0x%lx\n",
		       h64.e_entry);
	}

	if (close(fd) == -1)
		err_98();

	return (0);
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

/**
 * err_98 - prints error and exits with 98
 */
void err_98(void)
{
	dprintf(STDERR_FILENO, "Error\n");
	exit(98);
}

/**
 * print_magic - prints ELF magic numbers
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
 * main - displays ELF header info
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
		err_98();

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_98();

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		err_98();

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		err_98();

	printf("ELF Header:\n");
	print_magic(e_ident);

	/* Class */
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	/* Data */
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");

	/* Version */
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");

	/* OS/ABI */
	printf("  OS/ABI:                            %s\n",
	       get_osabi(e_ident[EI_OSABI]));

	/* ABI Version */
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);

	/* Read remaining header according to class */
	if (lseek(fd, 0, SEEK_SET) == -1)
		err_98();

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;
		r = read(fd, &h32, sizeof(h32));
		if (r != sizeof(h32))
			err_98();

		printf("  Type:                              %s\n", get_type(h32.e_type));
		printf("  Entry point address:               0x%x\n",
		       h32.e_entry);
	}
	else
	{
		Elf64_Ehdr h64;
		r = read(fd, &h64, sizeof(h64));
		if (r != sizeof(h64))
			err_98();

		printf("  Type:                              %s\n", get_type(h64.e_type));
		printf("  Entry point address:               0x%lx\n",
		       h64.e_entry);
	}

	if (close(fd) == -1)
		err_98();

	return (0);
}
