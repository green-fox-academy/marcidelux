#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

void CarPrinter (struct Car vehicle);
// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {

    struct Car car1;
    car1.gas = 3;
    car1.km = 12501.32;
    car1.type = VOLVO;

    struct Car car2;
    car2.km = 5411.72;
    car2.type = TESLA;

    CarPrinter(car1);
    CarPrinter(car2);


    return 0;
}

void CarPrinter (struct Car vehicle){

    switch(vehicle.type){
        case 0 :
            printf("Volvo\n");
            printf("%.02fkm\n",vehicle.km);
            printf("%.02f -gas level\n",vehicle.gas);
            break;
        case 1 :
            printf("Toyota\n");
            printf("%.02fkm\n",vehicle.km);
            printf("%.02f -gas level\n",vehicle.gas);
            break;
        case 2 :
            printf("Landrover\n");
            printf("%.02fkm\n",vehicle.km);
            printf("%.02f -gas level\n",vehicle.gas);
            break;
        case 3 :
            printf("Tesla\n");
            printf("%.02fkm\n",vehicle.km);
            break;
        default :
            printf("Its not a car");
    }
    printf("\n");

}
/*			  !         !          
			 ! !       ! !          
			! . !     ! . !          
			   ^^^^^^^^^ ^            
			 ^             ^          
		   ^  (0)       (0)  ^       
		  ^        ""         ^       
		 ^   ***************    ^     
	   ^   *                 *   ^    
	  ^   *   /\   /\   /\    *    ^   
	 ^   *                     *    ^
	^   *   /\   /\   /\   /\   *    ^
   ^   *                         *    ^
   ^  *                           *   ^
   ^  *                           *   ^
	^ *                           *  ^  
	 ^*                           * ^ 
	  ^ *                        * ^
	  ^  *                      *  ^
/*		^  *       ) (         * ^
