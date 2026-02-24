#include <stdio.h>

int main() {
    char message[100];
    int vowel_count = 0;
    int i = 0;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == 'a' || message[i] == 'e' || 
            message[i] == 'i' || message[i] == 'o' || 
            message[i] == 'u' || message[i] == 'A' || 
            message[i] == 'E' || message[i] == 'I' || 
            message[i] == 'O' || message[i] == 'U') {

            vowel_count++;
        }
    }

    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}