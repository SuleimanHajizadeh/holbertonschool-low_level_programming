/*
 * File: 100-elf_header.c
 */

#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_error - Print error message and exit with code 98
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_magic - Prints ELF magic numbers
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
}

/**
 * get_osabi - Returns a string for OS/ABI
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
	default:
		{
			static char buf[32];
			snprintf(buf, sizeof(buf), "<unknown: %x>", o);
			return buf;
		}
	}
}

/**
 * get_type - Returns a string describing ELF type
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
	default:
		{
			static char buf[32];
			snprintf(buf, sizeof(buf), "<unknown: %x>", t);
			return buf;
		}
	}
}

/**
 * swap16, swap32, swap64 - Byte swap functions for big-endian support
 */
uint16_t swap16(uint16_t val)
{
	return (val >> 8) | (val << 8);
}

uint32_t swap32(uint32_t val)
{
	return ((val >> 24) & 0xff) |
	       ((val >> 8) & 0xff00) |
	       ((val << 8) & 0xff0000) |
	       ((val << 24) & 0xff000000);
}

uint64_t swap64(uint64_t val)
{
	return ((val >> 56) & 0xff) |
	       ((val >> 40) & 0xff00) |
	       ((val >> 24) & 0xff0000) |
	       ((val >> 8) & 0xff000000) |
	       ((val << 8) & 0xff00000000ULL) |
	       ((val << 24) & 0xff0000000000ULL) |
	       ((val << 40) & 0xff000000000000ULL) |
	       ((val << 56) & 0xff00000000000000ULL);
}

/**
 * main - Displays ELF header information
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];
	int is_big_endian;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't read file");

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		print_error("Can't read ELF header");
	}

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	is_big_endian = (e_ident[EI_DATA] == ELFDATA2MSB);

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

	/* OS/ABI and ABI Version */
	printf("  OS/ABI:                            %s\n", get_osabi(e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	/* Read full header */
	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Can't seek file");

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;
		r = read(fd, &h32, sizeof(Elf32_Ehdr));
		if (r != sizeof(Elf32_Ehdr))
			print_error("Can't read ELF header");

		uint16_t e_type = is_big_endian ? swap16(h32.e_type) : h32.e_type;
		uint32_t e_entry = is_big_endian ? swap32(h32.e_entry) : h32.e_entry;

		printf("  Type:                              %s\n", get_type(e_type));
		printf("  Entry point address:               0x%x\n", e_entry);
	}
	else
	{
		Elf64_Ehdr h64;
		r = read(fd, &h64, sizeof(Elf64_Ehdr));
		if (r != sizeof(Elf64_Ehdr))
			print_error("Can't read ELF header");

		uint16_t e_type = is_big_endian ? swap16(h64.e_type) : h64.e_type;
		uint64_t e_entry = is_big_endian ? swap64(h64.e_entry) : h64.e_entry;

		printf("  Type:                              %s\n", get_type(e_type));
		printf("  Entry point address:               0x%lx\n", e_entry);
	}

	if (close(fd) == -1)
		print_error("Can't close fd");

	return (0);
}
