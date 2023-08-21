#include <uefi.h>

struct applet {
    char* name;
    int (*applet_main)(int argc, char** argv);
};

struct applet* find_applet(char* name);