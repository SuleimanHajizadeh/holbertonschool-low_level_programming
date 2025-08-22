#ifndef MAIN_H
#define MAIN_H

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _putchar(char c);
void print_error(void);
int is_digit_str(char *s);
void multiply_and_print(char *num1, char *num2);
void free_and_exit(int *ptr);
void *create_x_array(int size);
char *_memcpy(char *dest, char *src, int n);
int _strlen(char *s);
void print_number(char *num);
void multiply(char *num1, char *num2);
void _error(int *res);
int _putchar(char c);
int _isdigit(char *s);

#endif
