#include <uefi.h>
#include <error.h>
#include <applets.h>
#include <utils.h>
#include <keys.h>

int cat_main(int argc, char** argv){
    char* read_from = NULL;
    if(argc < 2) read_from="/dev/stdin";
    else         read_from=argv[1];

    FILE* f = fopen(read_from, "r");
    if(f==NULL)
        APPLET_ERROR_NUMBER(errno)
    
    if (strcmp(read_from, "/dev/stdin")){
        size_t filesize = fsize(f);
        char *buf = malloc(filesize+1);

        fread(buf, filesize, 1, f);
        fwrite(buf, filesize, 1, stdout);
    } else {
        int key = 0;
        for(;;key=getchar_ifany()){
            if(key==KEY_CTRLC) goto end;
            if(key==KEY_ENTER) printf("\n");
            else if(key!=0) {
                printf("%c", key);
            }
        }
    }
end:
    printf("\n");
    return 0;
}