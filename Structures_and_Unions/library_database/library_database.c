/**
 * @file library_database.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct Book {
    char name[50];
    float price;
} Book;

typedef struct Library {
    Book books[20];
    size_t count;
} Library;

/**
 * @brief Initialize the library with the library structure
 * 
 * @param lib Input existing library struct
 */
void library_init(Library* lib) {
    if (!lib) { return; }

    lib->count = 0;
}

/**
 * @brief Add a single book entry inside the Library
 * 
 * @param lib Input existing library struct
 * @param book Input existing book struct
 */
void library_add_book(Library* lib, Book* book) {
    if (!lib || !book) { return; }
    lib->books[lib->count] = *book;
    lib->count += 1;
}

/**
 * @brief Search a particular entry inside the whole library
 * 
 * @param lib Input existing library struct
 * @param bookname Input string to search within the library
 * @return const char* Output book name if found else nullptr
 */
const char* library_search_book(Library* lib, const char* bookname) {
    if (!lib || !bookname) { return nullptr; }

    for (size_t i = 0; i < lib->count; ++i) {
        if (strstr(lib->books[i].name, bookname)) {
            return lib->books[i].name;
        }
    }

    return nullptr;
}

int main() {
    Library lib;
    library_init(&lib);

    Book b1 = { "To Kill a Mockingbird", 23.45 };
    library_add_book(&lib, &b1);

    Book b2 = { "How to Trade in Stock", 10.00 };
    library_add_book(&lib, &b2);

    printf("Find book result: ");
    printf("%s\n", library_search_book(&lib, "Mockingbird"));

    return 0;
}
