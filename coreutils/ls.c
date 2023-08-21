#include <uefi.h>
#include <error.h>
#include <applets.h>

int ls_main(int argc, char** argv){
    char* dirPath = NULL;
    if(argc<2) dirPath = ".";
    else       dirPath = argv[1];
    
    DIR* dir;
    struct dirent* DirEntry;

    if((dir = opendir(dirPath))){
        while((DirEntry = readdir(dir)) != NULL){
            printf("%s\n", DirEntry->d_name);
        }
        closedir(dir);
    } else APPLET_ERROR("Unable to open dir!");

    return 0;
}