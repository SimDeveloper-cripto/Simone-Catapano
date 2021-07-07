#include <stdio.h>

struct card {
    char *face;
    char *suit;
};

int main(void){
    struct card carta; 
    struct card *cartaptr; // pointer to next_node.

    carta.face = "King";
    carta.suit = "Hearts"; 

    // facciamo si che il puntatore faccia riferimento alla variabile di tipo struct card.
    cartaptr = &carta; 

    printf("%s%s%s\n%s%s%s\n%s%s%s\n", carta.face, " of " ,carta.suit, 
            (*cartaptr).face, " of " ,(*cartaptr).suit,
            cartaptr->face, " of " ,cartaptr->suit );

    return 0;
}