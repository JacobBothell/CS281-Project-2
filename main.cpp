#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "People.h"
#include "E_Bank.h"
#include "Ele.h"

using namespace std;

int run_sim(int floors, int elevators, int rate, int time, float ticktime, int maxpeep){
    list<People> New;
    list<People> Old;
    int timestamp = 0;
    int timewaited = 0;
    int totalpeeps = 0;
    
    

    E_Bank Bank(elevators);

    while (timestamp * ticktime < time){

        //generate people, possibly multiple.
        int genpeep = 0;
        while (genpeep < maxpeep && rand() % 100 + 1 < rate){
            People newperson(floors);
            New.push_back(newperson);
            ++totalpeeps;
            ++genpeep;
        }

        //send new people requests.
        Bank.request(New);

        for (list<People>::iterator itr = New.begin(); itr != New.end(); ++itr)
        {
            Old.push_back(New.front());
        }
        New.clear();
        
        //Update all elevators, put people on elevators
        Bank.update(Old);

        //For each person, they've waited an extra update (3 seconds)
        for (int i = 0; i < Old.size(); i++){
            timewaited++;
        }

        timestamp++; //a single update (3 seconds) has passed

    }
    return (timewaited * ticktime) / totalpeeps;
}

int main() {
    srand(std::time(NULL));
    int floors = 10;
    int lifts = 3;
    int rate = 25;
    int time = 240;
    float ticktime = 3;
    int maxpeep = 5;
    cout << "Num floors: ";
    cin >> floors;
    cout << "Num lifts: ";
    cin >> lifts;
    cout << "Rate: ";
    cin >> rate;
    cout << "Time: ";
    cin >> time;
    cout << "Tick time: ";
    cin >> ticktime;
    cout << "Max peep: ";
    cin >> maxpeep;
    
    cout << run_sim(floors, lifts, rate, time, ticktime, maxpeep) << " seconds is the average wait time";
    //system("Pause");
    return 0;
}
