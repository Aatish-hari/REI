#include "utils.h"

void CommandExecution(char** tokens, char** env){
    
//echo command====>
    if(strcmp(tokens[0], "echo") == 0){
        for(int i = 1; tokens[i] ; i++){
           printf("%s ", tokens[i]);
            if(!tokens[i+1])
                printf("\n");
        }
    }

//cd command======>
    else if(strcmp(tokens[0], "cd") == 0){
        
    if(tokens[1] == NULL) {
        printf("Error: Need directory name as argument\n");
        }

    else{
        // tokens[1][strcspn(tokens[1], "\n")] = 0;        //

        if(chdir(tokens[1]) != 0) {
            printf("cd: no such directory\n");
        }
        else{
            char* cwd;
            cwd = getcwd(NULL, 0);
            printf("%s\n", cwd);
            free(cwd);
        }
    }
}
//===================>

//pwd command========>
    else if(strcmp(tokens[0], "pwd") == 0){
        char* cwd;
        cwd = getcwd(NULL, 0);
        printf("%s\n", cwd);
        free(cwd);
    }
//=================>


}