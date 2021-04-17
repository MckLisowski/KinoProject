//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
#include "model/ClientType.h"
#include "managers/SeansManager.h"
#include "managers/CinemaManager.h"

struct TestSuiteCinemaFixture {
    const unsigned int testSeansNumber = 2;
    const std::string testName = "Jim";
    const std::string testSurname = "Carrey";
    const unsigned int testID = 15;
    CTPtr testClientType = std::make_shared<Student>();

    SeansManagerPtr SM=std::make_shared<SeansManager>();
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteCinemaRepository, TestSuiteCinemaFixture)

    BOOST_AUTO_TEST_CASE(buyTicketTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        const TicketPtr t= CinemaM.buyTicket(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(t!=nullptr);  //sprawdza czy utworzono bilet
        BOOST_TEST(t->getSeans()->getMovieTitle()=="Fast and Furious 2"); //sprawdza czy poprawnie wybrano seans
        const TicketPtr t1= CinemaM.buyTicket(5, testName, testSurname, testID, testClientType);
        BOOST_TEST(t1== nullptr);  //do zakupu nie doszło, ponieważ wybrano nieistniejący seans
    }

    BOOST_AUTO_TEST_CASE(makeReservationTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        const TicketPtr t= CinemaM.makeReservation(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(t!=nullptr);  //sprawdza czy utworzono bilet
        BOOST_TEST(t->getSeans()->getMovieTitle()=="Fast and Furious 2"); //sprawdza czy poprawnie wybrano seans
        const TicketPtr t1= CinemaM.makeReservation(5, testName, testSurname, testID, testClientType);
        BOOST_TEST(t1== nullptr);  //do rezerwacji nie doszło, ponieważ wybrano nieistniejący seans
    }

    BOOST_AUTO_TEST_CASE(confirmReservationTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        const TicketPtr t= CinemaM.makeReservation(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(t!=nullptr);  //sprawdza czy utworzono bilet
        BOOST_TEST(CinemaM.confirmReservation(t->getTicketNumber())!="");
        BOOST_TEST(CinemaM.confirmReservation(t->getTicketNumber())=="Ten bilet jest już kupiony \n");
        BOOST_TEST(CinemaM.confirmReservation(132)=="Niestety nie udalo sie potwierdzic rezerwacji \n");
    }

    BOOST_AUTO_TEST_CASE(viewClientsValidTicketsTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        const TicketPtr t= CinemaM.makeReservation(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(CinemaM.viewClientsValidTickets(testID)!="");
        BOOST_TEST(CinemaM.viewClientsValidTickets(4)=="Brak biletow do wyswietlenia \n");
    }

    BOOST_AUTO_TEST_CASE(viewAllValidTicketsTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        BOOST_TEST(CinemaM.viewAllValidTickets()=="Brak biletow do wyswietlenia \n");
        const TicketPtr t= CinemaM.makeReservation(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(CinemaM.viewAllValidTickets()!="");
    }
    BOOST_AUTO_TEST_CASE(viewRepertuarTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        BOOST_TEST(CinemaM.viewRepertuar() == SM->viewSeanses());
    }

    BOOST_AUTO_TEST_CASE(returnTicketTest) {
        utils::seansManagerObjects(SM, 4);
        CinemaManager CinemaM(SM);
        BOOST_TEST(CinemaM.returnTicket(23) == "Niestety nie udalo sie zwrocic biletu \n");
        const TicketPtr t= CinemaM.makeReservation(testSeansNumber, testName, testSurname, testID, testClientType);
        BOOST_TEST(CinemaM.returnTicket(t->getTicketNumber()) == "Bilet zwrocony pomyslnie \n");
    }

BOOST_AUTO_TEST_SUITE_END()
