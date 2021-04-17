//
// Created by student on 08.06.2020.
//

#include "repositories/ClientRepository.h"
#include <sstream>

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

void ClientRepository::add(ClientPtr const newClient) {
    if(newClient!=nullptr) clients.push_back(newClient);
}

const ClientPtr ClientRepository::get(const unsigned int &index) const {
    if(index<clients.size()) return clients[index];
    return nullptr;
}

const ClientPtr ClientRepository::find(ClientPredicate predicate) const {
    for(int i=0; i<clients.size(); i++)
    {
        if(predicate(clients[i])) return clients[i];
    }
    return nullptr;
}

const std::vector<ClientPtr> ClientRepository::findAll(ClientPredicate allPredicate) const {
    std::vector<ClientPtr> v;
    for(int i=0; i<clients.size(); i++)
    {
        if(allPredicate(clients[i])) v.push_back(clients[i]);
    }
    return v;
}

const unsigned int ClientRepository::size() const {
    return clients.size();
}

const std::string ClientRepository::report() const {
    std::ostringstream out;
    for(int i=0; i<clients.size(); i++)
    {
        out<<std::to_string(i+1)<<". "<<clients[i]->getClientInfo()<<"\n";
    }
    return out.str();
}
