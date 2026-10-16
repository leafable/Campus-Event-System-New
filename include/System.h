#pragma once
#include <limits>
#include "FileManager.h"
#include "EventSystem.h"
#include "OrganizerManagement.h"
#include "StudentManagement.h"
#include "RegistrationManager.h"
#include "ReportManager.h"

class System
{
private:
    StudentManagement students;
    OrganizerManagement organizers;
    EventSystem events;
    RegistrationManager registrations;
    ReportManager reports;
    FileManager filemanager = FileManager(students, events, organizers, registrations);
    int getSelection();
    void processSelection(int selection);

public:
    System();
    ~System();
    void runSystem();
    void closeSystem();
};