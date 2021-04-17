//
// Created by student on 08.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/ClientType.h"

namespace btt = boost::test_tools;

struct TestSuiteClientFixture {
    const std::string testName = "Jon";
    const std::string testSurname = "Arbuckle";
    const unsigned int testID = 56789;
    CTPtr testClientType = std::make_shared<Student>();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
    Client c(testName, testSurname, testID, testClientType);

        BOOST_TEST(c.getName()==testName);
        BOOST_TEST(c.getSurname()==testSurname);
        BOOST_TEST(c.getId()==testID);
        BOOST_TEST(c.getClientType()==testClientType);
    }
    BOOST_AUTO_TEST_CASE(getClientInfoTest)
    {
        Client c1(testName, testSurname, testID, testClientType);
        BOOST_TEST(c1.getClientInfo()==" Name: Jon   Surname: Arbuckle   Client ID: 56789   Client type: STUDENT ");
    }

BOOST_AUTO_TEST_SUITE_END()