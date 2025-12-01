/* 2. Copy content of one file to another using system calls */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src, dest;
    char buffer[1024];
    ssize_t bytes;

    char sourceFile[100], destFile[100];

    printf("Enter source file name: ");
    scanf("%s", sourceFile);
    printf("Enter destination file name: ");
    scanf("%s", destFile);

    src = open(sourceFile, O_RDONLY);
    if (src < 0) {
        printf("Cannot open source file\n");
        return 1;
    }

    dest = open(destFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        printf("Cannot open/create destination file\n");
        close(src);
        return 1;
    }

    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);

    printf("File copied successfully.\n");
    return 0;
}

