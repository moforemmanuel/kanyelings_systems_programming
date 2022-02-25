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

        // char *content = (char*)malloc(sizeof(char)*(fileLength + 1));

        char content[fileLength + 1];
        ssize_t bytes = read(fd, content, sizeof(content) - 1);
        if (bytes < 0){
            printf("-- %s could not be read -- \n", file);
            perror("read");
            return 1;
        } 
        else {
            // printf("%ld \n", bytes);
            // write(1, content, bytes);
            content[fileLength] = '\0';
            // printf("%s", content);

            char str1[fileLength/2 + 2], str2[fileLength/2 + 2];

            for (int i = 0; i <= fileLength/2; i++){
                str1[i] = content[i];
            }
            str1[fileLength/2 + 1] = '\n';
            str1[fileLength/2 + 2] = '\0';


            for (int j = fileLength/2 + 1, k = 0; j <= fileLength && k <= fileLength/2 + 1; j++, k++){
                str2[k] = content[j];
                // printf("%c\n", content[j]);
            }

            // printf("%s", str1);
            // printf("%s", str2);
            
            printf("-- file : %s - splitting file done -- \n", file);
            
            char file1[] = "file1.txt";
            char file2[] = "file2.txt";

            //file 1 create
            int fd1 = creat(file1, 0744);
            if (fd1 < 0){
            printf("-- file : %s - could not be created -- \n", file1);
            perror("create");
            return 1;
            }

            else {
                printf("-- file 1: %s - created file successfully -- \n", file1);

            }

            //file2 create
            int fd2 = creat(file2, 0744);
            if (fd2 < 0){
            printf("-- file : %s - could not be created -- \n", file2);
            perror("create");
            return 1;
            }

            else {
                printf("-- file 2: %s - created file successfully -- \n", file2);

            }

            //file1 write
            printf("-- file 1: writing to %s --\n", file1);
            ssize_t fr1 = write(fd1, str1, bytes);
            if (fr1 < 0){
                printf("-- file 1: %s - could not write to file -- \n", file1);
                perror("write");
                return 1;
                
            }
            else {
            printf("-- file 1: %s - wrote to file sucessfully  -- \n", file1);
                
            }

            //file 2 write
            printf("-- file 2: writing to %s --\n", file2);
            ssize_t fr2 = write(fd2, str2, bytes);
            if (fr2 < 0){
                printf("-- file 2: %s - could not write to file -- \n", file2);
                perror("write");
                return 1;
                
            }
            else {
            printf("-- file 2: %s - wrote to file sucessfully  -- \n", file2);

                
            }
            printf("\n-- Operation complete: copied %s contents to %s and %s --\n\n",file, file1, file2);

            close(fd1);
            close(fd2);

        }

        // free(content);
        
        
    }

    
    close(fd);
    
    return 0;
}