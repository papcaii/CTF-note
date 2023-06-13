//gcc pwn1.c -o pwn1 -no-pie -s

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#define MAX_CONTENT_LENGTH 1000

char name[32];
FILE *filePtr = NULL;
char fileContent[MAX_CONTENT_LENGTH];

void openFile() {
    if (filePtr != NULL) {
        printf("A file is already opened. Please close it before opening a new file.\n");
        return;
    }

    char filename[100];
    printf("Enter the filename: ");
    scanf("%99s", filename);

    // Check if the filename contains the flag
    const char* flag = "flag";
    if (strstr(filename, flag) != NULL) {
        printf("Ha, what are you trying to do ?!\n");
        return;
    }

    // Open the file
    filePtr = fopen(filename, "r");
    if (filePtr == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    puts("Ok, this file is yours");
}

void readFile() {

    memset(fileContent, 0, sizeof(fileContent));
    if (filePtr == NULL) {
        printf("No file is currently opened.\n");
        return;
    }

    // Read the content from the file
    if (fgets(fileContent, sizeof(fileContent), filePtr) == NULL) {
        printf("Failed to read the file.\n");
        return;
    }

    printf("Read successful\n");
}

void printFileContent() {
    if (strchr(fileContent, '}') != 0) {
        printf("Nothing for you!!! Bye~\n");
        exit(1);
    }

    puts(fileContent);
}

void menu() {
	puts("---------------MENU---------------");
	puts("  1. Open");
  	puts("  2. Read");
  	puts("  3. Write");
  	puts("  4. Exit");
  	puts("----------------------------------");
  	printf("Your choice :");
}

char generateRandomHexValue() {
    return rand() % 16;  // Generates a random number between 0 and 15 (inclusive)
}

void custom_read(char *input, int maxLength) {
    scanf("%16[^\n]", input);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
    	input[length - 1] = '\0';
    }
}

void handler(int signum) {
    // Signal handler code
    puts("Time out!!! Bye~\n");
    
    exit(1);
}

int init() {
    int result;
    
    setvbuf(stdout, NULL, _IONBF, 0);
    signal(0xe, handler);
    result = alarm(0x3c);
    return result;
}

int main() {

    init();

    srand(time(NULL));  // Seed the random number generator with the current time
	
    char input[16];	
    char password[16];

    // Generate random hex values and store them in the array
    for (int i = 0; i < 16; i++) {
        password[i] = generateRandomHexValue();
    }
    
    memset(input, 0, sizeof(input));
    printf("Are you Huster? Show me your ID: ");
    custom_read(input, sizeof(input));
    
    int n = strlen(input);
    
    if (strncmp(input, password, n) == 0) {
        puts("Ohh... so you can use the newest tool I just found");
    } else {
        printf("Do you forgot your ID, so badd !!!");
        exit(1);
    }
    
    int choice;
    puts("Please don't break my program T_T\n");
    
    while (1) {
	menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                openFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                printFileContent();
                break;
            case 4:
            	puts("oh... I forgot asking your name");
            	printf("What is your name: ");
            	scanf("%s", name);
            	printf("See you soon, %s !!!\n", name);
	    	
	    	if (filePtr != NULL) {
        		fclose(filePtr);
    		}
    		
                exit(1);
            default:
                printf("Invalid choice\n");
                exit(1);
                break;
        }

        printf("\n");
    }

    return 0;
}
