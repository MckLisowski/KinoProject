//
// Created by student on 07.06.2020.
//

#include "model/Client.h"
#include "model/ClientType.h"
#include <sstream>

Client::Client(const std::string &cname, const std::string &csurname, const unsigned int cid, CTPtr const &cclientType)
        : name(cname), surname(csurname), id(cid), clientType(cclientType) {}

Client::~Client() {}

    // Getters

const std::string &Client::getName() const {
    return name;
}

const std::string &Client::getSurname() const {
    return surname;
}

const unsigned int Client::getId() const {
    return id;
}

const CTPtr &Client::getClientType() const {
    return clientType;
}

const std::string Client::getClientInfo() const {
    std::ostringstream out;
    out<<" Name: "<<name<<"   Surname: "<<surname<<"   Client ID: "<<id<<"   Client type: "<<clientType->getCname()<<" ";
    return out.str();
}
