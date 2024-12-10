#include <stdio.h>
#include "parser.c" // Include your parser here
#include "parser.h" // Include the header file for parser

void generateAssembly(Node *node)
{
    if (!node)
        return;

    if (node->type == TOKEN_IDENTIFIER)
    {
        printf("LOAD %s\n", node->value); // Example assembly for loading a variable
    }
    // Add more mappings for +, -, assignments, and conditionals
}

int main()
{
    FILE *file = fopen("example.sl", "r");
    if (!file)
    {
        perror("Failed to open file");
        return 1;
    }

    tokenize(file); // Tokenize the input file
    rewind(file);   // Reset file pointer for parsing

    Node *ast = parse(file); // Parse the tokens into an AST
    fclose(file);

    generateAssembly(ast); // Generate assembly code from AST
    return 0;
}