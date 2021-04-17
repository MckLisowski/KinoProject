//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
#include "repositories/SeansRepository.h"
#include "managers/SeansManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteSeansRepository)

    BOOST_AUTO_TEST_CASE(registerSeansTest) {
        SeansManagerPtr SM=std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        BOOST_TEST(SM->createSeans("Kung Fu Panda", pt::second_clock::local_time(), 123, 35, C, 678));
        BOOST_TEST(!(SM->createSeans("Kung Fu Panda", pt::second_clock::local_time(), 123, 35, C, 678)));
        BOOST_TEST( SM->getSeans(4)!=nullptr);
    }

    BOOST_AUTO_TEST_CASE(getSeansTest) {
        SeansManagerPtr SM = std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        BOOST_TEST(SM->getSeans(2)->getMovieTitle()=="Fast and Furious 3");
        BOOST_TEST(SM->getSeans(5)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(getSeansByNrTest) {
        SeansManagerPtr SM = std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        BOOST_TEST(SM->getSeansByNr(6)==SM->getSeans(0));
        BOOST_TEST(SM->getSeans(200)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(deleteSeansTest) {
        SeansManagerPtr SM = std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        BOOST_TEST(SM->getSeans(3)!= nullptr);
        SM->deleteSeans(SM->getSeans(3));
        BOOST_TEST(SM->getSeans(3)== nullptr);
    }

    BOOST_AUTO_TEST_CASE(viewSeansesTest) {
        SeansManagerPtr SM = std::make_shared<SeansManager>();
        utils::seansManagerObjects(SM, 4);
        std::ostringstream out;
        for(int i=0; i<4; i++)
        {
            out<<std::to_string(i+1)<<". "<<SM->getSeans(i)->getSeansInfo()<<"\n";
        }
        BOOST_TEST(SM->viewSeanses()== out.str());
    }
BOOST_AUTO_TEST_SUITE_END()
