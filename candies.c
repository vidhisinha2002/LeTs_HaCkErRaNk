#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, int arr_count, int* arr) {
    int c[n];                       //numbr of candies wala array
    for(int i=0;i<n;i++)
        c[i]=1;                     //sbko atleast 1 dena he hai to pehle de do 
   
    for(int i=1;i<n;i++)          //l to r----leftmost ele lena ni h cuz uske left m kuch ni h 1>0....n-1>n-2
    {
        if(arr[i]>arr[i-1]){      //1 2 2 -- 1 2 1 =4
          
            c[i]=c[i-1]+1;      //purane me ek plus.......COPY
        }
    } 
    for(int i=n-2;i>=0;i--)       // r to l-----rightmost ele lena ni h cuz uske right m kuch ni h....n-2>n-1......0>1
    {
        if(arr[i]>arr[i+1])
            c[i]= max((c[i+1]+1),c[i]);       //max cuz aisa na ho right aane me dec hoje cux we want maxx
        
    }  

    long sum=0;
    for(int i=0;i<n;i++)          //finally add all ele or c array for total no of candies
        sum=sum+(long)c[i];
        
    return sum;


}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(ltrim(rtrim(readline())));

        *(arr + i) = arr_item;
    }

    long result = candies(n, n, arr);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
