//
// Created by student on 08.06.2020.
//

#include "model/Ticket.h"
#include <sstream>
#include <string>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Seans.h"

Ticket::Ticket(const std::string &state, const unsigned int ticketNumber,  ClientPtr const client,
                SeansPtr const seans) : state(state), ticketNumber(ticketNumber), client(client), seans(seans) { valid=1;}

Ticket::~Ticket() {}

    // Getters

const unsigned int Ticket::getTicketNumber() const {
    return ticketNumber;
}

const ClientPtr &Ticket::getClient() const {
    return client;
}

const SeansPtr &Ticket::getSeans() const {
    return seans;
}

const std::string &Ticket::getState() const {
    return state;
}

    // Setters

void Ticket::setState(const std::string &state) {
    Ticket::state = state;
}

const std::string Ticket::getTicketInfo() const {
    std::ostringstream out;
    out<<"\n====================================================================================================================\n"<<" Ticket number: "<<ticketNumber<<"\n\n Client Details:\n"<<client->getClientInfo()<<"\n\n Movie Details:\n"<<seans->getSeansInfo()<<"   Discounted ticket price: "<<std::fixed <<std::setprecision(2)<<getClient()->getClientType()->applyDiscount(getSeans()->getPrice())<<" zl"<<"\n\n Ticket type: "<<state<<"\n====================================================================================================================\n";
    return out.str();
}

void Ticket::setValid(bool valid) {
    Ticket::valid = valid;
}

bool Ticket::isValid() const {
    return valid;
}
