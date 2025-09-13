#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * print_error - print error message and exit with code 98
 * @msg: error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_magic - print the ELF magic bytes
 * @e_ident: ELF identification array
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - print ELF class
 * @e_ident: ELF identification array
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE: printf("none\n"); break;
	case ELFCLASS32: printf("ELF32\n"); break;
	case ELFCLASS64: printf("ELF64\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
	}
}

/**
 * print_data - print ELF data encoding
 * @e_ident: ELF identification array
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE: printf("none\n"); break;
	case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
	case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_DATA]); break;
	}
}

/**
 * print_version - print ELF version
 * @e_ident: ELF identification array
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - print ELF OS/ABI
 * @e_ident: ELF identification array
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
	case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
	case ELFOSABI_ARM: printf("ARM\n"); break;
	case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_OSABI]); break;
	}
}

/**
 * print_type - print ELF type
 * @type: ELF file type
 * @data: endianness from e_ident
 */
void print_type(uint16_t type, unsigned char data)
{
	if (data == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE: printf("NONE (None)\n"); break;
	case ET_REL: printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default: printf("<unknown: %x>\n", type); break;
	}
}

/**
 * print_entry - print entry point address
 * @entry: entry point
 * @class: ELF class (32 or 64)
 * @data: endianness
 */
void print_entry(unsigned long entry, unsigned char class, unsigned char data)
{
	if (data == ELFDATA2MSB)
	{
		if (class == ELFCLASS32)
			entry = __builtin_bswap32((uint32_t)entry);
		else
			entry = __builtin_bswap64(entry);
	}

	printf("  Entry point address:               ");
	if (class == ELFCLASS32)
		printf("0x%x\n", (unsigned int)entry);
	else
		printf("0x%lx\n", entry);
}

/**
 * main - displays ELF header information
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't open file");

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Can't read ELF ident");

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	/* reposition and read full header */
	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Can't lseek");

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
		print_error("Can't read ELF header");

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
	print_type(header.e_type, e_ident[EI_DATA]);
	print_entry(header.e_entry, e_ident[EI_CLASS], e_ident[EI_DATA]);

	if (close(fd) == -1)
		print_error("Can't close fd");

	return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * print_error - print error message and exit with code 98
 * @msg: error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_magic - print the ELF magic bytes
 * @e_ident: ELF identification array
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - print ELF class
 * @e_ident: ELF identification array
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE: printf("none\n"); break;
	case ELFCLASS32: printf("ELF32\n"); break;
	case ELFCLASS64: printf("ELF64\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
	}
}

/**
 * print_data - print ELF data encoding
 * @e_ident: ELF identification array
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE: printf("none\n"); break;
	case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
	case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_DATA]); break;
	}
}

/**
 * print_version - print ELF version
 * @e_ident: ELF identification array
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - print ELF OS/ABI
 * @e_ident: ELF identification array
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
	case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
	case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
	case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
	case ELFOSABI_ARM: printf("ARM\n"); break;
	case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
	default: printf("<unknown: %x>\n", e_ident[EI_OSABI]); break;
	}
}

/**
 * print_type - print ELF type
 * @type: ELF file type
 * @data: endianness from e_ident
 */
void print_type(uint16_t type, unsigned char data)
{
	if (data == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE: printf("NONE (None)\n"); break;
	case ET_REL: printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default: printf("<unknown: %x>\n", type); break;
	}
}

/**
 * print_entry - print entry point address
 * @entry: entry point
 * @class: ELF class (32 or 64)
 * @data: endianness
 */
void print_entry(unsigned long entry, unsigned char class, unsigned char data)
{
	if (data == ELFDATA2MSB)
	{
		if (class == ELFCLASS32)
			entry = __builtin_bswap32((uint32_t)entry);
		else
			entry = __builtin_bswap64(entry);
	}

	printf("  Entry point address:               ");
	if (class == ELFCLASS32)
		printf("0x%x\n", (unsigned int)entry);
	else
		printf("0x%lx\n", entry);
}

/**
 * main - displays ELF header information
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't open file");

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Can't read ELF ident");

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	/* reposition and read full header */
	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Can't lseek");

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
		print_error("Can't read ELF header");

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
	print_type(header.e_type, e_ident[EI_DATA]);
	print_entry(header.e_entry, e_ident[EI_CLASS], e_ident[EI_DATA]);

	if (close(fd) == -1)
		print_error("Can't close fd");

	return (0);
}
