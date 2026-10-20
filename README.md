# Project Overview: What does the application do?
The application reads student, event, registration, and organizer data from text files. The data is then used to provide an interface for the user to perform various functions for Campus event management. It allows the user to view and add students. Search and add events. Check event registrations and create new registrations. The user can view current organizers and search them. Then it saves the data when the program is closed.

# Team Members: Each team member and their primary responsibilities.
- Aleksandr: Organizer and Organizer Manager, Student and Student Manager, Event System
- Brandon: File Manager, Data Files, Readme, Technical Documentation
- Charlie: Event and child classes
- Korshid: Report Manager
- Theodore: Registration and Registration Manager

# Features: Reads and writes data using text files
- View and add students
- View, add, and search events
- Register or unregister students for events
- View attendees for an event
- View and add organizers


# Class Design: Major classes and responsibilities.
- Events: This is a parent class with four derived classes. Its holds data that is shared among all events. There are four derived classes for each type of event: Academic, Career, Club, and Social.
- EventSystem: This manages all the events. It holds all the events, allows adding and searching functionality.
- FileManager: Provides read and write functions for each of the four text files: events.txt, organizer.txt, students.txt, registrations.txt
- Organizer: Holds all the data for the organizer, getters and setters.
- OrganizerManager: Store all organizers and allow functions for displaying and searching.
- Registration: Holds all the data for registrations and provides getters and setters.
- ReportManager: Show available events, show full events, show registration count, show most popular event.
- Student: Holds all the data for each student and provides getters and setters.
- StudentManagement: Holds all student objects, provides functions to search, display, and add student.


# Building: 
There is a CMakeList that includes all of the source and header files to create and exe for the program. Ensure that you have the 4 text files in the CMakeList folder. 

# Running: 
Once the exe is created, click on the .exe file to begin the program.

# Data Storage: 
All the data is saved in .txt files. The FileManager class opens the files for Events, Organizers, Registrations, and Students. The data is read and the objects are created either in FileManager or through a helper function in the relevant class. Then when the program closes, the FileManager accepts all the data saved in the Management classes, and overwrites the existing text files with the up to date data. The data is simply saved and written in the order it was created. 

# Known Limitations: Important limitations or unfinished functionality.
- If there are multiple events that have the same max amount of attendees, then only the first found event will be displayed
- The FileManager is not coded to open up files with a different name via user input.
- Data is just read and written in the order it was created, it is not being sorted by a specific field.
- We cannot manually input a students ID if they already have one, it is randomly assigned.
- We did not implement a feature to edit the information of the student.
- We cannot display students, events, organizers in order based off x criteria.
- We do not check to see if the data files are correct. We assume that the program writes the data in the proper format to be read when it is reopened.
- When we show the registered students in an event, it is just in the order that they were added instead of alphabetical.
- When we deregister the student we simply mark the registration flag to false, we were not sure if it needed to be deleted entirely or not.