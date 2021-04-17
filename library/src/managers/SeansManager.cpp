//
// Created by student on 09.06.2020.
//

#include "managers/SeansManager.h"

SeansManager::SeansManager() {}

SeansManager::~SeansManager() {

}

bool SeansManager::createSeans(const std::string &mmovieTitle, const pt::ptime &mmovieDate, const unsigned int mmovieDuration, const unsigned int mprice, const ScreenRoomSize mscreenRoom, const unsigned int mseansNumber) {
    if(getSeansByNr(mseansNumber)==nullptr)
    {
        SeansPtr s=std::make_shared<Seans>(mmovieTitle, mmovieDate, mmovieDuration, mprice, mscreenRoom, mseansNumber);
        SR.add(s);
        return true;
    }
    return false;
}

const SeansPtr SeansManager::getSeansByNr(const unsigned int gseansNumber) const {
    SeansPredicate findSeans = [&gseansNumber](SeansPtr sPtr) ->bool
    {
        return (sPtr->getSeansNumber()==gseansNumber);
    };
    return SR.find(findSeans);
}

void SeansManager::deleteSeans(SeansPtr const seans) {
    if(getSeansByNr(seans->getSeansNumber())!= nullptr)
    SR.deleteSeans(seans);
}

const std::string SeansManager::viewSeanses() const {
    return SR.report();
}

const SeansPtr SeansManager::getSeans(const unsigned int index) const {
    return SR.get(index);
}
/*
const SeansRepositoryPtr &SeansManager::getSr() const {
    return SR;
}*/
