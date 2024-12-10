#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f = fopen(argv[1], "r");

    // error out if file not found
    if(f==NULL){
        printf("Invalid File: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // find file size
    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    rewind(f);

    // allocate memory dependent on file size
    char *filecontent = calloc(fsize, sizeof(char));

    // read contents of file to filecontent (no shit) 
    fread(filecontent, sizeof(char), fsize, f);
    fclose(f);

    char cell=0;

    // general logic
    for (int i=0;i<fsize;i++){
        switch (filecontent[i]){
            case 'i': ++cell; break;
            case 'd': --cell; break;
            case 's': cell=cell*cell; break;
            case 'o': printf("%i", cell);
        }
    }

    free(filecontent);

    // HURRAY :)
    return EXIT_SUCCESS;
}
