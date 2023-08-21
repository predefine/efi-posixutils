#include <api.h>
#include <applets.h>
#include <../config.h>

struct applet applets[] = {
#ifdef CONFIG_LS
    {"ls", ls_main},
#endif
#ifdef CONFIG_CAT
    {"cat", cat_main},
#endif
};

int applets_getcount(){
    return sizeof(applets)/sizeof(struct applet);
}

struct applet* find_applet(char* name){
    for(int i = 0; i < applets_getcount(); i++)
        if(!strcmp(applets[i].name, name))
            return &applets[i];
    return NULL;
}