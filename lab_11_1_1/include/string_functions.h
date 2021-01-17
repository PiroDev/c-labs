#ifndef STRING_FUNCTIONS_H_
#define STRING_FUNCTIONS_H_

void write_symbol_to_string(char symbol, char *str, int str_len, int pos);
int copy_to_string(char *src, char *dest, int start_pos, int dest_len);
void swap(char *first_symbol, char *second_symbol);
int oct(unsigned long int number, char *oct_str);

#endif  // STRING_FUNCTIONS_H_
