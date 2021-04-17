//
// Created by student on 11.06.2020.
//

#include "managers/CinemaManager.h"

CinemaManager::CinemaManager(SeansManagerPtr const cSM) : SM(cSM), CM(std::make_shared<ClientManager>()), TM(std::make_shared<TicketManager>()){}

CinemaManager::~CinemaManager() {}


const TicketPtr  CinemaManager::buyTicket(const unsigned int seansIndex, const std::string &mname, const std::string &msurname, const unsigned int mid, CTPtr const &mclientType) {
    SeansPtr s=SM->getSeans(seansIndex-1);   //wybrany z listy seansów numer zmienjsza o 1 i sprawdza czy w repozytorium seansów istnieje seans pod takim indexem
    if(s== nullptr) return nullptr;
    if(TM->checkAvability(s)) {
        ClientPtr c = CM->registerClient(mname, msurname, mid, mclientType);
        const unsigned int size = TM->getNumberOfTickets();
        TicketPtr t = TM->newTicket("bought", size + 10, c, s);
        return t;
    }
        return nullptr;
}

const std::string CinemaManager::viewClientsValidTickets(const unsigned int cid) const {
    std::ostringstream out;
    std::vector<TicketPtr> ctickets=TM->getClientsTickets(cid);
    for(int i=0; i<ctickets.size(); i++)
    {
        out<<"\n"<<i+1<<". "<<ctickets[i]->getTicketInfo();
    }
    if(out.str()=="") return "Brak biletow do wyswietlenia \n";
    return out.str();
}

const std::string CinemaManager::viewAllValidTickets() const {

    if(TM->viewTickets()=="") return "Brak biletow do wyswietlenia \n";
    return TM->viewTickets();
}

const std::string CinemaManager::returnTicket(const unsigned int ticketNr) {
    //TM->getTicket(ticketNr)->setValid(false);
    if(TM->deleteTicket(TM->getTicketByNr(ticketNr))) return "Bilet zwrocony pomyslnie \n";
    return "Niestety nie udalo sie zwrocic biletu \n";
}

const TicketPtr CinemaManager::makeReservation(const unsigned int seansNr, const std::string &mname, const std::string &msurname, const unsigned int mid, CTPtr const &mclientType) {
    SeansPtr s=SM->getSeans(seansNr-1);
    if(s== nullptr) return nullptr;
    if(TM->checkAvability(s)) {
        ClientPtr c = CM->registerClient(mname, msurname, mid, mclientType);
        const unsigned int size = TM->getNumberOfTickets();
        TicketPtr t = TM->newTicket("reservation", size + 100, c, s);
        return t;
    }
        return nullptr;
}

const std::string CinemaManager::confirmReservation(const unsigned int ticketNr) {
    TicketPtr ticket=TM->getTicketByNr(ticketNr);
    if(ticket!= nullptr) {
        if(ticket->getState()=="bought") return "Ten bilet jest już kupiony \n";
        ticket->setState("bought");
        return ticket->getTicketInfo();
    }
    return "Niestety nie udalo sie potwierdzic rezerwacji \n";
}

const std::string CinemaManager::viewRepertuar() const {
    return SM->viewSeanses();
}
