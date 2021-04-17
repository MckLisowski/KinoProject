//
// Created by student on 15.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Seans.h"

namespace gr = boost::gregorian;

struct TestSuiteSeansFixture {
    const std::string testmovieTitle="Matrix";
    const pt::ptime testmovieDate=pt::ptime(gr::date(2020,7,13),pt::hours(9)+pt::minutes(25));
    //const pt::ptime testmovieDateBefore=pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
    //const pt::ptime testmovieDateAfter=pt::ptime(gr::date(3015,5,13),pt::hours(9)+pt::minutes(25));
    //const pt::ptime testmovieDateNow=pt::second_clock::local_time();
    const unsigned int testmovieDuration = 140;
    const unsigned int testprice=34;
    const ScreenRoomSize testscreenRoom=F;
    const unsigned int testseansNumber=6;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteSeans, TestSuiteSeansFixture)

    BOOST_AUTO_TEST_CASE(SeansConstructorTests) {
    Seans s(testmovieTitle, testmovieDate, testmovieDuration, testprice, testscreenRoom, testseansNumber);

    BOOST_TEST(s.getMovieTitle()==testmovieTitle);
    BOOST_TEST(s.getMovieDate()==testmovieDate);
    BOOST_TEST(s.getMovieDuration()==testmovieDuration);
    BOOST_TEST(s.getPrice()==testprice);
    BOOST_TEST(s.getScreenRoom()==testscreenRoom);
    BOOST_TEST(s.getSeansNumber()==testseansNumber);
    }

    BOOST_AUTO_TEST_CASE(getSeansInfoTest) {
        Seans s1(testmovieTitle, testmovieDate, testmovieDuration, testprice, testscreenRoom, testseansNumber);

        BOOST_TEST(s1.getSeansInfo()==" Movie date: 2020-Jul-13 09:25:00   Movie title: Matrix   Movie duration: 140 min    Screenroom name: 100\n Normal ticket price: 34 zl ");
    }

BOOST_AUTO_TEST_SUITE_END()