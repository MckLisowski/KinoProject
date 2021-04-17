//
// Created by student on 15.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/ClientType.h"
#include "utils.h"
#include "repositories/ClientRepository.h"


BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

     BOOST_AUTO_TEST_CASE(getTests)
     {
         ClientRepository CR;
         utils::clientRepositoryObjects(&CR, 4);
         BOOST_TEST(CR.get(1)->getName()=="Nicolas1");
         BOOST_TEST(CR.get(4)== nullptr);
         BOOST_TEST(CR.get(3)->getId()==39);
     }

     BOOST_AUTO_TEST_CASE(addANDsizeTests)
     {
         ClientRepository CR;
         utils::clientRepositoryObjects(&CR, 4);
         BOOST_TEST(CR.size()==4);
         ClientPtr  testclient1 =std::make_shared<Client>("Andrzej", "Box", 23, std::make_shared<Retired>());
         CR.add(testclient1);
         BOOST_TEST(CR.size()==5);
         BOOST_TEST(CR.get(4)->getSurname()=="Box");
     }

     bool checkInput(ClientPtr v)
     {
         return v->getName()=="Nicolas3";
     }
    bool checkInput2(ClientPtr v)
    {
        return v->getId()<=38;  //36-39
    }

     BOOST_AUTO_TEST_CASE(findTests)
     {
         ClientRepository CR;
         utils::clientRepositoryObjects(&CR, 4);
         BOOST_TEST(CR.find(checkInput)->getName()=="Nicolas3");
         BOOST_TEST(CR.findAll(checkInput2).size()==3);
     }

     BOOST_AUTO_TEST_CASE(reportTests) {
         ClientRepository CR;
         utils::clientRepositoryObjects(&CR, 4);
        std::ostringstream out;
        for(int i=0; i<CR.size(); i++)
        {
            out<<std::to_string(i+1)<<". "<<CR.get(i)->getClientInfo()<<"\n";
        }
        BOOST_TEST(CR.report() == out.str());
     }

BOOST_AUTO_TEST_SUITE_END()
