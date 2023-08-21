#include <uefi.h>
#include <api.h>

#define usage_error() {usage(argv[0]); goto err;}

void usage(char* argv0){
    printf("Usage: %s <applet>\n", argv0);
    printf("Applets:");
    for(int i = 0; i < applets_getcount(); i++)
        printf(" %s", applets[i].name);
    printf("\n");
}

int main (int argc, char **argv)
{
    if(argc<2)
        usage_error();

    struct applet* app = find_applet(argv[1]);
    if(app==NULL)
        usage_error();
    
    argc--;
    argv++;

    return app->applet_main(argc, argv);

err:
    return 1;
}
