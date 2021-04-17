//
// Created by student on 07.06.2020.
//

#ifndef KINOPROJECT_CLIENT_H
#define KINOPROJECT_CLIENT_H

#include <string>
#include "smartPtrs.h"


class Client {

const std::string name;
const std::string surname;
const unsigned int id;
CTPtr clientType;

public:
    Client(const std::string &cname, const std::string &csurname, const unsigned int cid, CTPtr const &cclientType);

    virtual ~Client();

    // Getters

    const std::string getClientInfo() const;
    const std::string &getName() const;
    const std::string &getSurname() const;
    const unsigned int getId() const;
    const CTPtr &getClientType() const;
};


#endif //KINOPROJECT_CLIENT_H
