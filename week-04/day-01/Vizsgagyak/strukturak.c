#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    // Ez egy listaszerűség melynek az elemei ezek, viszont igazából mindegyik csak egy szám az első a 0.
    // a második az 1 és a harmadik a 2 nek megelelő számok.
enum price {Cheap, Affordeable, Expensive};

    // Ez itt az autók struktúrájának az egyik típusú deklarálása. van benne char, int, float és egy enum.
struct Cars{
    char type[50];
    int ccm;
    float maxSpeed;
    enum price carprice;
};
    // a printfügvényt itt említeni kell hogy van ilyen hogy a complier ne fossa magát össze.
void PrintCars (struct Cars cararr[], int size);


void main(){
        // Csináltunk egy darab autót a változó neve car1
    struct Cars car1;
        // Itt feltöltjük a változóit
    strcpy(car1.type, "Opel");
    car1.ccm = 2400;
    car1.maxSpeed = 230.43;
    car1.carprice = Affordeable;
        //Kiírása az 1-es autónak
    printf("car1: \n");
    printf("type: %s\n", car1.type);
    printf("Engine: %d ccm\n", car1.ccm);
    printf("maxspeed: %.02f km/h\n", car1.maxSpeed);
    printf("Price: %d\n\n", car1.carprice); // Ez '1'-et fog kiírni, mert az enumnak a 2.eleme az Affordeable

        //Második autót is megcsináljuk, de itt már egy speckó módon értékeket is adunk a változóinak.
    struct Cars car2 = {"Hummer", 4000, 200.12, Expensive};
        //Ugyan úgy írjuk ki mint az 1-est
    printf("car2: \n");
    printf("type: %s\n", car2.type);
    printf("Engine: %d ccm\n", car2.ccm);
    printf("maxspeed: %.02f km/h\n", car2.maxSpeed);
    printf("Price: %d\n\n", car2.carprice);

        //Ez már egy autókat tartalmazó tömb, aminek az elemeit egyből fel is töltjük.
        //Ha szeretnénk hivatkozni egy autóra a tömbön belül akkor azt a cararray[i]-vel tudjuk megtenni, mos ez a nevük a car1, car2 helyett.
    struct Cars cararray[] = {
    {"Ferrari", 3500, 350.21, Expensive},
    {"Trabant", 1085, 101.46, Cheap},
    {"Audi", 1800, 180.56, Affordeable},
    };
        //Itt a tömb első autójának azaz a 0-ás indexűnek írjuk ki az adatait külön külön.
    printf("First car from the array:\n");
    printf("type: %s\n", cararray[0].type);
    printf("Engine: %d ccm\n", cararray[0].ccm);
    printf("maxspeed: %.02f km/h\n", cararray[0].maxSpeed);
    printf("Price: %d\n\n", cararray[0].carprice);

        //SemiProfi fokozat, egy függvénnyel kiiratjuk az összes autót a tömbből. Ehhez kell a tömb  hossza is.
    int size = sizeof(cararray)/sizeof(cararray[0]);
    printf("Cars in the array one by one:\n");
    PrintCars(cararray, size);
}

void PrintCars (struct Cars cararr[], int size){
        //Öreg forciklus egyenként végigmegy 0-tól a hossz-1 ig azaz minden elemen.
    for(int i = 0; i < size; i++){
        printf("type: %s\n", cararr[i].type);
        printf("Engine: %d ccm\n", cararr[i].ccm);
        printf("maxspeed: %.02f km/h\n", cararr[i].maxSpeed);
            //Itt van egy switch ami szépen visszaírja hogy most drága e vagy sem.
        switch (cararr[i].carprice){
            case 0 :
                printf("Price: Cheap\n\n");
                break;
            case 1 :
                printf("Price: Affordeable\n\n");
                break;
            case 2 :
                printf("Price: Expensive\n\n");
                break;
            default :
                printf("Price: This is not a Car\n\n");
        }
    }
}