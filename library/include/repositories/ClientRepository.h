//
// Created by student on 08.06.2020.
//

#ifndef KINOPROJECT_CLIENTREPOSITORY_H
#define KINOPROJECT_CLIENTREPOSITORY_H

#include "model/Client.h"
#include <vector>
#include "smartPtrs.h"

class ClientRepository {

    std::vector<ClientPtr> clients;

public:

    ClientRepository();
    virtual ~ClientRepository();

    void add(ClientPtr const newClient);
    const ClientPtr get(const unsigned int &index) const;
    const ClientPtr find(ClientPredicate predicate) const;
    const std::vector<ClientPtr> findAll(ClientPredicate allPredicate) const;
    const unsigned int size() const;
    const std::string report() const;


};


#endif //KINOPROJECT_CLIENTREPOSITORY_H
