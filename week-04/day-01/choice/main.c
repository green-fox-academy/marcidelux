//make it work

void MemoryAdress (int num);
void CurrentValue (int num);
void DoubleItsValue (int* numberpointer);

int main(){

    int number = 12;
    int number_pointer = & number;
    int mode;

    printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n");

    while(mode != 0) {

        scanf("%d", &mode);
        switch (mode) {
            case 1 :
                MemoryAdress(number);
                break;
            case 2 :
                CurrentValue(number);
                break;
            case 3 :
                DoubleItsValue(number_pointer);
                break;
            default:
                printf("Wrong mode, if you want to exit type 0");
        }
    }
    return 0;
}

void MemoryAdress (int num){
    printf("memory address of the number is:%p\n", &num);
}

void CurrentValue (int num){
    printf("Current value of the number is:%d\n", num);
}

void DoubleItsValue (int* numberpointer){
    *numberpointer *= 2;
    printf("number has benn doubled\n");
}
