//
// Created by student on 23.05.2020.
//
#include "utils.h"
#include <string>

#include "model/Client.h"
#include "model/Seans.h"
#include "model/Ticket.h"
#include "model/ClientType.h"
#include <repositories/ClientRepository.h>
#include <repositories/SeansRepository.h>
#include <repositories/TicketRepository.h>
#include "managers/SeansManager.h"
#include "managers/ClientManager.h"
#include "managers/TicketManager.h"


using namespace std;
namespace utils {

    // REPOSITORIES

    void seansRepositoryObjects(SeansRepository * SR, unsigned int number) {
        srand(time(0));

        for (int i = 0; i < number; i++) {
            string umovieTitle = "Fast and Furious " + to_string(i+1);
            unsigned int umovieDuration = random()%200;
            unsigned int uprice = random()%40;

            SeansPtr s = std::make_shared<Seans>(umovieTitle, pt::second_clock::local_time(), umovieDuration, uprice, C, i+1);

            SR->add(s);
        }
    }

    void clientRepositoryObjects(ClientRepository * CR, unsigned int number) {
        srand(time(0));
        for (int i = 0; i < number; i++) {
            string uname = "Nicolas" + to_string(i);
            string usurname = "Cage" + to_string(i);

            ClientPtr c = std::make_shared<Client>(uname, usurname, i+36, std::make_shared<School>());
            CR->add(c);
        }
    }

    void ticketRepositoryObjects(TicketRepository * TR, SeansRepository * SR, ClientRepository * CR, unsigned int number) {
        for (int i = 0; i < number; i++) {
            const unsigned int uticketNumber=i+46;
            TicketPtr t = std::make_shared<Ticket>("bought", uticketNumber, CR->get(i), SR->get(i));
            TR->add(t);
        }
    }


    // MANAGERS

    void seansManagerObjects(SeansManagerPtr SM, unsigned int number) {
        for (int i = 0; i < number; i++) {
            string umovieTitle = "Fast and Furious " + to_string(i+1);
            unsigned int umovieDuration = random()%200;
            unsigned int uprice = random()%40;

            SM->createSeans(umovieTitle, pt::second_clock::local_time(), umovieDuration, uprice, A, i+6);
        }
    }

    void clientManagerObjects(ClientManagerPtr CM, unsigned int number) {
        for (int i = 0; i < number; i++) {
            string uname = "Nicolas" + to_string(i);
            string usurname = "Cage" + to_string(i);

            CM->registerClient(uname, usurname, i+36, std::make_shared<School>());
        }
    }

    void ticketManagerObjects(TicketManagerPtr TM, SeansManagerPtr SM, ClientManagerPtr CM, unsigned int number) {
        for (int i = 0; i < number; i++) {
            TM->newTicket("bought", i+1, CM->getClient(i), SM->getSeans(i));
        }
    }
}