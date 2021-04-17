//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
#include "repositories/TicketRepository.h"
#include "managers/ClientManager.h"
#include "managers/SeansManager.h"
#include "managers/TicketManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteTicketRepository)

    BOOST_AUTO_TEST_CASE(registerTicketTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        TicketPtr c=TM->newTicket("reservation", 2532, CM->getClient(0), SM->getSeans(0));
        BOOST_TEST(c!=nullptr);
        BOOST_TEST(TM->getTicket(4)==c);
        TicketPtr c1=TM->newTicket("reservation", 3, CM->getClient(0), SM->getSeans(0));
        BOOST_TEST(c1!=nullptr);
        BOOST_TEST(TM->getTicket(2)==c1);
    }

    BOOST_AUTO_TEST_CASE(getTicketTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        BOOST_TEST(TM->getTicket(2)->getTicketNumber()==3);
        BOOST_TEST(TM->getTicket(5)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(getTicketByNrTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        BOOST_TEST(TM->getTicketByNr(1)==TM->getTicket(0));
        BOOST_TEST(TM->getTicket(20)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(deleteTicketTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        BOOST_TEST(TM->getTicket(3)!= nullptr);
        TM->deleteTicket(TM->getTicket(3));
        BOOST_TEST(TM->getTicket(3)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(viewTicketesTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        std::ostringstream out;
        for(int i=0; i<TM->getNumberOfTickets(); i++)
        {
            out<<std::to_string(i+1)<<".   "<<TM->getTicket(i)->getTicketInfo()<<"\n";
        }
        BOOST_TEST(TM->viewTickets()== out.str());
    }

    BOOST_AUTO_TEST_CASE(getNumberOfTicketsTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        BOOST_TEST(TM->getNumberOfTickets()==0);
        utils::ticketManagerObjects(TM, SM, CM, 4);
        BOOST_TEST(TM->getNumberOfTickets()==4);
    }

    BOOST_AUTO_TEST_CASE(getClientsTicketsTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM=std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        BOOST_TEST(TM->getClientsTickets(36).size()==1);
       TM->newTicket("reservation", 245, CM->getClient(0), SM->getSeans(3));
        BOOST_TEST(TM->getClientsTickets(36).size()==2);
    }

    BOOST_AUTO_TEST_CASE(checkAvabilityTest) {
        SeansManagerPtr SM = std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        ClientManagerPtr CM = std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        TicketManagerPtr TM = std::make_shared<TicketManager>();
        utils::ticketManagerObjects(TM, SM, CM, 4);
        TM->newTicket("reservation", 24, CM->getClient(0), SM->getSeans(3));
        TM->newTicket("reservation", 25, CM->getClient(0), SM->getSeans(3));
        BOOST_TEST(TM->checkAvability(SM->getSeans(3)));
        TM->newTicket("reservation", 26, CM->getClient(0), SM->getSeans(3));
        BOOST_TEST(!(TM->checkAvability(SM->getSeans(3))));
    }

BOOST_AUTO_TEST_SUITE_END()
