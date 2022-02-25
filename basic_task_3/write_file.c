#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


// int open(const char *name, int flags, mode_t mode);


int main(int argc, char *argv[]){
    printf("\n");
    const char *file1 = argv[1];
    const char *file2 = argv[2];
    (void)argc;

    int fd1, fd2;
    errno = 0;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_WRONLY);

    if (fd1 < 0){
        printf("-- file 1: %s - could not be opened -- \n", file1);
        perror("open");
        return 1;
        
    }
    else {
        printf("-- file 1: %s - opened successfully -- \n", file1);

        if (fd2 < 0) {
            printf("-- file 2: %s - could not be opened -- \n", file2);
            perror("open");
        
            printf("-- file 2: %s - creating file -- \n", file2);
            
            fd2 = creat(file2, 0744);
            if (fd1 < 0){
            printf("-- file 2: %s - could not be created -- \n", file2);
            perror("create");
            return 1;
            }

            else {
                printf("-- file 2: %s - created file successfully -- \n", file2);

            }
        
        } else {
            printf("-- file 2: %s - opened successfully -- \n", file2);
        }

        off_t fileLength =lseek(fd1, 0, SEEK_END);

        if (fileLength < 0 ) {
            return 1;
        } 
        else {
            // printf("%ld  \n", fileLength);
        }

        lseek(fd1, 0, SEEK_SET);

        char content[100];
        ssize_t bytes = read(fd1, content, sizeof(content) - 1);
        if (bytes < 1){
            printf("-- %s could not be read -- \n", file1);
            perror("read");
            return 1;
        } 
        else {
            // printf("%ld \n", bytes);
            // ssize_t fr1 = write(1, content, bytes);
            // (void)fr1;

            printf("-- file 2: writing to %s --\n", file2);
            ssize_t fr2 = write(fd2, content, bytes);
            if (fr2 < 0){
                printf("-- file 2: %s - could not write to file -- \n", file2);
                perror("write");
                return 1;
                
            }
            else {
            printf("-- file 2: %s - wrote to file sucessfully  -- \n", file2);
            printf("\n-- Operation complete: copied %s contents to %s --\n\n", file1, file2);

                
            }
            
        }

        
    }

    close(fd1);
    close(fd2);
    return 0;
}