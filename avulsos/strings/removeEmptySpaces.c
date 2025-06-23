#include <stdio.h>
#include <string.h> // For strlen (optional, but good for understanding)
#include <ctype.h>  // For isspace()

void removeSpaces(char *str) {
	int non_space_count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isspace((unsigned char)str[i])) { // Use isspace() for all whitespace
			str[non_space_count] = str[i];
			non_space_count++;
		}
	}
	str[non_space_count] = '\0'; // Null-terminate the new string
}

int main() {
	char myString[] = "  Hello   World   from C!  ";
	printf("Original string: '%s'\n", myString);

	removeSpaces(myString);
	printf("String after removing spaces: '%s'\n", myString);

	return 0;
}
