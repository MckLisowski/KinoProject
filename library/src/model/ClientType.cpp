//
// Created by student on 07.06.2020.
//

#include "model/ClientType.h"

Baby::Baby() { cname="BABY"; }

const float Baby::applyDiscount(int ticketPrice) {
    return 0*ticketPrice;
}

School::School() { cname="SCHOOL"; }

const float School::applyDiscount(int ticketPrice) {
    return ticketPrice*0.7;
}

Student::Student() { cname="STUDENT"; }

const float Student::applyDiscount(int ticketPrice) {
    return ticketPrice*0.5;
}

Normal::Normal() { cname="NORMAL";  }

const float Normal::applyDiscount(int ticketPrice) {
    return ticketPrice;
}

Retired::Retired() { cname="RETIRED"; }

const float Retired::applyDiscount(int ticketPrice) {
    return 0.1*ticketPrice;
}

const std::string &ClientType::getCname() const {
    return cname;
}
