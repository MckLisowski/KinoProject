#include "model/ClientType.h"
#include "utils.h"
#include "smartPtrs.h"
#include "managers/SeansManager.h"
#include "managers/CinemaManager.h"
#include <iostream>

namespace pt = boost::posix_time;

int main() {

    bool k=true;
    unsigned int wybor, nrseansu, id, ticketNr;
    std::string name, surname;

    SeansManagerPtr SM = std::make_shared<SeansManager>();
    utils::seansManagerObjects(SM, 16);
    CinemaManager CinemaM(SM);

    std::cout<<"Witaj w Naszym kinie! \n";
    while(k)
    {
        std::cout<<"\nCo chcesz zrobić? \n\n 1. Zobaczyć repertuar \n 2. Kupić bilet \n 3. Zrobić rezerwacje \n 4. Potwierdzic rezerwacje \n 5. Zobaczyć aktualne bilety klienta \n 6. Zobaczyć wszystkie aktualne bilety \n 7. Zwrocic bilet \n 8. Wyjsc z kina \n\n Podaj cyfrę: ";
        std::cin>>wybor;
        switch(wybor) {
            case 1:
                std::cout<<CinemaM.viewRepertuar()<<std::endl;
            break;
            case 2:
            {
                std::cout <<"\n Repertuar: \n\n";
                std::cout << CinemaM.viewRepertuar() << std::endl;
                std::cout << " Wybierz numer seansu: ";
                std::cin >> nrseansu;
                std::cout << "\n Podaj swoje dane: \n";
                std::cout <<"Imię: ";
                std::cin >> name ;
                std::cout <<"Nazwisko: ";
                std::cin>>surname;
                std::cout <<"ID: ";
                std::cin>> id;
                TicketPtr t = CinemaM.buyTicket(nrseansu, name, surname, id, std::make_shared<Student>());
                while (t == nullptr) {
                    std::cout << "Niestety brak miejsc na wybrany film. Wybierz inny film: \n";
                    std::cin >> nrseansu;
                    t = CinemaM.buyTicket(nrseansu, name, surname, id, std::make_shared<Student>());
                }
                std::cout << "\n Oto Twój bilet: \n";
                std::cout << t->getTicketInfo();
            }
            break;
            case 3: {
                std::cout << "\n Repertuar: \n\n";
                std::cout << CinemaM.viewRepertuar()<< std::endl;
                std::cout << " Wybierz numer seansu: ";
                std::cin >> nrseansu;
                std::cout << "\n Podaj swoje dane: \n";
                std::cout << "Imię: ";
                std::cin >> name;
                std::cout << "Nazwisko: ";
                std::cin >> surname;
                std::cout << "ID: ";
                std::cin >> id;
                TicketPtr tr = CinemaM.makeReservation(nrseansu, name, surname, id, std::make_shared<Student>());
                while (tr == nullptr) {
                    std::cout << "Niestety brak miejsc na wybrany film. Wybierz inny film: \n";
                    std::cin >> nrseansu;
                    tr = CinemaM.makeReservation(nrseansu, name, surname, id, std::make_shared<Student>());
                }
                std::cout << "\n Oto Twój bilet: \n";
                std::cout << tr->getTicketInfo();
            }
            break;
            case 4:
                std::cout << "\n Podaj numer biletu: ";
                std::cin>>ticketNr;
                std::cout<<CinemaM.confirmReservation(ticketNr);
            break;
            case 5:
                std::cout << "\n Podaj ID klienta: ";
                std::cin>> id;
                std::cout <<CinemaM.viewClientsValidTickets(id);
            break;
            case 6:
                std::cout <<CinemaM.viewAllValidTickets();
                break;
            case 7:
                std::cout << "\n Podaj numer biletu: ";
                std::cin>>ticketNr;
                std::cout << CinemaM.returnTicket(ticketNr);
                break;
            case 8:
                k=false;
                break;
            default:
                k=false;
            break;
        }
    }
    return 0;
}
