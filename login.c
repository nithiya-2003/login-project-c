#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char a;
    char p[20];
    char sp[20];
    printf("Enter your password: ");
    int i = 0;

    while (1) {
        a = _getch(); // Use _getch() for Windows systems

        if (a == 13) { // ASCII value for Enter key
            p[i] = '\0';
            break;
        } else {
            if (i < 19) { // Ensure we don't overflow the buffer
                p[i++] = a;
                printf("*");
            }
        }
    }

    printf("\nYou entered: %s\n", p);

    FILE *ptr;
    ptr = fopen("password.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open password file\n");
        return 1;
    }
    fscanf(ptr, "%s", sp);
    fclose(ptr);

    printf("Saved password: %s\n", sp);

    int le = strcmp(p, sp);
    if (le == 0) {
        printf("Login successful\n");
    } else {
        printf("Incorrect password\n");
    }

    return 0;
}
