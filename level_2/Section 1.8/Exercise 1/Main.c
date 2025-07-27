// Main.c
// Program to create a struct Article which has three fields
// 1. article_number
// 2. quantity
// 3. description (upto 20 characters)
// the article struct is initialized and printed using print() function

#include <stdio.h> // c style I/O

// define article struct with three fields
struct Article
{
    unsigned int article_number; // article number is unsigned as it cannot be negative
    unsigned int quantity;       // quantity is unsighed as it cannot be negative
    char description[21];        // description can be of max 20 characters. Null terminator '\0' is the 21st character
};

// define Print function that takes pointer to struct of type Article and prints all three fields
void Print(struct Article *article)
{
    printf("Article number: %i\n", article->article_number);
    printf("Article quantity: %i\n", article->quantity);
    printf("Article description: %s\n", article->description);
}

int main()
{
    struct Article firstArticle = {5, 200, "My first article"}; // initialize firstArticle struct of type Article

    Print(&firstArticle); // Use print to princt firstArticle by passing reference
    return 0;
}
