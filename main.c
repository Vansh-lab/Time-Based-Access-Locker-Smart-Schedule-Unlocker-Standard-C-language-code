C, file-handling, system-time, beginner-project, CLI-tool, resume-project, ATS-friendly, access-control, logic-building
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define START_HOUR 9   // Access starts from 09:00
#define END_HOUR 17    // Access allowed till 17:59

int is_within_allowed_time() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int hour = timeinfo->tm_hour;

    return (hour >= START_HOUR && hour < END_HOUR);
}

void write_data() {
    FILE *fp = fopen("secure.txt", "a");
    if (!fp) {
        printf(" Error opening file for writing.\n");
        return;
    }

    char data[500];
    getchar(); // flush newline
    printf("Enter your note:\n ");
    fgets(data, sizeof(data), stdin);
    fprintf(fp, "%s", data);
    fclose(fp);
    printf(" Data written successfully.\n");
}

void read_data() {
    FILE *fp = fopen("secure.txt", "r");
    if (!fp) {
        printf(" File not found.\n");
        return;
    }

    char ch;
    printf("\n Contents of secure.txt:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf(" Time-Based Access Locker\n");
        printf("1. Write to secure file\n");
        printf("2. Read secure file\n");
        printf("0. Exit\n");
        printf("Choose:\n ");
        scanf("%d", &choice);

        if (!is_within_allowed_time()) {
            printf(" Access Denied: Outside allowed hours (%02d:00–%02d:00)\n", START_HOUR, END_HOUR);
            continue;
        }

        switch (choice) {
            case 1: write_data();
                break;
            case 2: read_data(); 
                break;
            case 0: printf(" Exiting...\n");
            return 0;
            default:
                printf(" Invalid option.\n");
            return 0;
        }
    }
}
