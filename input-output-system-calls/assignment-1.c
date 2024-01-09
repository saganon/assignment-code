#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
    char fileNameToCopy[25];
    char destinationFile[25];
    char slash[10] = "/";
    int totalChar = 40;
    char contentFile[totalChar];

    printf("Input file that you want to copy: ");
    scanf("%s", fileNameToCopy);

    printf("Input the destination folder name: ");
    scanf("%s", destinationFile);

    strcat(slash, fileNameToCopy);
    strcat(destinationFile, slash);

    int file = open(destinationFile, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IROTH);

    if (file == -1)
    {
        printf("\nFile is already exist. Copy process failed!\n");
    }

    int parentFile = open(fileNameToCopy, O_RDWR);
    read(parentFile, contentFile, totalChar);

    write(file, contentFile, strlen(contentFile));

    close(file);
    close(parentFile);

    return 0;
}