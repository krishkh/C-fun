#include <stdio.h>

int main() {
    // Text colors
    printf("\033[31mThis is red text.\033[0m\n");
    printf("\033[32mThis is green text.\033[0m\n");
    printf("\033[34mThis is blue text.\033[0m\n");

    // Background colors
    printf("\033[41mThis is red background.\033[0m\n");
    printf("\033[42mThis is green background.\033[0m\n");

    // Bold and Underline styles
    printf("\033[1mThis is bold text.\033[0m\n");
    printf("\033[4mThis is underlined text.\033[0m\n");

    // Combining styles
    printf("\033[1;31mThis is bold red text.\033[0m\n");
    printf("\033[4;32mThis is underlined green text.\033[0m\n");

    return 0;
}
