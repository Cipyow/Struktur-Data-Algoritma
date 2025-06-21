#ifndef MORSE_H
#define MORSE_H

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data);
void insert(Node* root, const char* code, char letter);
void buildMorseTree(Node* root);
void inorder(Node* root);
char* getMorse(char c);
void encode(const char* text);
char decodeLetter(Node* root, const char* code);
void decode(Node* root, const char* morse);
void encodeFile(Node* root, const char* inputFile, const char* outputFile);

#endif