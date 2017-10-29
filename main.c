#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int fd;
    int random;
    int numran[10];

    // Generating random numbers and populating the array
    printf("Generating random numbers: \n");

    int i;
    for (i = 0; i < 10; i++) {
        fd = open("/dev/random", O_RDONLY);
        // If fd < 0 then the user doesn't have /dev/random
        if (fd < 0) {
            printf("You appear to be missing a /dev/random directory.\n");
            break;
        } else {
            read(fd, &random, sizeof(random));
            close(fd);
            numran[i] = random;
            printf("\trandom %d: %d\n", i, numran[i]);
        }
    }

    // File Writing

    printf("\nWriting numbers to file...\n\n");
    // Writes to rannums.txt
    int fileNums = open("rannums.txt", O_CREAT | O_RDWR, 0644);
    if (fileNums < 0) {
        printf("You appear to be missing a /dev/random directory.\n");
    } else {
        write(fileNums, numran, sizeof(numran));
        close(fileNums);
    }

    // File Reading
    printf("Reading numbers from file...\n\n");
    int results[10];
    // Reads from rannums.txt
    fileNums = open("rannums.txt", O_RDONLY);
    if (fileNums < 0) {
        printf("You appear to be missing a /dev/random directory.\n");
    } else {
        read(fileNums, results, sizeof(results));
        close(fileNums);
    }
    
    // Print result
    printf("Verification that written values were the same:\n");
    for (i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, results[i]);
    }

    return 0;
}