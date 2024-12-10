#include <stdio.h>
#include <stdlib.h>
#include "lexer.c" // Include your lexer here

// Define basic AST structures
typedef struct Node
{
    TokenType type;
    char value[MAX_TOKEN_LEN];
    struct Node *left;
    struct Node *right;
} Node;

// Create a new AST node
Node *createNode(Token token)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = token.type;
    strcpy(node->value, token.text);
    node->left = node->right = NULL;
    return node;
}

// Parse variable declarations
Node *parseDeclaration(FILE *file)
{
    Token token;
    getNextToken(file, &token);
    if (token.type == TOKEN_IDENTIFIER)
    {
        return createNode(token);
    }
    printf("Syntax Error: Expected identifier after 'int'\n");
    exit(1);
}

// Parser driver function
void parse(FILE *file)
{
    Token token;
    while (1)
    {
        getNextToken(file, &token);
        if (token.type == TOKEN_EOF)
            break;

        if (token.type == TOKEN_INT)
        {
            Node *var = parseDeclaration(file);
            printf("Declared variable: %s\n", var->value);
            free(var);
        }
        // Extend this for assignments and conditionals
    }
}

int main()
{
    FILE *file = fopen("example.sl", "r");
    if (!file)
    {
        perror("Failed to open file");
        return 1;
    }
    parse(file);
    fclose(file);
    return 0;
}
