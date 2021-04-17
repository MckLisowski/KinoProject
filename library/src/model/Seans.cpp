//
// Created by student on 07.06.2020.
//

#include "model/Seans.h"
#include <sstream>

Seans::Seans(const std::string &movieTitle, const pt::ptime &movieDate, const unsigned int movieDuration,
             const unsigned int price, const ScreenRoomSize screenRoom, const unsigned int cseansNumber) : movieTitle(movieTitle), movieDate(movieDate),
                                                                          movieDuration(movieDuration), price(price),
                                                                          screenRoom(screenRoom), seansNumber(cseansNumber) {}

Seans::~Seans() {}

    // Getters

const std::string &Seans::getMovieTitle() const {
    return movieTitle;
}

const pt::ptime &Seans::getMovieDate() const {
    return movieDate;
}

const unsigned int &Seans::getMovieDuration() const {
    return movieDuration;
}

const unsigned int Seans::getPrice() const {
    return price;
}

const ScreenRoomSize Seans::getScreenRoom() const {
    return screenRoom;
}

const std::string Seans::getSeansInfo() const {
    std::ostringstream out;
    out<<" Movie date: "<<movieDate<<"   Movie title: "<<movieTitle<<"   Movie duration: "<<std::to_string(movieDuration)<<" min    Screenroom name: "<<screenRoom<<"\n Normal ticket price: "<<std::to_string(price)<<" zl ";
    return out.str();
}

const unsigned int Seans::getSeansNumber() const {
    return seansNumber;
}


