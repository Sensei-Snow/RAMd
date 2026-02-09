#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Welcome to the fake app !!!\n");

    printf("PID : %d\n\n", getpid());

    int value = 39;
    char text[] = "Hello";

    while (1) {
        char answer;

        printf("\rNombre : %d\n", value);
        printf("Adresse de nombre : %p\n\n", (void*)&value);

        printf("Texte : %s\n", text);
        printf("Adresse du texte : %p\n\n", (void*)&text);

        printf("Entrez votre choix [+ / - / =] : ");
        scanf(" %c", &answer);
        printf("\n");

        if (answer == '+') {
            value++;
        }
        else if (answer == '-') {
            value--;
        }
    }
    return 0;
}