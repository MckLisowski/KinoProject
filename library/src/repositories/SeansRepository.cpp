//
// Created by student on 08.06.2020.
//

#include "repositories/SeansRepository.h"
#include <sstream>

SeansRepository::SeansRepository() {}

SeansRepository::~SeansRepository() {

}

void SeansRepository::add(SeansPtr const newSeans) {
    if(newSeans!=nullptr) seanses.push_back(newSeans);
}

const SeansPtr SeansRepository::get(const unsigned int &index) const {
    if(index<seanses.size()) return seanses[index];
    return nullptr;
}

const SeansPtr SeansRepository::find(SeansPredicate predicate) const {
    for(int i=0; i<seanses.size(); i++)
    {
        if(predicate(seanses[i])) return seanses[i];
    }
    return nullptr;
}

const std::vector<SeansPtr> SeansRepository::findAll(SeansPredicate allPredicate) const {
    std::vector<SeansPtr> v;
    for(int i=0; i<seanses.size(); i++)
    {
        if(allPredicate(seanses[i])) v.push_back(seanses[i]);
    }
    return v;
}

const unsigned int SeansRepository::size() const {
    return seanses.size();
}

const std::string SeansRepository::report() const {
    std::ostringstream out;
    for(int i=0; i<seanses.size(); i++)
    {
        out<<std::to_string(i+1)<<". "<<seanses[i]->getSeansInfo()<<"\n";
    }
    return out.str();
}

void SeansRepository::deleteSeans(SeansPtr const seans) {
    for(int i=0; i<seanses.size(); i++)
    {
        if(seanses[i]==seans)
        {
            seanses[i]= nullptr;
            seanses.erase(seanses.begin() +i);
        }
    }
}

/*const unsigned int SeansRepository::getIndex(SeansPtr seans) const {
    for(int i=0; i<seanses.size(); i++)
    {
        if(seanses[i]==seans) return i;
    }
    return 400;
}*/
