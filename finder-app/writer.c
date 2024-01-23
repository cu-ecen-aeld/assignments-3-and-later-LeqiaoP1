#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    char filename[256];
    char stringbuf[256];

    openlog ("Assignment2", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

    if (argc < 3) {
        //printf("too few arguments.");
        syslog(LOG_ERR, "too few arguments");
        return 1;
    }

    strcpy(filename, argv[1]);
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        //printf("open new file to write failed.\n");
        syslog(LOG_ERR, "open new file to write failed");
        return 1;
    }

    strcpy(stringbuf, argv[2]);

    if (write(fd, stringbuf, strlen(stringbuf)) != -1)
        syslog(LOG_DEBUG, "Writing %s to %s", stringbuf, filename);
    else
        syslog(LOG_ERR, "Writing %s to %s failed!", stringbuf, filename);

    close(fd);
    return 0;
}
