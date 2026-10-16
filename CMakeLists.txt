cmake_minimum_required(VERSION 4.3)
project(Campus_Event_System_New)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Campus_Event_System_New
        include/AcademicEvent.h
        include/CareerEvent.h
        include/ClubEvent.h
        include/Event.h
        include/EventSystem.h
        include/FileManager.h
        include/Organizer.h
        include/OrganizerManagement.h
        include/Registration.h
        include/RegistrationManager.h
        include/ReportManager.h
        include/SocialEvent.h
        include/Student.h
        include/StudentManagement.h
        include/System.h
        src/AcademicEvent.cpp
        src/CareerEvent.cpp
        src/ClubEvent.cpp
        src/Event.cpp
        src/EventSystem.cpp
        src/FileManager.cpp
        src/main.cpp
        src/Organizer.cpp
        src/OrganizerManagement.cpp
        src/Registration.cpp
        src/RegistrationManager.cpp
        src/ReportManager.cpp
        src/SocialEvent.cpp
        src/Student.cpp
        src/StudentManagement.cpp
        src/System.cpp)
