#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>


void print_file_info(const char *path){
    
}


int main(){
    
    const char *path = "./";
    
    DIR * fd = opendir(path);
    //printf("errno: %d, error: %s\n", errno, strerror(errno));
    
    struct dirent * file = readdir(fd);
    
    struct stat buf;
    
    int size;
    printf("Statistics for directory: %s\n", path);
    
    while(file != NULL) {
        stat(file->d_name, &buf);
        printf("Directories:\n");
        while(file != NULL && S_ISDIR(buf.st_mode)){
            printf("    %s\n", file->d_name);
            file = readdir(fd);
            stat(file->d_name, &buf);
            size += buf.st_size;
        }
        if (file != NULL) printf("Regular files:\n");
        while(file != NULL && S_ISREG(buf.st_mode)) {
            printf("    %s\n", file->d_name);
            file = readdir(fd);
            stat(file->d_name, &buf);
            size += buf.st_size;

        }
    }
    
    printf("Total directory size: %d bytes\n", size);

    return 0;
}
