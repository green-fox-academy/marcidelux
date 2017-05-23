#include <stdio.h>

void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {

    //TODO:
    // Implement this function to create the union of a and b into the array result!
    if(l_a+l_b>l_res){
        printf("Lenth of Resh is too small");
        return;
    }

    for(int i=0; i<l_res; i++){
        if(i<l_a){
        *(result+i)=*(a+i);
        }else {
            *(result+i)=*(b+i-l_a);
        }
    }

    return;
}

int main(int argc, char** argv) {
    int a[3] = {1,2,3};
    int b[3] = {4,5,6};
    int c[6];
    safeUnion(a,3,b,3,c,6);
    for (int i = 0; i<6; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}
