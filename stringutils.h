#ifndef _stringutils_h_
#define _stringutils_h_

/* String length and validation */
int string_length(const char* str);
int is_empty_string(const char* str);
int is_numeric_string(const char* str);

/* String manipulation */
void reverse_string(char* str);
void to_uppercase(char* str);
void to_lowercase(char* str);
char* trim_whitespace(char* str);

/* String comparison and search */
int strings_equal(const char* str1, const char* str2);
int count_character(const char* str, char ch);
int find_character(const char* str, char ch);

/* String generation and formatting */
void generate_repeated_char(char* buffer, char ch, int count);
int count_words(const char* str);

#endif /* _stringutils_h_ */