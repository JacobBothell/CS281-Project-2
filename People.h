//Jacob Bothell
//CS303-Project-2

//Due 3-25-16

class People
{
private:
	int cur_floor;	//current floor of the person
	
	int dir;		//direction of travel	0 - no movement
					//						1 - down
					//						2 - up
	
	int dest;		//destination floor of the person

public:
	int direction();		//need getter
	
	int current();			//need getter
	
	int destination();		//need getter
};