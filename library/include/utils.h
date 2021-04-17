//
// Created by student on 23.05.2020.
//

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H

#include "smartPtrs.h"

class ClientRepository;
class SeansRepository;
class TicketRepository;
/*class ClientManager;
class SeansManager;
class TicketManager;*/


namespace utils {
     void clientRepositoryObjects(ClientRepository * CR, unsigned int number);
     void ticketRepositoryObjects(TicketRepository * TR, SeansRepository * SR, ClientRepository * CR,  unsigned int number);
     void seansRepositoryObjects(SeansRepository * SR, unsigned int number);

    void clientManagerObjects(ClientManagerPtr CM, unsigned int number);
    void ticketManagerObjects(TicketManagerPtr TR, SeansManagerPtr SR, ClientManagerPtr CR,  unsigned int number);
    void seansManagerObjects(SeansManagerPtr SM, unsigned int number);
};


#endif //CARRENTAL_UTILS_H
