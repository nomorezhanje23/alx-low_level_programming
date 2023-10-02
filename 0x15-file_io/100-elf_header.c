/**
 * Tawanda project
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

/**
 * error_exit - Print an error message and exit with status code 98
 * @msg: The error message to print
 */

void error_exit(const char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
 * print_elf_header_info - Print information from the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", header->e_ident[i]);
printf("\nClass: %d\n", header->e_ident[EI_CLASS]);
printf("Data: %d\n", header->e_ident[EI_DATA]);
printf("Version: %d\n", header->e_ident[EI_VERSION]);
printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
printf("Type: %d\n", header->e_type);
printf("Entry point address: 0x%lx\n",
(unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
if (argc != 2)
error_exit("Usage: elf_header elf_filename");

const char *filename = argv[1];
int fd = open(filename, O_RDONLY);
if (fd == -1)
error_exit(strerror(errno));

Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header))
error_exit("Error reading ELF header");

if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
error_exit("Not an ELF file");

print_elf_header_info(&header);
close(fd);
return (0);
}
