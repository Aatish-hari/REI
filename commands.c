#include "utils.h"

void commandExecution(char** tokens, char** env){
    
    if(strcmp(tokens[0], "echo") == 0){
        for(int i = 1; tokens[i] ; i++){
            printf(tokens[i]);
            if(tokens[i+1])
            printf("\n");
        }
    }
    else if(){

    }
}