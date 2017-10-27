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
    srand(time(NULL));

    fd = open('/dev/random', O_RDONLY);
    read()
    int rnumandom[10];

    int i;
    for (i = 0; i < 10; i++) {
        rnumandom[i] = rand
    }

    return 0;
}