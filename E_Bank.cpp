//Jacob Bothell

#include "E_Bank.h"

E_Bank::E_Bank(){}

E_Bank::E_Bank(int floors){
    for (int i = 0; i < floors; i++){
        Ele newele = Ele();
        lifts.push_back(newele);
    }
}

void E_Bank::request(list<People> new_requests)
{
	if (new_requests.empty() && req.empty())
		return;

	if (!(new_requests.empty())) {
            for (list<People>::iterator it=new_requests.begin(); it != new_requests.end(); ++it) {
                req.push_back(*it);
            }
            new_requests.clear();
        }

	list<People>::iterator pit;
	list<Ele>::iterator lit;

	for (pit = req.begin(); pit != req.end(); )
	{
		bool accepted = false;
		for (lit = lifts.begin(); lit != lifts.end(); lit++) {
			
			if (lit->direction() == 0 || pit->direction() == lit->direction())
			{

                            if (lit->direction() == 0) {
                                if (pit->current() > lit->current()) lit->setDirection(2); //up
                                else if (pit->current() < lit->current()) lit->setDirection(1); //down
                                else lit->setDirection(pit->direction());
                                    accepted = true;
                            }
                            else if (pit->current() < lit->current() && lit->direction() == 1)
                            {
                                    accepted = true;
                            }
                            else if (pit->current() > lit->current() && lit->direction() == 2)
                            {
                                    accepted = true;
                            }
                            
                            if (accepted == true)
                            {
                                lit->add_stop(pit->current());
                                req.erase(pit++);
                                break;
                            }
			}
                }
                if (!accepted) ++pit;
	}
	return;
}

void E_Bank::update(list<People>& old)
{
	list<Ele>::iterator lit;
	for (lit = lifts.begin(); lit != lifts.end(); lit++)
		lit->update(old);
	return;
}
