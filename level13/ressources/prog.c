#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decrypt(char* encryptedText) {
	// [...]
}

int main(void) {
	uid_t currentUid = getuid();
	if (currentUid != 0x1092) {
		printf("UID %d started us, but we expect %d\n", currentUid, 0x1092);
		exit(1);
	}

	char* token = decrypt("boe]!ai0FB@.:|L6l@A?>qJ}I");
	printf("Your token is: %s\n", token);

	free(token);
	return (0);
}
