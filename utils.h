#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char** parsing_input(char* input);

void free_tokens(char** tokens);

void commandExecution(char** tokens, char** env);