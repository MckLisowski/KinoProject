//
// Created by student on 10.06.2020.
//

#include "managers/TicketManager.h"

TicketManager::TicketManager() {}

TicketManager::~TicketManager() {}

const TicketPtr TicketManager::newTicket(const std::string &state, const unsigned int mTicketNumber, ClientPtr const client, SeansPtr const seans) {
    if(getTicketByNr(mTicketNumber)==nullptr)
    {
        TicketPtr t=std::make_shared<Ticket>(state, mTicketNumber, client, seans);
        TRvalid.add(t);
        return t;
    }
    return getTicketByNr(mTicketNumber);
}

const TicketPtr TicketManager::getTicketByNr(const unsigned int gTicketNumber) const {
    TicketPredicate findTicket = [&gTicketNumber](TicketPtr tPtr) ->bool
    {
        return (tPtr->getTicketNumber()==gTicketNumber);
    };
    TicketPtr t;
    if(TRvalid.find(findTicket)== nullptr)
        t=TRoutdated.find(findTicket);
    else
        t=TRvalid.find(findTicket);
    return t;
}

const TicketPtr TicketManager::getTicket(const unsigned int gindex) const {
    return TRvalid.get(gindex);
}

void TicketManager::archiveTickets() {
    for(int i=0; i<TRvalid.size(); i++)
    {
        TicketPtr tp = TRvalid.get(i);
        if(tp->getSeans()->getMovieDate()>pt::second_clock::local_time() || !tp->isValid())
        {
            TRoutdated.add(tp);
            TRvalid.deleteTicket(tp);
            tp->setValid(0);
        }
    }
}

bool TicketManager::checkAvability(SeansPtr seans) const {
    TicketPredicate findTickets = [&seans](TicketPtr tPtr) ->bool
    {
        return (tPtr->getSeans()==seans);
    };
    std::vector<TicketPtr> btickets=TRvalid.findAll(findTickets);
    return btickets.size() < seans->getScreenRoom();    //jak są miejsca zwraca true
}

const bool TicketManager::deleteTicket(TicketPtr t) {
    if(t!= nullptr)
    {
        bool b=true;
            b=TRvalid.deleteTicket(t);
        if(!b)
            TRoutdated.deleteTicket(t);
        return true;
    }
    return false;
}

const std::string TicketManager::viewTickets() const {
    return TRvalid.report();
}

const unsigned int TicketManager::getNumberOfTickets() const {
    return TRvalid.size();
}

std::vector<TicketPtr> TicketManager::getClientsTickets(const unsigned int cid) const {
    TicketPredicate findTickets = [&cid](TicketPtr tPtr) ->bool
    {
        return (tPtr->getClient()->getId()==cid);
    };
    return TRvalid.findAll(findTickets);
}

