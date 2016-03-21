//Jacob Bothell
//CS303-Project-2

//Due 3-25-16

#include <vector>

using namespace std;

class Ele
{
private:
	int cur_floor;		//current floor of the person
	
	int dir;			//direction of travel	0 - no movement
						//						1 - down
						//						2 - up
	
	vector<int> stops;	//vector of floor stops

public:
	int current();					//need getter
	
	int direction();				//need getter
	
	void add_stop(int stop);		//need adds and sorts stop
	
	void update();					//updates the status of elevator
									//current floor, direction, stops
									//called by E_Bank for each elevator
};