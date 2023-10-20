#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform decryption
char* decrypt(char* encryptedText) {
    char* decryptedText = strdup(encryptedText); // Create a copy of the input text
    int length = strlen(decryptedText);

    for (int i = 0; i < length; i++) {
        // Check if the character is at an even or odd index
        if (i % 2 == 0) {
            // Decrypt by decreasing the character's ASCII value
            decryptedText[i] -= 1;
            if (decryptedText[i] == 31) {
                decryptedText[i] = '~'; // Handle special case
            }
        } else {
            // Decrypt by increasing the character's ASCII value
            decryptedText[i] += 1;
            if (decryptedText[i] == 127) {
                decryptedText[i] = ' '; // Handle special case
            }
        }
    }
    return decryptedText;
}

int main(void) {
    // uid_t currentUid = getuid();
    // if (currentUid != 0x1092) {
    //     printf("UID %d started us, but we expect %d\n", currentUid, 0x1092);
    //     exit(1); // Exit with an error if the UID is not as expected
    // }

    char* token = decrypt("boe]!ai0FB@.:|L6l@A?>qJ}I");
    printf("Your token is: %s\n", token);

    free(token); // Free the dynamically allocated memory
    return 0;
}