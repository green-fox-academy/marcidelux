#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergeArrays(int *array1, int sizeof_array1, int *array2, int sizeof_array2, int *resultarray, int sizeof_resultarray);

void main(){

    // Az &-operátorral lehet egy változó memóriacímét elkérni
    int number1 = 12345;
    printf("number1's value: %d\n", number1);
    printf("number1's memory adress: %p\n", &number1);

printf("_______________________________________________________________________________________\n\n");

    int number2 = 6789;
    int* number2_pointer = &number2; // itt létrehozunk egy int-re mutató pointert aminek az értékébe a number2 mamóriacímét írjuk be.
    printf("number2's value: %d\n", number2); // Simán kiírva a number2 értéke
    printf("number2's value printed with pointer: %d\n", *number2_pointer); // Most a number2_pointer rámutat a number2 értékére, ezt írjuk ki.

printf("_______________________________________________________________________________________\n\n");

    int number3 = 4325;
    int* number3_pointer = &number3; // pointerbe betötjük a number3 címét.
    printf("number3's value: %d\n", number3); // Simán kiírva a number3
    *number3_pointer = 666; // A pointeren keresztül elérjük a number3 értékét, és átírjuk.
    printf("number3's value after changed with pointer: %d\n", number3); //Változtatás után kiírva.

printf("_______________________________________________________________________________________\n\n");

    int numbers_array1[] = {5,3,2,7}; //Int tömb ami számokat tartalmaz
    int* targetnumber_pointer1; // Egy sima intre mutató pointer
    targetnumber_pointer1 = &numbers_array1[0]; // A tömbünk első elemének a címét belerakjuk a pointerbe.
    printf("numbers_array1's first element's value printed with pointer: %d\n", *targetnumber_pointer1);
    targetnumber_pointer1 = numbers_array1; // Itt az a lényeg hogy lássuk a tömbünk nevének az értéke az első elemének a memóriacíme.
    printf("numbers_array1's first element's value printed with pointer: %d\n", *targetnumber_pointer1);

printf("_______________________________________________________________________________________\n\n");

    int numbers_array2[] = {23, 42, 653, 2};
    int* targetnumber_pointer2 = &numbers_array2[0]; // Ugyan az mint ha int* targetnumber_pointer2 = numbers_array2;
    targetnumber_pointer2 += 2; // Az a lényeg, hogy a memóriában egymás mellé lettek lerakva a tömb elemei,
                                //így ha az első elem címéhez 2 őt adok hozzá akkor a 3. elemre fog mutatni.
    printf("numbers_array2 third element's value with modified pointer: %d\n", *targetnumber_pointer2);

    for (int i = 0; i < 4; i++){    //Pointerek felhasználásával egy forciklussal kiírjuk mind a 4 elemét. (Most nem szórakoztam tömbmérettel).
        targetnumber_pointer2 = &numbers_array2[i];
        printf("numbers_array2[%d]'s value with pointer: %d\n", i, *targetnumber_pointer2);
    }

printf("_______________________________________________________________________________________\n\n");

    int number4 = 100;
    int number5 = 200;
    int* number4_variable scopespointer = &number4;
    int* targetnumber_pointer3;

    targetnumber_pointer3 = number4_pointer; // Most a targetnumber_pointer3-ba beletöltöttük a number4 memóriacímét.
    printf("numbers4 value with targetnumber_pointer3: %d\n", *targetnumber_pointer3);

printf("_______________________________________________________________________________________\n\n");

    int number6 = 222;
    int number7 = 555;
    int* number6_pointer = &number7; //Bizony rosz helyre mutatnak a pointerek, ezt kell felcserélni.
    int* number7_pointer = &number6;
    int* memory_pointer1; // kell egy memória pointer.

    printf("number6's value before fixing the number6_pointer: %d\n", *number6_pointer);
    printf("number7's value before fixing the number7_pointer: %d\n", *number7_pointer);

    memory_pointer1 = number6_pointer; // memoryba belemegy anumber6_pointer-ben tárolt cím, ami a number7-re mutat
    number6_pointer = number7_pointer; // num6_pointer-be belemegy a num7-pointerben tárolt cím, ami a number6-osé
    number7_pointer = memory_pointer1; // S végül a num7_ponterbe belemegy a memoryban tárolt cím ami a number7-re mutat, ezzel a csere megtörtént.

    printf("number6's value with fixed number6_pointer: %d\n", *number6_pointer);
    printf("number7's value with fixed number7_pointer: %d\n", *number7_pointer);

printf("_______________________________________________________________________________________\n\n");

    int number8 = 33;
    int number9 = 777;
    int* number8_pointer = &number8;
    int* number9_pointer = &number9;

    printf("number8 before swap: %d\n", *number8_pointer);
    printf("number9 before swap: %d\n", *number9_pointer);
        //Most ki akarjuk cserélni a number8 értékét és a number9 értékét pointereket használva, most is kell egy memory.
    int memory;
        //Ugye amikor *van a pointer neve elött akkor az általa mutatott memóriacímen lévő ÉRTÉKRE hivatkozik.
    memory = *number8_pointer; // Memoryába belemászik a number8_pointer által mutatott number8 értéke.
    *number8_pointer = *number9_pointer; // a number8 értékébe belemegy a number9 értéke.
    *number9_pointer = memory; // S végül a number9 be belemegy a memoryban tárolt number8 értéke.

    printf("number8 after swap: %d\n", *number8_pointer);
    printf("number9 after swap: %d\n", *number9_pointer);

printf("_______________________________________________________________________________________\n\n");

    //Most 2 tömb elemeit akarjuk összefűzni.

    int numbers_array3[] = {1,2,3,4};
    int sizeof_numbers_array3 = sizeof(numbers_array3)/sizeof(numbers_array3[0]);

    int numbers_array4[] = {5,6,7,8};
    int sizeof_numbers_array4 = sizeof(numbers_array4)/sizeof(numbers_array4[0]);

    int sizeof_mergedarray = sizeof_numbers_array3 + sizeof_numbers_array4;
    int merged_array[sizeof_mergedarray];

    mergeArrays(numbers_array3, sizeof_numbers_array3, numbers_array4, sizeof_numbers_array4, merged_array, sizeof_mergedarray);

    for(int i = 0; i < sizeof_numbers_array3; i++) {
        printf("numbers_array3[%d]: %d\n", i, numbers_array3[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof_numbers_array4; i++) {
        printf("numbers_array4[%d]: %d\n", i, numbers_array4[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof_mergedarray; i++) {
        printf("mergedarray[%d]: %d\n", i, merged_array[i]);
    }

}

void mergeArrays(int *array1, int sizeof_array1, int *array2, int sizeof_array2, int *resultarray, int sizeof_resultarray){

    for(int i = 0; i < sizeof_resultarray; i++) {

        if(i<sizeof_array1){
            resultarray[i] = array1[i];
        }else{
            resultarray[i] = array2[i-sizeof_array1];
        }

    }
    return;
}
