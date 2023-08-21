#include <uefi.h>
#include <api.h>

#define usage_error() {usage(argv[0]); goto err;}

void usage(char* argv0){
    printf("Usage: %s help\n", argv0);
}

int main (int argc, char **argv)
{
    if(argc<2)
        usage_error();

    if(!strcmp(argv[1], "help")){
        printf("TODO!\n");
    } else usage_error();

    return 0;
err:
    return 1;
}
