//Jacob Bothell
//CS303-Project-2

//Due 3-25-16

#include"People.h"
#include"Ele.h"

#include <list>

using namespace std;

class E_Bank
{
private:
	list<People> req;
	list<Ele> lifts;

public:
    E_Bank();
    E_Bank(int elevators);

	void request(list<People> new_requests);	//processes requests made by People
												//adds request to appropriate elevator
	
	void update(list<People>& old);								//updates the status of elevator
												//current floor, direction, stops
												//called by E_Bank for each elevator
};
