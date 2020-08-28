//
// Created by misha on 27/08/2020.
//

#ifndef PRACTICE2_BITS1_H
#define PRACTICE2_BITS1_H

#include <stdbool.h>
#include <string.h>
#include <malloc.h>

bool pow_of_2(unsigned int n) {
    unsigned int counter = n & 1;
    for (int i = 0; i < 15; i++, counter += (n >> i & 1));
    return counter == 2;
}

int sbstr_index(char *haystack, const char *needle, int n) {
    unsigned long postfix = strlen(needle);
    char *str_p = haystack;
    n--;
    for (; n > 0; str_p += strstr(str_p, needle) - str_p,n--) {
            str_p += postfix;
        if ((str_p >= haystack + strlen(haystack)) || (strstr(str_p, needle) == NULL))
            return -1;
    }
    return str_p - haystack;
}

char* substitute(char* haystack, char* needle, char* insert, int index){
    int head_size = sbstr_index(haystack, needle, index);

    if(head_size == -1)
        return NULL;

    unsigned long insert_size = strlen(insert);
    unsigned long needle_size = strlen(needle);
    unsigned long tail_size = strlen(haystack) + ( insert_size - needle_size);

    char res[head_size+insert_size+tail_size];

    int i;
    for(i = 0; i < head_size; res[i] = haystack[i], i++); //wrie the head - no change
    for(i = 0; i < insert_size; res[head_size+i] = insert[i], i++); //insert the sequence, overriding the origin
    for (i = 0; i <  tail_size; res[head_size+insert_size+i] = haystack[head_size+needle_size+i], i++ ); //write the tail - no change
    return strdup(res);
}



#endif //PRACTICE2_BITS1_H
