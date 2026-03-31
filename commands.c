#include "utils.h"

// For which command
char* finding_path(char* command) {     //command to be found
    char* env = strdup(getenv("PATH"));// gotta copy PATH, cause we gonna change the PATH inside our own running program's memory if we will not copy
    char full_path[1024];
    char* all_dir = strtok(env, ":");
    while (all_dir != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", all_dir, command);

        if (access(full_path, X_OK) == 0) {
            char* result = strdup(full_path);  
            free(env);                         
            return result;                    
        }
        all_dir = strtok(NULL, ":");
    }

    free(env);
    return NULL;
}

void CommandExecution(char** tokens, char** env){
    
//echo command====>
    if(strcmp(tokens[0], "echo") == 0){
        for(int i = 1; tokens[i] ; i++){
            if(tokens[i][0] == '$'){
                char* env = getenv(tokens[i] +1);
                printf("%s ", env);
            }
            else{
                printf("%s ", tokens[i]);
            }
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

//which command====>

    else if(strcmp(tokens[0], "which") == 0){
        if(tokens[1] == NULL){
            printf("which require argument");
        }

        for(int i = 1 ; tokens[i] ; i++){
            char* result = finding_path(tokens[i]);
            printf("%s\n", result);
        }
        
    }
//=================>

}


