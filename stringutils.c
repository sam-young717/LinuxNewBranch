/*
 * String utilities module for text processing operations
 */

#include "stringutils.h"
#include <ctype.h>

/* String length and validation */
int string_length(const char* str)
{
    int len = 0;
    if (str == 0) {
        return 0;
    }
    
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int is_empty_string(const char* str)
{
    return (str == 0 || str[0] == '\0');
}

int is_numeric_string(const char* str)
{
    int i;
    
    if (is_empty_string(str)) {
        return 0;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* String manipulation */
void reverse_string(char* str)
{
    int len, i;
    char temp;
    
    if (str == 0) {
        return;
    }
    
    len = string_length(str);
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void to_uppercase(char* str)
{
    int i;
    
    if (str == 0) {
        return;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lowercase(char* str)
{
    int i;
    
    if (str == 0) {
        return;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

char* trim_whitespace(char* str)
{
    char* end;
    
    if (str == 0) {
        return str;
    }
    
    /* Trim leading whitespace */
    while (isspace(*str)) {
        str++;
    }
    
    /* Trim trailing whitespace */
    end = str + string_length(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    
    return str;
}

/* String comparison and search */
int strings_equal(const char* str1, const char* str2)
{
    int i = 0;
    
    if (str1 == 0 && str2 == 0) {
        return 1;
    }
    if (str1 == 0 || str2 == 0) {
        return 0;
    }
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    
    return (str1[i] == '\0' && str2[i] == '\0');
}

int count_character(const char* str, char ch)
{
    int count = 0;
    int i;
    
    if (str == 0) {
        return 0;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int find_character(const char* str, char ch)
{
    int i;
    
    if (str == 0) {
        return -1;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i; /* Return index of first occurrence */
        }
    }
    return -1; /* Character not found */
}

/* String generation and formatting */
void generate_repeated_char(char* buffer, char ch, int count)
{
    int i;
    
    if (buffer == 0 || count < 0) {
        return;
    }
    
    for (i = 0; i < count; i++) {
        buffer[i] = ch;
    }
    buffer[count] = '\0';
}

int count_words(const char* str)
{
    int count = 0;
    int in_word = 0;
    int i;
    
    if (str == 0) {
        return 0;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    
    return count;
}