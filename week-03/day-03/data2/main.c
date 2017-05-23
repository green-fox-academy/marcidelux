#include <stdio.h>

struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

int SumGold(struct Pirate* juggernaut, int size);
float AvarageGold(struct Pirate* juggernaut, int size);

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int main() {
    struct Pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    int all_the_gold = SumGold(pirates, 6);
    float avarage_gold = AvarageGold(pirates, 6);


    printf("All the gold: %d pieces\n\n", all_the_gold);
    printf("%.02f goldpiece / pirate\n\n", avarage_gold);



    return 0;
}


int SumGold(struct Pirate* juggernaut, int size){
    int gold = 0;
    for(int i = 0; i < size; i++){
        gold += juggernaut[i].gold_count;
    }
    return gold;
}

float AvarageGold(struct Pirate* juggernaut, int size){
    int gold = 0;
    for(int i = 0; i < size; i++){
        gold += juggernaut[i].gold_count;
    }
    return (float)gold/size;
}

float AvarageGold(struct Pirate* juggernaut, int size){





}
