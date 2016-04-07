#include "People.h"
#include <cstdlib>

People::People(){

}

People::People(int floors){
    dest = cur_floor = rand() % floors + 1; //random floor
    while (dest == cur_floor){
        dest = rand() % floors + 1; //random dest (protects against dest == cur_floor
    }
    if (dest > cur_floor) dir = 2; //set appropriate direction
    else dir = 1;
}
