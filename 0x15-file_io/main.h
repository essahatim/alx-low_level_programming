#ifndef MAIN_H
#define MAIN_H

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

#define USAGE "Usage: cp file_from file_to\n"
#define ER_NORD "Error: Can't read from file %s\n"
#define ER_NOWR "Error: Can't write to %s\n"
#define ER_NOCL "Error: Can't close fd %s\n"
#define PERMISSION (S_IRUSR | S_IRGRP | S_IROTH | S_IWGRP | S_IWUSR)


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);


#endif
