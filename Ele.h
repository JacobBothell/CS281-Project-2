//Jacob Bothell
//CS303-Project-2

//Due 3-25-16

#ifndef ELE_H
#define ELE_H

#include <vector>
#include <list>
#include <ostream>

#include "People.h"

using namespace std;

class Ele
{
private:
    int cur_floor;  //current floor of the elevator
    int waiting;
    int wait_len;
	
    int dir;    //direction of travel   0 - no movement
                                    //  1 - down
                                    //  2 - up
	
    vector<int> stops;	//vector of floor stops
    
    void takePeople(list<People>& old);

public:
    Ele();
    
    void dumpdebug(ostream& out);
    
    int current();  //need getter
	
    int direction();    //need getter
    void setDirection(int d);
    
    int waitTime(); // >0 the door is open
    int waitLength();
    void setWaitLength(int w);
	
    void add_stop(int stop);    //need adds and sorts stop
	
    void update(list<People>& old);  //updates the status of elevator
                    //current floor, direction, stops
                    //called by E_Bank for each elevator
};

#endif
