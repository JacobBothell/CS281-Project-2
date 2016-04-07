//Jacob Bothell
//CS303-Project-2

//Due 3-25-16
#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
public:
    People();
    People(int floors);



    int direction() { return dir; }         	//need getter
	
    int current() { return cur_floor; }			//need getter
	
    int destination() { return dest; }          //need getter
    
    
    bool operator==(const People& rhs) { return cur_floor == rhs.cur_floor; }
    bool operator!=(const People& rhs) { return cur_floor != rhs.cur_floor; }
    bool operator>(const People& rhs) { return cur_floor > rhs.cur_floor; }
    bool operator<(const People& rhs) { return cur_floor < rhs.cur_floor; }
    bool operator>=(const People& rhs) { return cur_floor >= rhs.cur_floor; }
    bool operator<=(const People& rhs) { return cur_floor <= rhs.cur_floor; }

private:
    int cur_floor;	//current floor of the person

    int dir;		//direction of travel	0 - no movement
    //						1 - down
    //						2 - up

    int dest;		//destination floor of the person
};

#endif
