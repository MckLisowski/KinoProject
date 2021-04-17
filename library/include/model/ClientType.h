//
// Created by student on 07.06.2020.
//

#ifndef KINOPROJECT_CLIENTTYPE_H
#define KINOPROJECT_CLIENTTYPE_H

#include <string>

class ClientType {
protected:
     std::string cname;
public:
    virtual const float applyDiscount(int ticketPrice)=0;

    const std::string &getCname() const;
};

class Baby : public ClientType
{
public:
    Baby();
    const float applyDiscount(int ticketPrice) override;
};

class School : public ClientType
{
public:
    School();
    const float applyDiscount(int ticketPrice) override;
};

class Student : public ClientType
{
public:
    Student();
    const float applyDiscount(int ticketPrice) override;
};

class Normal : public ClientType
{
public:
    Normal();
    const float applyDiscount(int ticketPrice) override;
};

class Retired : public ClientType
{
public:
    Retired();
    const float applyDiscount(int ticketPrice) override;
};
#endif //KINOPROJECT_CLIENTTYPE_H
