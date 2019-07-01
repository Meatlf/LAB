#ifndef DEFINE_FUNCTION_H
#define DEFINE_FUNCTION_H

int double_num(int);
bool find_number_in_martrix(int* matrix, int row, int column,
	int number, int* location);
int temp_string_length(const char* string, int length);
int replace_blank(const char* string, int length, int lengthTemp, char* replaceBlankString);
#endif // !DEFINE_FUNCTION_H