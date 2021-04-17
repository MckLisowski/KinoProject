//
// Created by student on 07.06.2020.
//

#ifndef KINOPROJECT_SEANS_H
#define KINOPROJECT_SEANS_H

#include<string>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;

enum ScreenRoomSize
{
    A=4,
    B=40,
    C=50,
    D=60,
    E=80,
    F=100
};

class Seans {

    const std::string movieTitle;
    const pt::ptime movieDate;
    const unsigned int movieDuration;
    const unsigned int price;
    const ScreenRoomSize screenRoom;
    const unsigned int seansNumber;

public:
    Seans(const std::string &movieTitle, const pt::ptime &movieDate, const unsigned int movieDuration,
          const unsigned int price, const ScreenRoomSize screenRoom, const unsigned int seansNumber);

    virtual ~Seans();

    // Getters
    const unsigned int getSeansNumber() const;
    const std::string &getMovieTitle() const;
    const pt::ptime &getMovieDate() const;
    const unsigned int &getMovieDuration() const;
    const unsigned int getPrice() const;
    const ScreenRoomSize getScreenRoom() const;
    const std::string getSeansInfo() const;
};


#endif //KINOPROJECT_SEANS_H
