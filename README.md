# KinoProject
Kino(Cinema) is an university project created to practice object-oriented programming. Rules, such as polymorphysm, inheritance and hermetization have been applied in this project or its parts. I also tried to write code consistent with SOLID as well as KISS and DRY principles. Project also contains tests for each element and utils file to generate data for tests.

Project overview:

The projects' structure consists of model, repositories and managers. 
Model contains classes such as Client, Ticket or Seans and Enums. Due to the fact that this project wasn't aimed to learn databases, objects were stored in std::vector containers. 
Repositories contain methods responsible for operations on the vector, such as: adding new elements, finding elements, sizing vector etc. In later stage of developement I was going to unify the way repositories work, due to the fact they have got almost the same methods. 
Managers contain methods responsible for functioning of each part and whole cinema (CinemaManager).

Program overview:
There is no grafic interface so the program can be run on the console. User has several options to choose such as: seeing a repertoire, buying ticket, making a reservation, overlooking his tickets, seeing all actual tickets, returning a ticket or confirming a reservation. 

UML diagram:

![UML_KINO_222100_Lisowski](https://user-images.githubusercontent.com/37239354/115143586-91415700-a048-11eb-8032-b63a0c5242c3.png)

