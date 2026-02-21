#include "utils.h"

char** parsing(char* input){

    char** tokens = malloc(1024 * sizeof(char*));

    char* token = NULL;
    int index = 0;
    int length = strlen(input);
    for(int i = 0 ; i<length; i++){     
        token = input;
        int st = i;
        while(input[i] && input[i] != ' '){
            i++;
        }
        int end = i;
        tokens[index] = malloc((end-st+1) * sizeof(char));
        for(int j = 0 ; j<end-st ; j++){                    
            tokens[index][j] = token[st+j];                     
        }
         tokens[index][end-st] = '\0';
        index++;
    }
    
    tokens[index] = NULL;
    return tokens;
}