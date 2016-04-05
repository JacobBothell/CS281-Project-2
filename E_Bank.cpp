//Jacob Bothell

#include "E_bank.h"

void E_Bank::request(list<People> new_requests)
{
	if (new_requests.empty() && req.empty())
		return;

	if (!(new_requests.empty()))
		req.merge(new_requests);

	list<People>::iterator pit;
	list<Ele>::iterator lit;

	for (pit = req.begin(); pit != req.end(); pit++)
	{
		bool accepted = false;
		for (lit = lifts.begin(); lit != lifts.end(); lit++)
			
			if (pit->direction() == lit->direction())
			{

				if (pit->current < lit->current && lit->direction() == 1)
				{
					lit->add_stop(*pit);
					accepted = true;
				}
				else if (pit->current > lit->current && lit->direction() == 2)
				{
					lit->add_stop(*pit);
					accepted = true;
				}
			}
			if (accepted == true)
			{
				req.remove(*pit);
				break;
			}
	}
	return;
}

void E_Bank::update()
{
	list<Ele>::iterator lit;
	for (lit = lifts.begin(); lit != lifts.end(); lit++)
		lit->update();
	return;
}
