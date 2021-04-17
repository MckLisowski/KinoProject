//
// Created by student on 25.05.2020.
//

#ifndef CARRENTAL_SMARTPTRS_H
#define CARRENTAL_SMARTPTRS_H

#include <memory>
#include <functional>

class Seans;
class Client;
class Ticket;
class SeansRepository;
class ClientRepository;
class TicketRepository;
class TicketManager;
class SeansManager;
class ClientManager;
class ClientType;

typedef std::shared_ptr<Seans> SeansPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Ticket> TicketPtr;
typedef std::shared_ptr<ClientType> CTPtr;

/*typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<SeansRepository> SeansRepositoryPtr;
typedef std::shared_ptr<TicketRepository> TicketRepositoryPtr;*/

typedef std::shared_ptr<TicketManager> TicketManagerPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<SeansManager> SeansManagerPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(SeansPtr)> SeansPredicate;
typedef std::function<bool(TicketPtr)> TicketPredicate;


#endif //CARRENTAL_SMARTPTRS_H
