#include <stdio.h>
#include <string.h>
#define N 100

/**
 * Converts a character in the message using a modified Caesar Cipher
 * with an additional layer of substitution.
 *
 * Pre-conditions:
 * - The message contains valid characters (lowercase letters).
 * - 'c' must be 'e' for encryption or 'd' for decryption.
 * - The key is used to determine the shift for each character.
 * - A second substitution layer adds more complexity.
 *
 * Post-conditions:
 * - The character at position 'n' in the message is shifted based on
 *   the key and further substituted.
 *
 * \param message The original message array.
 * \param newmessage The array to store the shifted message.
 * \param n The index of the character to convert.
 * \param key The key used to determine shifts.
 * \param c Specifies whether to encode ('e') or decode ('d').
 */
void convert(char message[], char newmessage[], int n, char key[], char c)
{
    int shift = key[n % strlen(key)] - 'a'; // Get shift from key based on position
    int base_shift, mod_shift;

    if (c == 'e')
    {
        base_shift = message[n] - 'a';               // Convert character to 0-25 range
        mod_shift = (base_shift + shift) % 26;       // Apply the key-based shift
        newmessage[n] = mod_shift + 'a';             // Convert back to ASCII
        newmessage[n] = 'z' - (newmessage[n] - 'a'); // Second layer of substitution
    }
    else if (c == 'd')
    {
        newmessage[n] = 'z' - (message[n] - 'a'); // Reverse second layer substitution
        base_shift = newmessage[n] - 'a';         // Convert character to 0-25 range
        mod_shift = (base_shift - shift);         // Reverse key-based shift
        if (mod_shift < 0)
        {
            mod_shift += 26;
        }
        newmessage[n] = mod_shift + 'a'; // Convert back to ASCII
    }
}

/**
 * Encrypts the given message using a more complex Caesar Cipher.
 *
 * Pre-conditions:
 * - The message contains lowercase letters and may include non-alphabetic characters.
 * - A key is provided to determine variable shifts.
 *
 * Post-conditions:
 * - Prints the encrypted version of the message.
 *
 * \param message The original message to encrypt.
 * \param key The key used for the variable shifts.
 */
void encrypt(char message[], char key[])
{
    char newmessage[N];
    int n = 0;

    while (message[n] != '\0')
    {
        if (message[n] >= 'a' && message[n] <= 'z')
        {
            convert(message, newmessage, n, key, 'e'); // Encrypt character
        }
        else
        {
            newmessage[n] = message[n]; // Keep non-lowercase letters unchanged
        }
        n++;
    }
    newmessage[n] = '\0'; // Null-terminate the new message
    printf("Encrypted message: %s\n", newmessage);
}

/**
 * Decrypts the given message using the more complex Caesar Cipher.
 *
 * Pre-conditions:
 * - The message contains lowercase letters and may include non-alphabetic characters.
 * - A key is provided to reverse the variable shifts.
 *
 * Post-conditions:
 * - Prints the decrypted version of the message.
 *
 * \param message The original encrypted message to decrypt.
 * \param key The key used for the variable shifts.
 */
void decrypt(char message[], char key[])
{
    char newmessage[N];
    int n = 0;

    while (message[n] != '\0')
    {
        if (message[n] >= 'a' && message[n] <= 'z')
        {
            convert(message, newmessage, n, key, 'd'); // Decrypt character
        }
        else
        {
            newmessage[n] = message[n]; // Keep non-lowercase letters unchanged
        }
        n++;
    }
    newmessage[n] = '\0'; // Null-terminate the new message
    printf("Decrypted message: %s\n", newmessage);
}

/**
 * Main function to interact with the user.
 *
 * Pre-conditions:
 * - User inputs either 'e' to encrypt or 'd' to decrypt a message.
 *
 * Post-conditions:
 * - Based on user input, either the encrypt or decrypt function is called to handle the message.
 *
 * \return Always returns 0.
 */
int main(void)
{
    char message[N], key[N];
    char EorD;

    printf("This program encrypts and decrypts messages using an enhanced Caesar Cipher.\n");
    printf("Type e to encode or d to decode a message: ");
    scanf(" %c", &EorD); // Get user's choice to encrypt or decrypt

    if (EorD == 'e')
    {
        printf("Enter the string to encode: ");
        scanf("%s", message); // Read the message to encode

        printf("Enter the key for encryption: ");
        scanf("%s", key); // Read the key for variable shifting

        encrypt(message, key); // Encrypt the message
    }
    else if (EorD == 'd')
    {
        printf("Enter the string to decode: ");
        scanf("%s", message); // Read the encrypted message to decode

        printf("Enter the key for decryption: ");
        scanf("%s", key); // Read the key for reversing the shifts

        decrypt(message, key); // Decrypt the message
    }
    else
    {
        printf("Valid options are 'e' to encode and 'd' to decode\n");
    }

    return 0;
}
