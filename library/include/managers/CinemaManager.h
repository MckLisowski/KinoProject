//
// Created by student on 11.06.2020.
//

#ifndef KINOPROJECT_CINEMAMANAGER_H
#define KINOPROJECT_CINEMAMANAGER_H

#include "managers/ClientManager.h"
#include "managers/SeansManager.h"
#include "managers/TicketManager.h"

class CinemaManager {
    ClientManagerPtr const CM;
    SeansManagerPtr const SM;
    TicketManagerPtr const TM;

public:
    CinemaManager(SeansManagerPtr const cSM);

    virtual ~CinemaManager();

    const TicketPtr buyTicket(const unsigned int seansIndex, const std::string &mname, const std::string &msurname, const unsigned int mid, CTPtr const &mclientType);
    const TicketPtr makeReservation(const unsigned int seansNr, const std::string &mname, const std::string &msurname, const unsigned int mid, CTPtr const &mclientType);
    const std::string confirmReservation(const unsigned int ticketNr);
    const std::string viewClientsValidTickets(const unsigned int cid) const;
    const std::string viewAllValidTickets() const;
    const std::string  returnTicket(const unsigned int ticketNr);
    const std::string viewRepertuar() const;
};


#endif //KINOPROJECT_CINEMAMANAGER_H
