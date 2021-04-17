//
// Created by student on 09.06.2020.
//

#ifndef KINOPROJECT_SEANSMANAGER_H
#define KINOPROJECT_SEANSMANAGER_H

#include "repositories/SeansRepository.h"
#include "model/Seans.h"

class SeansManager {

    SeansRepository SR;

public:
    SeansManager();

    virtual ~SeansManager();

    bool createSeans(const std::string &mmovieTitle, const pt::ptime &mmovieDate, const unsigned int mmovieDuration, const unsigned int mprice, const ScreenRoomSize mscreenRoom, const unsigned int mseansNumber);
    const SeansPtr getSeansByNr(const unsigned int gseansNumber) const;
    const SeansPtr getSeans(const unsigned int index) const;
    void deleteSeans(SeansPtr const seans);
    const std::string viewSeanses() const;

};


#endif //KINOPROJECT_SEANSMANAGER_H
