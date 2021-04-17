//
// Created by student on 08.06.2020.
//

#include "repositories/TicketRepository.h"
#include <sstream>

TicketRepository::TicketRepository() {}

TicketRepository::~TicketRepository() {

}

void TicketRepository::add(TicketPtr const newTicket) {
    if(newTicket!=nullptr) tickets.push_back(newTicket);
}

const TicketPtr TicketRepository::get(const unsigned int &index) const {
    if(index<tickets.size()) return tickets[index];
    return nullptr;
}

const TicketPtr TicketRepository::find(TicketPredicate predicate) const {
    for(int i=0; i<tickets.size(); i++)
    {
        if(predicate(tickets[i])) return tickets[i];
    }
    return nullptr;
}

const std::vector<TicketPtr> TicketRepository::findAll(TicketPredicate allPredicate) const {
    std::vector<TicketPtr> v;
    for(int i=0; i<tickets.size(); i++)
    {
        if(allPredicate(tickets[i])) v.push_back(tickets[i]);
    }
    return v;
}

const unsigned int TicketRepository::size() const {
    return tickets.size();
}

const std::string TicketRepository::report() const {
    std::ostringstream out;
    for(int i=0; i<tickets.size(); i++)
    {
        out<<std::to_string(i+1)<<".   "<<tickets[i]->getTicketInfo()<<"\n";
    }
    return out.str();
}

const bool TicketRepository::deleteTicket(TicketPtr const ticket) {
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i]==ticket)
        {
            tickets[i]= nullptr;
            tickets.erase(tickets.begin() +i);
            return true;
        }
    }
    return false;
}

/*const std::string TicketRepository::reportOne(TicketPtr const ticket) const {
    std::ostringstream out;
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i]==ticket)
        {
            return tickets[i]->getTicketInfo();
        }
    }
    return "No ticket found";
}*/
