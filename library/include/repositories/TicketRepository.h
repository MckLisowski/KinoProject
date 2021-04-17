//
// Created by student on 08.06.2020.
//

#ifndef KINOPROJECT_TICKETREPOSITORY_H
#define KINOPROJECT_TICKETREPOSITORY_H

#include "model/Seans.h"
#include "model/Ticket.h"
#include "model/Client.h"
#include <vector>
#include "smartPtrs.h"

class TicketRepository {

    std::vector<TicketPtr> tickets;

public:

    TicketRepository();
    virtual ~TicketRepository();

    void add(TicketPtr const newTicket);
    const TicketPtr get(const unsigned int &index) const;
    const TicketPtr find(TicketPredicate predicate) const;
    const std::vector<TicketPtr> findAll(TicketPredicate allPredicate) const;
    const unsigned int size() const;
    const std::string report() const;
    const bool deleteTicket(TicketPtr const ticket);
};


#endif //KINOPROJECT_TICKETREPOSITORY_H
