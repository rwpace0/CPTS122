#include "test.h"
#include "dmm.h"

void test_insert() {
    printf("*****test_insert*****\n");

    Node* head = NULL;
    Record new;
    strcpy(new.artist, "Perry, Katy");
    strcpy(new.album, "Witness");
    strcpy(new.title, "Chained to the Rhythm");
    strcpy(new.genre, "pop");
    new.length.minutes = 4;
    new.length.seconds = 36;
    new.plays = -1;  
    new.rating = 6;   

    int result = insert_front(&head, new);
    if (result == 0 && head == NULL) {
        printf("test_insert PASSED: Insertion rejected .\n");
    }
    else {
        printf("test_insert FAILED: Insertion accepted.\n");
        if (head != NULL) {
            printf("Inserted record:\n"
                "  Artist: %s\n  Album: %s\n  Title: %s\n  Plays: %d\n  Rating: %d\n",
                head->data.artist, head->data.album, head->data.title,
                head->data.plays, head->data.rating);
        }
    }
    
    printf("\n");
}

