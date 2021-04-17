//
// Created by student on 08.06.2020.
//

#ifndef KINO_TICKET_H
#define KINO_TICKET_H

#include "smartPtrs.h"

class Client;
class Seans;

class Ticket {

    std::string state;
    const unsigned int ticketNumber;
    const ClientPtr client;
    const SeansPtr seans;
    bool valid;

public:
    Ticket(const std::string &state, const unsigned int ticketNumber, ClientPtr const client, SeansPtr const seans);

    virtual ~Ticket();

    // Getters

    const unsigned int getTicketNumber() const;
    const ClientPtr &getClient() const;
    const SeansPtr &getSeans() const;
    const std::string &getState() const;
    const std::string getTicketInfo() const;
    bool isValid() const;

    // Setters
    void setValid(bool valid);
    void setState(const std::string &state);
};


#endif //KINO_TICKET_H
