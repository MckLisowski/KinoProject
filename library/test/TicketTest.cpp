//
// Created by student on 15.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Seans.h"
#include "model/Ticket.h"
#include "model/Client.h"
#include "model/ClientType.h"

namespace gr = boost::gregorian;

struct TestSuiteTicketFixture {
    const pt::ptime movieDate=pt::ptime(gr::date(2020,7,13),pt::hours(9)+pt::minutes(25));
    std::string teststate="bought";
    const unsigned int testTicketNumber=4;
    const ClientPtr client= std::make_shared<Client>("Ania", "Mania", 22, std::make_shared<Student>());
    const SeansPtr seans= std::make_shared<Seans>("Titanic", movieDate, 120, 35, C, 16);
    bool testvalid=true;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTicket, TestSuiteTicketFixture)

    BOOST_AUTO_TEST_CASE(TicketConstructorTests) {
        Ticket t(teststate, testTicketNumber, client, seans);

        BOOST_TEST(t.getState()==teststate);
        BOOST_TEST(t.getTicketNumber()==testTicketNumber);
        BOOST_TEST(t.getClient()==client);
        BOOST_TEST(t.getSeans()==seans);
        BOOST_TEST(t.isValid()==testvalid);
    }

    BOOST_AUTO_TEST_CASE(getTicketInfoTest) {
        Ticket t1(teststate, testTicketNumber, client, seans);

        BOOST_TEST(t1.getTicketInfo()=="\n====================================================================================================================\n Ticket number: 4\n\n Client Details:\n Name: Ania   Surname: Mania   Client ID: 22   Client type: STUDENT \n\n Movie Details:\n Movie date: 2020-Jul-13 09:25:00   Movie title: Titanic   Movie duration: 120 min    Screenroom name: 50\n Normal ticket price: 35 zl    Discounted ticket price: 17.50 zl\n\n Ticket type: bought\n====================================================================================================================\n");
    }

    BOOST_AUTO_TEST_CASE(settersTest) {
        Ticket t1(teststate, testTicketNumber, client, seans);

        t1.setState("reservation");
        BOOST_TEST(t1.getState()=="reservation");
        t1.setValid(false);
        BOOST_TEST(t1.isValid()==false);
    }

BOOST_AUTO_TEST_SUITE_END()