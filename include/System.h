#pragma once
#include "FileManager.h"
#include "EventSystem.h"
#include "OrganizerManagement.h"
#include "StudentManagement.h"
#include "RegistrationManager.h"
#include "ReportManager.h"

class System
{
public:
    System();
    ~System();
    StudentManagement students;
    OrganizerManagement organizers;
    EventSystem events;
    RegistrationManager registrations;
    ReportManager reports;
    FileManager filemanager = FileManager(students, events, organizers, registrations);
};