#include "Ele.h"


Ele::Ele() {
    cur_floor = 1;
    dir = 0;
    waiting = 0;
    wait_len = 1;
}

int Ele::current() {
    return cur_floor;
}

int Ele::direction() {
    return dir;
}

void Ele::setDirection(int d) {
    dir = d;
}

int Ele::waitTime() {
    return waiting;
}

int Ele::waitLength() {
    return wait_len;
}

void Ele::setWaitLength(int w) {
    wait_len = w;
}

void Ele::add_stop(int stop) {
    // O(1)
    if (stops.empty()) {
        stops.push_back(stop);
        return;
    }
    
    int left = 0;
    int rite = stops.size()-1;
    int mid;
    
    // O(logn)
    while (rite >= left) { // binary search
        mid = (left+rite)/2;
        if (stops.at(mid) == stop) return; //don't need duplicates
        if (stops.at(mid) < stop) left = mid+1;
        else if (stops.at(mid) > stop) rite = mid-1;
    }
    
    // O(n)
    if (stops.at(mid) > stop) stops.insert(stops.begin()+mid,stop); //insert before
    else stops.insert(stops.begin()+mid+1,stop); //insert after
}

void Ele::update(list<People>& old) {
    if (waiting > 0) {
        --waiting; //all aboard!
        return;
    }
    
    if (stops.empty()) dir = 0; //nothing to do
    
    switch (dir) {
        case 2: //up
            if (stops.at(0) == cur_floor) {
                stops.erase(stops.begin()); //it's expected all stops are greater than cur_floor
                waiting = wait_len;
                takePeople(old);
                if (stops.empty()) dir = 0;
                break;
            }
            ++cur_floor;
            break;
        case 1: //down
            if (stops.at(stops.size()-1) == cur_floor) {
                stops.pop_back(); //it's expected all stops are less than cur_floor
                waiting = wait_len;
                takePeople(old);
                if (stops.empty()) dir = 0;
                break;
            }
            --cur_floor;
            break;
        default: //stopped
            if (!stops.empty()) {
                //checks the first one because it's expected all stops are along the same direction
                if (stops.at(0) > cur_floor) {
                    dir = 2; //go up
                    if (stops.at(0) == cur_floor) {
                        stops.erase(stops.begin());
                        waiting = wait_len;
                        takePeople(old);
                    }
                }
                else {
                    if (stops.at(stops.size()-1) == cur_floor) {
                        stops.pop_back();
                        waiting = wait_len;
                        takePeople(old);
                    }
                    dir = 1; //go down
                }
            }
    }
}
void Ele::takePeople(list<People>& old) {
    for (list<People>::iterator pit = old.begin(); pit != old.end(); ) {
        if (pit->current() == cur_floor && (pit->direction() == dir || stops.empty() ) ) {
            //remove person
            if (stops.empty()) dir = pit->direction();
            add_stop(pit->destination());
            old.erase(pit++);
        }
        else ++pit;
    }
}


void Ele::dumpdebug(ostream& out) {
    out << cur_floor << ", " << dir << ", " << waiting << ", " << wait_len;
    for (int i=0; i<stops.size(); ++i) {
        if (i%8 == 0) out << endl;
        out << "\t" << stops.at(i);
    }
    out << endl << endl;
}
