#include"utils.h"


int main(int argc, char** argv, char** env){
    
    char* input= NULL;
    size_t inputsize = 0;

    char** tokens;
    while(1){                   //shell loop
        printf("(REI): ");
        getline(&input, &inputsize, stdin);

        tokens = parsing(input);
    }

}