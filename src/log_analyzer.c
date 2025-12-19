/*
File: log_analyzer.c
Description:
Reads a text/log file and analyzes:
- Number of lines
- Number of words
- Frequency of ERROR, WARNING, INFO messages
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[256];
    int lineCount = 0, wordCount = 0;
    int errorCount = 0, warningCount = 0, infoCount = 0;

    fp = fopen("../data/sample_log.txt", "r");
    if (!fp) {
        printf("Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        lineCount++;

        // Count words
        char *token = strtok(line, " \n");
        while (token != NULL) {
            wordCount++;

            if (strcmp(token, "error") == 0)
                errorCount++;
            else if (strcmp(token, "warning") == 0)
                warningCount++;
            else if (strcmp(token, "info") == 0)
                infoCount++;

            token = strtok(NULL, " \n");
        }
    }

    fclose(fp);

    printf("Total Lines   : %d\n", lineCount);
    printf("Total Words   : %d\n", wordCount);
    printf("ERROR Count   : %d\n", errorCount);
    printf("WARNING Count : %d\n", warningCount);
    printf("INFO Count    : %d\n", infoCount);

    return 0;
}
