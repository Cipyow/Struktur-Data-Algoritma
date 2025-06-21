#include <stdio.h>
#include "morse.h"

int main() {
    Node* root = createNode(' ');
    buildMorseTree(root);

    printf("1. Inorder traversal pohon Morse:\n");
    inorder(root);

    printf("\n\n2. Encode teks: \"JTK Politeknik Negeri Bandung\"\n");
    encode("JTK Politeknik Negeri Bandung");

    printf("\n3. Decode Morse:\n");
    decode(root, ".-  -.-.  ..-.  .-..-..-..-.  -...  ..  ...  .-");

    printf("\n4. Encode dari file input.txt ke out.txt\n");
    encodeFile(root, "input.txt", "out.txt");

    return 0;
}