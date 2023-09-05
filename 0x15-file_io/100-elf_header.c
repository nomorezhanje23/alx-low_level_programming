#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * print_elf_header_info - this prints information from the ELF header
 * @header: pointer to the ELF header structure
 * main: this displays the information contained in the file
 * return: 0 upon sucess
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("Class: %s\n", header->e_ident[EI_CLASS]
== ELFCLASS64 ? "ELF64" : "ELF32");
printf("Data %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ?
"2's complement, little endian" : "2's complement, big endian");
printf("Version: %d (current)\n", header->e_ident[EI_VERSION]);
printf("OS/ABI:  %d\n", header->e_ident[EI_OSABI]);
printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
printf("Type: %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)"
: (header->e_type == ET_DYN ? "DYN (Shared object file)"
: "REL (Relocatable file)"));
printf("Entry point address:0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}
int fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
exit(98);
}

Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header)
|| memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
{
fprintf(stderr, "Error: Not an ELF file: '%s'\n", argv[1]);
exit(98);
}

printf("ELF Header:\n");
print_elf_header_info(&header);

close(fd);
return (0);
}
