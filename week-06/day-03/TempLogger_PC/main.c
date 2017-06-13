#include <stdio.h>
#include <stdlib.h>
#include "rs232.h"
#include <string.h>

int main()
{
    char buffer[1];
    char temp[5];
    int port_index;
    char *p;
    int temp_int;
    int avarage_array[10];

    int enumerated_ports = comEnumerate();
    printf("Numbers of enumerated ports: %d\n", enumerated_ports);


    printf("Get Port name: %s\n", comGetPortName(0));

    port_index = comFindPort(comGetPortName(0));
    printf("find port: %d\n", port_index);

    comOpen(0, 115200);

    int j = 0;
    int i = 0;
    while (1) {
        if (comRead(port_index, buffer, 1)) {
            //buffer_cut = strtok(buffer, "\n");
            //printf("%s", buffer);

            if (buffer[0] != '\n') {
                temp[i] = buffer[0];
               // printf("i:%d,", i);
                i++;
            } else {
                temp[i] = '\0';
                //printf("%s\n", temp);
                i = 0;
                //free(temp);
                temp_int = atoi(temp);
                printf("temp_int: %d\n", temp_int);
                avarage_array[j] = temp_int;
                j++;
            }

            if(j == 10) {
                float avarage;
                int sum = 0;

                for(int k = 0; k < 10; k++) {
                    sum += avarage_array[k];
                }

                avarage = (float)sum / 10;
                printf("Avarage: %0.2f\n", avarage);
                j = 0;
            }
        }
    }

    return 0;
}
