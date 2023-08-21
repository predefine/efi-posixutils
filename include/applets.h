#pragma once
#include <../config.h>


#ifdef CONFIG_LS
int ls_main(int argc, char** argv);
#endif
#ifdef CONFIG_CAT
int cat_main(int argc, char** argv);
#endif