#include"utils.h"


int main(int argc, char** argv, char** env){
    
    char* input= NULL;
    size_t inputsize = 0;

    char** tokens;
    while(1){                   //shell loop
        printf("(REI): ");
        getline(&input, &inputsize, stdin);

        tokens = parsing_input(input);
        
        if (tokens == NULL || tokens[0] == NULL){
            continue;
        }
        if (strcmp(tokens[0], "exit")==0){
            printf("REI closed\n"); 
            break;
        }
        CommandExecution(tokens, env);
        
    }

    free_tokens(tokens);

}