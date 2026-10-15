#pragma once
#include "FileManager.h"
#include "EventSystem.h"
#include "OrganizerManagement.h"
#include "StudentManagement.h"
#include "RegistrationManager.h"
#include "ReportManager.h"
#include <limits>

class System
{
private:
    int getSelection();
    void processSelection(int selection);
    StudentManagement students;
    OrganizerManagement organizers;
    EventSystem events;
    RegistrationManager registrations;
    ReportManager reports;
    FileManager filemanager = FileManager(students, events, organizers, registrations);
public:
    System();
    ~System();
    void runSystem();
};