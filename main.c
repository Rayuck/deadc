#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f = fopen(argv[1], "r");
    if(f==NULL){
        printf("Invalid File: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    rewind(f);

    char *filecontent = calloc(fsize, sizeof(char));

    fread(filecontent, sizeof(char), fsize, f);
    fclose(f);

    char cell=0;

    for (int i=0;i<fsize;i++){
        switch (filecontent[i]){
            case 'i': ++cell; break;
            case 'd': --cell; break;
            case 's': cell=cell*cell; break;
            case 'o': printf("%i", cell);
        }
    }

    free(filecontent);
    return EXIT_SUCCESS;
}