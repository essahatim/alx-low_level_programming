#ifndef MAIN_H
#define MAIN_H

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include <elf.h>




#define USAGE "Usage: cp file_from file_to\n"
#define ER_NORD "Error: Can't read from file %s\n"
#define ER_NOWR "Error: Can't write to %s\n"
#define ER_NOCL "Error: Can't close fd %d\n"
#define ERR_NORD "Error: Can't read file %s\n"
#define ERR_NOSF "Error: `%s`: No such file\n"
#define ER_NOELF "Error: Not an ELF file\n"



ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void close_file(int fd);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif
