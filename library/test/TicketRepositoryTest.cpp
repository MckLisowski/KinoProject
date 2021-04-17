//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Ticket.h"
#include "utils.h"
#include "repositories/SeansRepository.h"
#include "repositories/ClientRepository.h"
#include "repositories/TicketRepository.h"


BOOST_AUTO_TEST_SUITE(TestSuiteTicketRepository)

    BOOST_AUTO_TEST_CASE(getTests)
    {
        SeansRepository SR;
        ClientRepository CR;
        TicketRepository TR;
        utils::clientRepositoryObjects(&CR, 4);
        utils::seansRepositoryObjects(&SR, 4);
        utils::ticketRepositoryObjects(&TR, &SR, &CR, 4);
        BOOST_TEST(TR.get(1)->getTicketNumber()==47);
        BOOST_TEST(TR.get(4)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(addANDsizeTests)
    {
        SeansRepository SR;
        ClientRepository CR;
        TicketRepository TR;
        utils::clientRepositoryObjects(&CR, 4);
        utils::seansRepositoryObjects(&SR, 4);
        utils::ticketRepositoryObjects(&TR, &SR, &CR, 4);
        BOOST_TEST(TR.size()==4);
        TicketPtr  testTicket1 =std::make_shared<Ticket>("reservation", 2532, CR.get(0), SR.get(0));
        TR.add(testTicket1);
        BOOST_TEST(TR.size()==5);
        BOOST_TEST(TR.get(4)->getState()=="reservation");
    }

    bool checkInput(TicketPtr v)
    {
        return v->getTicketNumber()==48;
    }
    bool checkInput2(TicketPtr v)
    {
        return v->getState()=="bought";
    }

    BOOST_AUTO_TEST_CASE(findTests)
    {
        SeansRepository SR;
        ClientRepository CR;
        TicketRepository TR;
        utils::clientRepositoryObjects(&CR, 4);
        utils::seansRepositoryObjects(&SR, 4);
        utils::ticketRepositoryObjects(&TR, &SR, &CR, 4);
        BOOST_TEST(TR.find(checkInput)->getTicketNumber()==48);
        BOOST_TEST(TR.findAll(checkInput2).size()==4);
    }

    BOOST_AUTO_TEST_CASE(reportTests) {
        SeansRepository SR;
        ClientRepository CR;
        TicketRepository TR;
        utils::clientRepositoryObjects(&CR, 4);
        utils::seansRepositoryObjects(&SR, 4);
        utils::ticketRepositoryObjects(&TR, &SR, &CR, 4);
        std::ostringstream out;
        for(int i=0; i<TR.size(); i++)
        {
            out<<std::to_string(i+1)<<".   "<<TR.get(i)->getTicketInfo()<<"\n";
        }
        BOOST_TEST(TR.report() == out.str());
    }

    BOOST_AUTO_TEST_CASE(deleteTicketTests) {
        SeansRepository SR;
        ClientRepository CR;
        TicketRepository TR;
        utils::clientRepositoryObjects(&CR, 4);
        utils::seansRepositoryObjects(&SR, 4);
        utils::ticketRepositoryObjects(&TR, &SR, &CR, 4);
        BOOST_TEST(TR.size()==4);
        TR.deleteTicket(TR.get(2));
        BOOST_TEST(TR.size()==3);
        BOOST_TEST(TR.get(2)->getTicketNumber()==49);
    }
BOOST_AUTO_TEST_SUITE_END()
