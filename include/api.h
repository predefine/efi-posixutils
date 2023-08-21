#include <uefi.h>

struct applet {
    char* name;
    int (*applet_main)(int argc, char** argv);
};

extern struct applet applets[];
int applets_getcount();
struct applet* find_applet(char* name);