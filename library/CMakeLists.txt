cmake_minimum_required(VERSION 3.4)

project(Library)

#ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES
        src/model/Client.cpp
        src/model/ClientType.cpp
        src/model/Seans.cpp
        src/model/Ticket.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/SeansRepository.cpp
        src/repositories/TicketRepository.cpp
        src/utils.cpp
        src/managers/ClientManager.cpp
        src/managers/SeansManager.cpp
        src/managers/TicketManager.cpp
        src/managers/CinemaManager.cpp)

#włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_library(Library ${SOURCE_FILES})
#Określenie zależności pomiędzy projektami Program i Biblioteka
#target_link_libraries(Model Program )

#dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Library PUBLIC include)

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#=========================================================================================================================================================

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp test/SeansTest.cpp test/TicketTest.cpp test/ClientRepositoryTest.cpp test/SeansRepositoryTest.cpp test/TicketRepositoryTest.cpp test/ClientManagerTest.cpp test/SeansManagerTest.cpp test/TicketManagerTest.cpp test/CinemaManagerTest.cpp)

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})