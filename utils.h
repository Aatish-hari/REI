#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  
char** parsing_input(char* input);

void free_tokens(char** tokens);

void CommandExecution(char** tokens, char** env);

char* finding_path(char* command);