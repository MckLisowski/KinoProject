//
// Created by student on 08.06.2020.
//

#ifndef KINOPROJECT_SEANSREPOSITORY_H
#define KINOPROJECT_SEANSREPOSITORY_H

#include "model/Seans.h"
#include <vector>
#include "smartPtrs.h"

class SeansRepository {

    std::vector<SeansPtr> seanses;

public:

    SeansRepository();
    virtual ~SeansRepository();

    //const unsigned int getIndex(SeansPtr seans) const;
    void deleteSeans(SeansPtr const seans);
    void add(SeansPtr const newSeans);
    const SeansPtr get(const unsigned int &index) const;
    const SeansPtr find(SeansPredicate predicate) const;
    const std::vector<SeansPtr> findAll(SeansPredicate allPredicate) const;
    const unsigned int size() const;
    const std::string report() const;

};


#endif //KINOPROJECT_SEANSREPOSITORY_H
