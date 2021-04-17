//
// Created by student on 09.06.2020.
//

#ifndef KINOPROJECT_CLIENTMANAGER_H
#define KINOPROJECT_CLIENTMANAGER_H

#include "repositories/ClientRepository.h"
#include "model/Client.h"


class ClientManager {

   ClientRepository CR;

public:
    ClientManager();

    virtual ~ClientManager();

    ClientPtr registerClient(const std::string &mname, const std::string &msurname, const unsigned int mid, CTPtr const &mclientType);
    const ClientPtr getClientById(const unsigned int clientID) const;
    const ClientPtr getClient(const unsigned int index) const;
    const std::string viewClients() const;
};


#endif //KINOPROJECT_CLIENTMANAGER_H
