#include "utils.h"

char** parsing_input(char* input){

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
            tokens[index][j] = token[st+j];             // tokens[3][0] -> [(index1), (index2), (j)]       
        }
         tokens[index][end-st] = '\0';
        index++;
    }

    tokens[index-1][strcspn(tokens[index-1], "\n")] = 0; //removing \n of last index
    
    
    tokens[index] = NULL;
    return tokens;
}

//======================================

void free_tokens(char** tokens){
    for(int i = 0; tokens[i] != NULL ; i++){
        free(tokens[i]);
    }
    free(tokens);
}