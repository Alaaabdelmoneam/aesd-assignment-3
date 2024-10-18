#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Open syslog for logging
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required - writefile and writestr");
        closelog();
        exit(1);
    }

    char *writefile = argv[1];  // File path to write to
    char *writestr = argv[2];   // String to write to the file

    // Open the file for writing
    FILE *fptr = fopen(writefile, "w");
    if (fptr == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s: %s", writefile, strerror(errno));
        closelog();
        exit(1);
    }

    // Write the string to the file
    if (fprintf(fptr, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error: Could not write to file %s: %s", writefile, strerror(errno));
        fclose(fptr);
        closelog();
        exit(1);
    }

    // Log success with LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);

    // Close the file and syslog
    fclose(fptr);
    closelog();

    return 0;  // Successful completion
}
