#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "morse.h"

#define MAX_MORSE 10
#define MAX_LINE 256

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node* root, const char* code, char letter) {
    Node* current = root;
    while (*code) {
        if (*code == '.') {
            if (!current->left)
                current->left = createNode(' ');
            current = current->left;
        } else if (*code == '-') {
            if (!current->right)
                current->right = createNode(' ');
            current = current->right;
        }
        code++;
    }
    current->data = letter;
}

void buildMorseTree(Node* root) {
    struct { char letter; char* code; } table[] = {
        {'A', "."},    {'B', "-"},  {'C', ".."},  {'D', ".-"},   {'E', "-."},
        {'F', "--"},  {'G', "..."},   {'H', "..-"},  {'I', ".-."},    {'J', ".--"},
        {'K', "-.."},   {'L', "-.-"},  {'M', "--."},    {'N', "---"},    {'O', "...."},
        {'P', "...-"},  {'Q', "..-."},  {'R', "..--"},   {'S', ".-.."},   {'T', ".-.-"},
        {'U', ".--."},   {'V', ".---"},  {'W', "-..."},   {'X', "-..-"},  {'Y', "-.-."},
        {'Z', "-.--"},
        {'1', "--.."}, {'2', "--.-"},{'3', "---."}, {'4', "----"}, {'5', "..-.."},
        {'6', "..-.-"}, {'7', ".-.-."},{'8', ".-.--"}, {'9', "-.-.."}, {'0', "-.-.-"},
        {' ', "--.-."}
    };

    for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
        insert(root, table[i].code, table[i].letter);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        if (root->data != ' ')
            printf("%c ", root->data);
        inorder(root->right);
    }
}

char* getMorse(char c) {
    c = toupper(c);
    struct { char letter; char* code; } table[] = {
        {'A', "."},    {'B', "-"},  {'C', ".."},  {'D', ".-"},   {'E', "-."},
        {'F', "--"},  {'G', "..."},   {'H', "..-"},  {'I', ".-."},    {'J', ".--"},
        {'K', "-.."},   {'L', "-.-"},  {'M', "--."},    {'N', "---"},    {'O', "...."},
        {'P', "...-"},  {'Q', "..-."},  {'R', "..--"},   {'S', ".-.."},   {'T', ".-.-"},
        {'U', ".--."},   {'V', ".---"},  {'W', "-..."},   {'X', "-..-"},  {'Y', "-.-."},
        {'Z', "-.--"},
        {'1', "--.."}, {'2', "--.-"},{'3', "---."}, {'4', "----"}, {'5', "..-.."},
        {'6', "..-.-"}, {'7', ".-.-."},{'8', ".-.--"}, {'9', "-.-.."}, {'0', "-.-.-"},
        {' ', "--.-."}
    };
    for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
        if (table[i].letter == c)
            return table[i].code;
    }
    return "";
}

void encode(const char* text) {
    for (int i = 0; i < strlen(text); i++) {
        char* code = getMorse(text[i]);
        if (*code)
            printf("%s  ", code);
    }
    printf("\n");
}

char decodeLetter(Node* root, const char* code) {
    Node* current = root;
    while (*code) {
        if (*code == '.')
            current = current->left;
        else if (*code == '-')
            current = current->right;
        code++;
    }
    return current ? current->data : '?';
}

void decode(Node* root, const char* morse) {
    char buffer[MAX_MORSE];
    int index = 0;
    for (int i = 0; i <= strlen(morse); i++) {
        if (morse[i] == ' ' || morse[i] == '\0') {
            buffer[index] = '\0';
            if (index > 0) {
                printf("%c", decodeLetter(root, buffer));
                index = 0;
            }
        } else {
            buffer[index++] = morse[i];
        }

        if (morse[i] == ' ' && morse[i+1] == ' ') {
            i++;
        }
    }
    printf("\n");
}

void encodeFile(Node* root, const char* infile, const char* outfile) {
    FILE* in = fopen(infile, "r");
    FILE* out = fopen(outfile, "w");

    if (!in || !out) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), in)) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\n') continue;
            char* code = getMorse(line[i]);
            if (*code)
                fprintf(out, "%s  ", code);
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);
    printf("File berhasil dikonversi ke Morse dan disimpan di %s\n", outfile);
}
