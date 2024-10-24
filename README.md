## Complex Caesar Cipher Program

This project implements an enhanced version of the **Caesar Cipher**, a classical encryption technique, where letters of the alphabet are shifted by a 
specified number of positions. This program supports both **encryption** and **decryption** of text, allowing the user to input a message and select the 
shift value to encode or decode the message.

## Features
- Encrypt a message using a user-defined shift value.
- Decrypt a message using a user-defined shift value.
- Works with lowercase English alphabet characters.
- Non-alphabetic characters are preserved without changes.
- Allows flexible encryption by supporting both positive and negative shift values.

## How It Works

### Encryption
- A user provides a message and a shift value.
- Each letter in the message is shifted forward by the shift value provided.
- The result is displayed as the encrypted message.

### Decryption
- The program allows the user to reverse the encryption process by inputting the shift value used during encryption.
- Each letter is shifted backward by the provided value to recover the original message.

### Caesar Cipher Formula
The Caesar Cipher shifts each letter by a number of positions in the alphabet, wrapping around if necessary. For example, with a shift of 3:
- `a` becomes `d`
- `b` becomes `e`
- `z` becomes `c` (wraps around the alphabet)

The program works by converting characters to their numeric equivalents (0-25), applying the shift, and converting them back to characters.

## How to Use the Program

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/ComplexCaesarCipher.git
   ```
2. **Compile the Program** (if using a C compiler like GCC):
   ```bash
   gcc caesar_cipher.c -o caesar_cipher
   ```

3. **Run the Program**:
   ```bash
   ./caesar_cipher
   ```

4. **Choose Encryption or Decryption**:
   - Type `e` to encrypt a message.
   - Type `d` to decrypt a message.

5. **Enter the Message**:
   - Type the message you want to encrypt or decrypt (only lowercase alphabet characters will be processed).

6. **Enter the Shift Value**:
   - Provide the shift value (an integer between -25 and 25).
   - The program will display the encrypted or decrypted message accordingly.

## Example Usage

### Encrypting a Message
```bash
This program encrypts and decrypts messages using the Caesar Cipher.
Type e to encode or d to decode a message: e
Enter the string to encode: hello
Enter the shift value: 3
Encrypted message: khoor
```

### Decrypting a Message
```bash
Type e to encode or d to decode a message: d
Enter the string to encode: khoor
Enter the shift value: 3
Decrypted message: hello
```

## Prerequisites

- C Compiler (e.g., GCC, Clang)
- Terminal or Command Prompt for running the program

## Files in This Repository

- `caesar_cipher.c`: The source code for the Caesar Cipher program.
- `README.md`: This file, providing details on the program.

## License
This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as needed.

## Author
- **Nahom Gebreegziabher**

