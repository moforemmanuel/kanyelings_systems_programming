#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


// int open(const char *name, int flags, mode_t mode);


int main(int argc, char *argv[]){
    const char *file = argv[1];
    (void)argc;

    int fd;
    errno = 0;

    fd = open(file, O_RDONLY);

    if (fd < 0){
        printf("-- %s could not be opened -- \n", file);
        perror("open");
        return 1;
        
    }
    else {
        off_t fileLength =lseek(fd, 0, SEEK_END);

        if (fileLength < 0 ) {
            return 1;
        } 
        else {
            // printf("%ld  \n", fileLength);
        }

        lseek(fd, 0, SEEK_SET);

        char content[100];
        ssize_t bytes = read(fd, content, sizeof(content) - 1);
        if (bytes < 1){
            printf("-- %s could not be read -- \n", file);
            perror("read");
            return 1;
        } 
        else {
            printf("%ld \n", bytes);
            write(1, content, bytes/2);
        }
        
    }

    close(fd);
    return 0;
}