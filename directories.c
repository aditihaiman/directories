#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


void print_file_info(const char *path){
    
}


int main(){
    
    DIR * fd = opendir("./");
    //printf("errno: %d, error: %s\n", errno, strerror(errno));
    
    struct dirent * file = readdir(fd);

    
    while(file != NULL) {
        //printf("%s\n", file->d_name);
        file = readdir(fd);
    }
    
    return 0;
}
