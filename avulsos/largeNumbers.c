// C program to handle large numbers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add two large numbers
void addLargeNumbers(char* num1, char* num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int i;

    // Make both numbers of equal length
    while (len1 < len2) {
        // Prepend zero in num1
        memmove(num1 + 1, num1, len1 + 1);
        num1[0] = '0';
        len1++;
    }
    while (len2 < len1) {
        // Prepend zero in num2
        memmove(num2 + 1, num2, len2 + 1);
        num2[0] = '0';
        len2++;
    }

    // Add digits from right to left
    for (i = len1 - 1; i >= 0; i--) {
        int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
        num1[i] = (digit % 10) + '0';
        carry = digit / 10;
    }

    // If there is a carry after adding all digits
    if (carry) {
        memmove(num1 + 1, num1, len1 + 1);
        num1[0] = carry + '0';
    }
}

int main()
{
    char num1[1000] = "979879879879879879879879879879879879798798798321i2759872405982475264572495827409877";
    char num2[1000] = "1444444497987987135798451453464654";

    printf("%ld\n", strlen(num1));
    printf("%ld\n", strlen(num2));

    addLargeNumbers(num1, num2);

    printf("Sum: %s\n", num1);

    return 0;
}
