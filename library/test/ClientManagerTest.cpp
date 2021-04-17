//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
#include "model/ClientType.h"
#include "repositories/ClientRepository.h"
#include "managers/ClientManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

    BOOST_AUTO_TEST_CASE(registerClientTest) {
        ClientManagerPtr CM=std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        ClientPtr c=CM->registerClient("Stachu", "Slyszyszmnie", 22, std::make_shared<Retired>());
        BOOST_TEST(c!=nullptr);
        BOOST_TEST(CM->getClient(4)==c);
        ClientPtr c1=CM->registerClient("Stachu", "Slyszyszmnie", 38, std::make_shared<Retired>());
        BOOST_TEST(c1!=nullptr);
        BOOST_TEST(CM->getClient(2)==c1);
    }

    BOOST_AUTO_TEST_CASE(getClientTest) {
        ClientManagerPtr CM = std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        BOOST_TEST(CM->getClient(2)->getName()=="Nicolas2");
        BOOST_TEST(CM->getClient(5)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(getClientByIdTest) {
        ClientManagerPtr CM = std::make_shared<ClientManager>();
        utils::clientManagerObjects(CM, 4);
        BOOST_TEST(CM->getClientById(36)==CM->getClient(0));
        BOOST_TEST(CM->getClient(20)== nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()
