#include <utils.h>

size_t fsize(FILE* file){
    struct stat fst;
    fstat(file, &fst);
    return fst.st_size;
}