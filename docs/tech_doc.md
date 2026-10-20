# Technical Documentation 
# Architecture: 
The architecture is that everything is encapsulated in the System class. This class creates objects for each manager.  It saves the manager objects to encapsulate them. The main program is not encapsulated. It is explicitly defined in the main.cpp which is poor encapsulation.

# Object relationships: 
Events is a parent class with child classes AcademicEvent, CareerEvent, ClubEvent, and SocialEvent.
EventSystem is dependent on Event to create the events
OrganizerManager is dependent on Organizer to create the events and store them in the manager
RegistrationManager is dependent on Registration to create the events and store them in the manager
StudentManaager is dependent on Student and will take the data as argument and create, then store the object
The FileManager is dependent on the other managers to take the data read and create the appropriate objects to store in a data structure for the user to manipulate.

# Design Decisions: 
We wanted to design the program in a way that was efficient to manage the data and allow for the user to manipulate the data. We used different OOP concepts to reduce the work that we had to do and to ensure the program was well designed. We made encapsulation and priority to ensure that only the necessary classes had access to specific relevant data. We wanted to avoid the opportunity for undefined behavior. We designed the program to create complete and correct data and to assume that the data being read was correct and complete.

# Persistence Strategy: 
The data is read from the four text files. The data is manager by the program for the user to access and manipulate. When the user enters 0 to exit the program, the system.closeProgram() is called and the four write functions overwrite the existing files with the new data.


# Development approach: 
The way we approached the development is that we tried to keep the data class and the management class with the same people. This would allow each team member to have an in-depth understanding of the their own class so they can collaborate with others to properly integrate their code to get one working program. The encapsulation was the biggest influencer of how we developed the 

# Data storage: 
The data is read from each text file, process by the file manager and then an object is created and stored in a vector. There are four objects, Events, Students, Organizers, and registrations. Each object is handled by its own manager so the program can search, add, delete, etc. 

#Inheritance: 
The program shows inheritance in the Event class and associated child classes. All events have a set amount of shared data. However, based on the type of event, Academic, social, club, or career, we have these child classes that work of the shared data and include certain event specific data, like the club that is hosting the event or the department that is hosting an academic event. 

# Composition: 
Composition is used in the way that we classes for the data and for the managers. So StudentManagement has a Student, eventSystem has an event, and RegistrationManager has a registration. This allows us to keep the data separate from the class that organizes and edits the data. It is 

# Polymorphism: 
We use polymorphism to store the events. The EventSystem class has a vector of unique pointers of type Event. This allows us to store any of the 4 types of events in the vector. Then when the events are saved to the text files, we cast the event parent pointer to a specific event child class pointer to get the functionality to access the data fields specific to that event. Virtual functions allow us to use the same function name, but different implementations based on the data specific to each event type.

# How the project was divided: 
Initially, each part was assigned to a group member. As the project continued and there was no progress made, we made the decision to reassign the responsibilities, due to insufficient communication. This can be seen in the discord chat and github activity.
- Aleksandr: Organizer and Organizer Manager, Student and Student Manager, Event System
- Brandon: File Manager, Data Files, Readme, Technical Documentation
- Charlie: Event and child classes
- Korshid: Report Manager
- Theodore: Registration and Registration Manager

# Technical challenges:
There was a few issues with git and some issues with certain variables needing to be added or implemented in another class to resolve functionality and logic issues. There was an issue with git not being able to resolve merges and us having to back track or recopy the repo on our computers. Other technical challenges included trying to understand the correct was to store and handle the data. We wanted to make things simple, but that was not always possible. To make everything work we had to use pointers and create vectors of multiple data types. Since we used polymorphism, we had errors trying to resolve how to store different types of events, but still be able to interact with specific child class function like when writing the data at the end of the program. Since there was so many moving parts, it required a heaving amount of reviewing the reference materials. This included reviewing information on pointers, passing arguments to functions, reviewing the limitations of functions like getLine, the insertion/extractor operator, implementing virtual functions to utilize child class functions, and more. 

# Future Projects: 
A good amount of the design we would keep the same. However, we would make some changes, such as creating a better way to store events as opposed to just one vector of all the events.
A way to sort the data and have it displayed given a certain data field. This data could be sorted when it is being read into the program and be updated as the user interacts with the program.
We may want to add the functionality for users to type in the filename they wanted to use. In addition, the FileManager may want to continuously update the data in the files instead of just reading at the beginning and writing at the end. 
We may want to add functionality to display all the events a student is registered for.
The biggest change would be creating more useful relations between data like when we search a student, being able to see all the registrations, and if you click a certain registration, and option to see info of the event or the organizer. Write now the functionality is completely separate from the others. You can see the student, but need to return to the main menu to see the registrations, then back to the main menu if you want to see info on the organizer. The data should interact with each other more because users would benefit from the additional usability.
