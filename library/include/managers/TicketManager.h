//
// Created by student on 10.06.2020.
//

#ifndef KINOPROJECT_TICKETMANAGER_H
#define KINOPROJECT_TICKETMANAGER_H


#include "repositories/TicketRepository.h"
#include "model/Ticket.h"

class TicketManager {

    TicketRepository TRvalid;
    TicketRepository TRoutdated;

public:
    TicketManager();

    virtual ~TicketManager();

    const TicketPtr newTicket(const std::string &state, const unsigned int mTicketNumber, ClientPtr const client, SeansPtr const seans);
    const TicketPtr getTicket(const unsigned int gindex) const;
    std::vector<TicketPtr> getClientsTickets(const unsigned int cid) const;
    const TicketPtr getTicketByNr(const unsigned int gticketNumber) const;
    const std::string viewTickets() const;
    const unsigned int getNumberOfTickets() const;
    bool checkAvability(SeansPtr seans) const;
    const bool deleteTicket(TicketPtr t);
    void archiveTickets();
};


#endif //KINOPROJECT_TICKETMANAGER_H
