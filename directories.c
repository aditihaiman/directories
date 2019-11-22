#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>


void print_file_info(const char *path){
    
}


int main( int argc, char *argv[]){

    const char *path;
    
    if (argc > 1) path = argv[1];
    else path = "./";
    
    DIR * fd = opendir(path);
        
    if (errno != 0) printf("errno: %d, error: %s\n", errno, strerror(errno));
    
    else {
        
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
    }

    return 0;
}
