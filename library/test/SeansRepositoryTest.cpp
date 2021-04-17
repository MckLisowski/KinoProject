//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Seans.h"
#include "utils.h"
#include "repositories/SeansRepository.h"


BOOST_AUTO_TEST_SUITE(TestSuiteSeansRepository)

    BOOST_AUTO_TEST_CASE(getTests)
    {
        SeansRepository SR;
        utils::seansRepositoryObjects(&SR, 4);
        BOOST_TEST(SR.get(1)->getMovieTitle()=="Fast and Furious 2");
        BOOST_TEST(SR.get(4)== nullptr);
    }

   BOOST_AUTO_TEST_CASE(addANDsizeTests)
    {
        SeansRepository SR;
        utils::seansRepositoryObjects(&SR, 4);
        BOOST_TEST(SR.size()==4);
        SeansPtr  testSeans1 =std::make_shared<Seans>("Kung Fu Panda", pt::second_clock::local_time(), 123, 35, C, 678);
        SR.add(testSeans1);
        BOOST_TEST(SR.size()==5);
        BOOST_TEST(SR.get(4)->getMovieDuration()==123);
    }

    bool checkInput(SeansPtr v)
    {
        return v->getMovieTitle()=="Fast and Furious 2";
    }
    bool checkInput2(SeansPtr v)
    {
        return v->getSeansNumber()<=3;  //123
    }

    BOOST_AUTO_TEST_CASE(findTests)
    {
        SeansRepository SR;
        utils::seansRepositoryObjects(&SR, 4);
        BOOST_TEST(SR.find(checkInput)->getMovieTitle()=="Fast and Furious 2");
        BOOST_TEST(SR.findAll(checkInput2).size()==3);
    }

    BOOST_AUTO_TEST_CASE(reportTests) {
        SeansRepository SR;
        utils::seansRepositoryObjects(&SR, 4);
        std::ostringstream out;
        for(int i=0; i<SR.size(); i++)
        {
            out<<std::to_string(i+1)<<". "<<SR.get(i)->getSeansInfo()<<"\n";
        }
        BOOST_TEST(SR.report() == out.str());
    }

    BOOST_AUTO_TEST_CASE(deleteSeansTests) {
        SeansRepository SR;
        utils::seansRepositoryObjects(&SR, 4);
        BOOST_TEST(SR.size()==4);
        SR.deleteSeans(SR.get(2));
        BOOST_TEST(SR.size()==3);
        BOOST_TEST(SR.get(2)->getMovieTitle()=="Fast and Furious 4");
}
BOOST_AUTO_TEST_SUITE_END()
