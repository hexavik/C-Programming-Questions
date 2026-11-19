/**
 * @file book_price_discount.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-07-31
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <stdio.h>

typedef struct Book {
    float price;
    char* title;
    char* author;
} Book;

//
// Avoid #define (macros) for the type safety and miscalculation
//
float discount_calculate(float price, uint8_t discount) {
    return (price - (price * discount / 100));
}

void price_display(Book* book, uint8_t discount) {
    if (!book) { printf("Bad Input\n"); return; }

    printf("Title:  %s\nAuthor: %s\nNew Price: $%f\n",
        book->title, book->author,
        discount_calculate(book->price, discount));
}

int main() {
    Book bk1 = {
        .title = "Pride and Prejudice",
        .author = "Austen",
        .price = 30.0f
    };

    price_display(&bk1, 15);

    return 0;
}
