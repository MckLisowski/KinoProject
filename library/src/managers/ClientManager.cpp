//
// Created by student on 09.06.2020.
//

#include "managers/ClientManager.h"

ClientManager::ClientManager() {}

ClientManager::~ClientManager() {

}

ClientPtr ClientManager::registerClient(const std::string &mname, const std::string &msurname, const unsigned int mid,
                                   CTPtr const &mclientType) {
    if(getClientById(mid)==nullptr)
    {
        ClientPtr c=std::make_shared<Client>(mname, msurname, mid, mclientType);
        CR.add(c);
        return c;
    }
    return getClientById(mid);
}

const ClientPtr ClientManager::getClientById(const unsigned int clientID) const {
    ClientPredicate findClient = [&clientID](ClientPtr cPtr) ->bool
    {
        return (cPtr->getId()==clientID);
    };
    return CR.find(findClient);
}
/*
const ClientRepositoryPtr &ClientManager::getCr() const {
    return CR;
}*/

const std::string ClientManager::viewClients() const {
    return CR.report();
}

const ClientPtr ClientManager::getClient(const unsigned int index) const {
    return CR.get(index);
}



