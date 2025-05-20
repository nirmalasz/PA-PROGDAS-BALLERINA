#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void menuJobSeeker();
void menuUMKM();

int main(){
    int choice;

    while (1) {
        printf("=== Jobmaking App ===\n");
        printf("Select user type:\n");
        printf("1. Job Seeker\n");
        printf("2. UMKM / Company\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                menuJobSeeker();
                break;
            case 2:
                menuUMKM();
                break;
            case 3:
                printf("Exiting application. Thank you!\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}

void menuJobSeeker() {
    int choice;
    printf("\n--- Job Seeker Menu ---\n");
    printf("(Menu options to be added here)\n");
    printf("Press any key to return to main menu...\n");
    getchar(); // to consume leftover newline
    getchar();
}

void menuUMKM() {
    int choice;
    printf("\n--- UMKM / Company Menu ---\n");
    printf("(Menu options to be added here)\n");
    printf("Press any key to return to main menu...\n");
    getchar(); // to consume leftover newline
    getchar();
}





