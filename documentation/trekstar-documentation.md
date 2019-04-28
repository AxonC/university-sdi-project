---
title: "Software Design and Implementation"
author: [Callum Axon (N0727303), Callum Carney (N0741707), Matthew Robinson (N0724629)]
subtitle: "TrekStar Software System"
lang: "en"
logo: "./images/ntu-logo.png"
logo-width: 60
linkcolor: darkgray
titlepage: true
titlepage-color: "06386e"
titlepage-text-color: "FFFFFF"
titlepage-rule-color: "FFFFFF"
titlepage-rule-height: 1
header-includes: |
	\usepackage{pdflscape}
...

# Table of Contents

- [Table of Contents](#table-of-contents)
- [Todo - **_remove me before submission pls_**](#todo---remove-me-before-submission-pls)
	- [User Guide](#user-guide)
- [Contributions](#contributions)
	- [Callum Axon (N0727303) - Member A](#callum-axon-n0727303---member-a)
	- [Callum Carney (N0741707) - Member C](#callum-carney-n0741707---member-c)
	- [Matthew Robinson (N0724629) - Member B](#matthew-robinson-n0724629---member-b)
- [System Description](#system-description)
	- [Cohesion and Coupling Considerations](#cohesion-and-coupling-considerations)
		- [Cohesion](#cohesion)
		- [Coupling](#coupling)
- [Component Diagram](#component-diagram)
- [Deployment Diagram](#deployment-diagram)
	- [Individual Installation](#individual-installation)
	- [Company-Wide Installation](#company-wide-installation)
- [Design Pattern](#design-pattern)
	- [Factory Design Pattern](#factory-design-pattern)
	- [Singleton](#singleton)
- [Planned Architecture](#planned-architecture)
	- [Architecture Presentation](#architecture-presentation)
		- [Model-View-Controller](#model-view-controller)
	- [Utility Tree](#utility-tree)
- [Included C++ Libraries](#included-c-libraries)
	- [JSON for C++ (GitHub Link)](#json-for-c-github-link)
	- [GTest (GitHub Link)](#gtest-github-link)
	- [spdlog (GitHub Link)](#spdlog-github-link)
- [Internal Data Structures](#internal-data-structures)
- [Search/Sorting Algorithm](#searchsorting-algorithm)
	- [Merge Sort](#merge-sort)
		- [Explaination](#explaination)
		- [Justification](#justification)
	- [Binary Search](#binary-search)
		- [Explaination](#explaination-1)
		- [Justification](#justification-1)
- [UI Screenshots](#ui-screenshots)
	- [Main Menu](#main-menu)
	- [View Mode](#view-mode)
		- [List Projects](#list-projects)
		- [Search Projects](#search-projects)
	- [Maintenance Mode](#maintenance-mode)
		- [Add Project](#add-project)
		- [Update Project](#update-project)
		- [Remove Project](#remove-project)
		- [Add Project Materials](#add-project-materials)
		- [Add Project Materials - VHS](#add-project-materials---vhs)
		- [Update Project Materials](#update-project-materials)
		- [Remove Project Materials](#remove-project-materials)
		- [Add Project Crew](#add-project-crew)
		- [Update Project Crew](#update-project-crew)
		- [Remove Project Crew](#remove-project-crew)
		- [Add Box Office Report](#add-box-office-report)
		- [Remove Box Office Report](#remove-box-office-report)
- [Software Testing Procedure](#software-testing-procedure)
- [User Manual](#user-manual)
	- [Software Introduction](#software-introduction)
	- [Using the Main Menu](#using-the-main-menu)
	- [Using View Mode](#using-view-mode)
		- [Using List Projects](#using-list-projects)
		- [Using View Materials](#using-view-materials)
		- [Using View Crew](#using-view-crew)
		- [Using View Box Office Reports](#using-view-box-office-reports)
		- [Using Search Projects](#using-search-projects)
		- [Using List Materials](#using-list-materials)
	- [Using Maintenance Mode](#using-maintenance-mode)
		- [Using Add Project](#using-add-project)
		- [Using Update Project](#using-update-project)
		- [Using Remove Project](#using-remove-project)
		- [Using Add Project Materials](#using-add-project-materials)
		- [Using Update Project Materials](#using-update-project-materials)
		- [Using Remove Project Materials](#using-remove-project-materials)
		- [Using Add Crew](#using-add-crew)
		- [Using Update Crew](#using-update-crew)
		- [Using Remove Crew](#using-remove-crew)
		- [Using Add Box Office Report](#using-add-box-office-report)
		- [Using Remove Box Office Report](#using-remove-box-office-report)
- [Conclusion](#conclusion)
- [Appendix](#appendix)
	- [Managing group work](#managing-group-work)
	- [Meeting Minutes](#meeting-minutes)
- [References](#references)

\newpage

# Todo - **_remove me before submission pls_**

## User Guide
  - Add back in image that shows keywords when adding a project when this is reimplemented.
  - Change all figure values where text is CHANGEFIGUREVALUE once all images added.
  - Resolve image issue on [Edit Packaging](#edit-packaging) once bugs have been fixed
  - Add class diagram (and any other landscape picture pages) to the TOC on last save
  - Ensure Remove box office bug is fixed

\newpage

# Contributions

## Callum Axon (N0727303) - Member A
* Class Diagram.
* One of the data structures - stack.
* A description of how cohesion and coupling have been considered in the class design.
* A justification and explanation of how cohesion and coupling have been considered in the design.
* An explanation of the planned architecture and the reason of the choices according to ATAM (follow step 4 and 5, i.e., identify possible architecture styles and choose one with respect to the identified utility tree, you need to explain the reason).
* An explanation of any design pattern used.
  
## Callum Carney (N0741707) - Member C
* A cover page (showing the full name and student ID of all members).
* A table of contents page and identifying who has contributed to which individual tasks.
* A general description of the system.
* Component diagrams.
* Deployment diagrams.
* An explanation of the internal data structures used and the reason of the choices.
* Examples (screen shots) of user interface.
* A user manual and instruction of the software. (regardless if your software is based on GUI or console interface).
* An explanation of any C++ library used.
* An explanation about the software testing process and metrics.
* Meeting minutes.

## Matthew Robinson (N0724629) - Member B
* A sequence diagram for a case/scenario of interest.
* State machine diagram for a class.
* One of the sorting studied during the lectures - merge sort.
* One of the searching algorithms studied during the lectures - binary search.
* A console interface that allows user to interact with the software system.
* An explanation of the search or sorting algorithm used and the reason of the choices. Explain how the algorithm will work in the system with detailed steps.
* Discussion and conclusion about your results (reflection on testing approach, reflection on performance such as computational efficiency, reliability, security, portability, maintainability, scalability, etc. design of system complexity using e.g. big O- notation).

All other contributions have been completed as part of a group effort.

\newpage

# System Description

The Trekstar system has been developed in order to allow TrekStar Pictures to accomplish the following

- Create and Manage Projects including any relevant metadata
- Create and Manage Project Materials (single-sided DVDs, Blu-rays, etc)
- Create Projects that are "unreleased" and cannot be modified once created
- Include details in regards to the crew working on a Project

\newpage

<!-- Class Diagram -->

\begin{landscape}

\pagestyle{empty}

\hypertarget{class-diagram}{%
\section{Class Diagram}\label{class-diagram}}

\begin{figure}
    \makebox[\linewidth]{
		\includegraphics[width=1.16\linewidth]{images/class-diagrams/class-diagram-models.jpg}
    }
	\caption{Class diagram} \label{fig:class_diagram}
\end{figure}

\end{landscape}

\newpage

<!-- End of Class Diagram -->

## Cohesion and Coupling Considerations

### Cohesion

The concept of cohesion is defined as 'the degree to which all elements of a component are directed towards a single task, within a single component, or to which the responsibilities of a class are related'.

Within the design, it was important to separate out the logic for the presentation of the information from the business logic. We have achieved this using a Model - View - Controller architecture. In order for the views to gather data from the Models themselves, a large number of *so-called* getter functions are present. This is so that the models are not responsible for the presentation and **logical cohesion** does not occur. Utilising these functions also provides an example of how communicational cohesion has been considered within the design, whilst the separation of these elements has provided the situation of functional cohesion.

Another example of how **logical cohesion** has been avoided is the approach taken to importing data from files. This logic is contained within its own object and the only data which is passed into their respective objects is a *serialised* version - separating the concerns surrounding the importing of files.

Further details on cohesion, relating to specific design patterns, can be found in that section of the document. 

### Coupling

Due to the relationships between different objects within the system, some coupling does occur. An example of this is that a Project has Materials associated with it - thus creating a dependency between the two objects. However, the relationships defined within the class diagram show that the two related objects don't modify the data of eachother, but store data about eachother independently. The data between these two objects could therefore be considered to be uncoupled.

\newpage

<!-- Sequence Diagram -->

\begin{landscape}

\pagestyle{empty}

\hypertarget{sequence-diagram}{%
\section{Sequence Diagram}\label{sequence-diagram}}

\begin{figure}
    \makebox[\linewidth]{
		\includegraphics[width=0.5\linewidth]{images/sequence-diagram/sequence-diagram.png}
    }
	\caption{Sequence diagram} \label{fig:sequence_diagram}
\end{figure}

\end{landscape}

\newpage

<!-- End of Sequence Diagram -->

<!-- State Diagram -->

\begin{landscape}

\pagestyle{empty}

\hypertarget{state-diagram}{%
\section{State Diagram}\label{state-diagram}}

\begin{figure}
    \makebox[\linewidth]{
		\includegraphics[width=1.16\linewidth]{images/state-machine-diagram/state-machine-diagram.png}
    }
	\caption{State diagram} \label{fig:state_diagram}
\end{figure}

\end{landscape}

\newpage

<!-- End of State Diagram -->

# Component Diagram

Include component diagram here

\newpage

# Deployment Diagram

There are two possible deployment scenarios for the TrekStar management system, these being:

1. An individual user will have the TrekStar project management system installed on their machine, using a locally stored JSON Database.
2. TrekStar Pictures will release the TrekStar project management system company-wide, using a shared JSON Database for each installation.

These two deployments are different due to the change in the data storage location, in which the latter will support company-wide collaboration through the application. 

However, no matter where the application is installed the following Operating Systems are supported:

* Windows
* Mac OS
* Linux

On the following pages you can find a visual representation of the aforementioned Deployment scenarios.

## Individual Installation
![Visual Representation of Individual TrekStar installation](images/deployment-diagrams/trekstar-individual-installation.png)

## Company-Wide Installation
![Visual Representation of Company-Wide TrekStar installation](images/deployment-diagrams/trekstar-company-installation.png)

\newpage

# Design Pattern

## Factory Design Pattern

Include explanation of any design patterns used

With a large number of *materials* defined within the business rules, it was appropriate to use a **factory design pattern** to generate different material types based upon an input provided by the user. The specific implementation involved defining a return type as the base material class - allowing a covariant return type. This design pattern was possible as we have a common interface for every material. A UML representation of this pattern can be found below.

![MaterialFactory UML Class Diagram](images/class-diagrams/material-factory.jpg)

The advantages of this pattern is that new materials types can easily be added by adding a small conditional statement in this class. This provides a level of abstraction and means that this class has only a single responsibility - to construct materials - removing this logic from the consuming object. This helps with the issue of coupling as functional cohesion is achieved. Because of the abstraction, it wouldn't mean any changes would necesarily have to occur in the consuming class.

## Singleton

Through the logging library spdlog, a singleton pattern was used in order to ensure a single logging instance is present within the application. This involved creating this instance as soon as the application was launched, and then accessed (using the library) within the areas of the application logging is used e.g. in the application. 

A common issue with this pattern is the issue of multithreading, particularly with respect to file handling. There could be multiple components within the application 

\newpage

# Planned Architecture

## Architecture Presentation

Architecture tradeoff analysis method (ATAM) was used to decide on an arcitecture which was to be followed for the development of the Trekstar Project Management System.

### Model-View-Controller
MVC is driven by interaction. The use of Views to prompt their respective controllers to modify the model and subsequently update the view in real time fits the requirements of the Trekstar system. Models act as the data store for all of the related objects within the system. Controllers manipulate the data in the models through an exposed interface on the model objects

## Utility Tree

 The management of projects requires fast, realtime interaction (Top 6 Most Important Benefits of MVC Architecture, 2017). The requirements gathered from Trekstar meant that some of the data needs to be presented in a different manner (e.g. displaying the contents of a double sided DVD). Due the benefit of MVC being able to present data in multiple formats, this made it an ideal choice. One of the stretch goals of the project was to provide the user with a Graphical User Interface (GUI). By using MVC, it will be easier to produce views for a GUI rather than a console based interface as only one component of the system (the views) will need to be changed out.

As previously mentioned in other sections, separating the logic for presenting and performing the business model provides benefits with regards to de-coupling and setting clear boundaries within the system. Given that the components of the MVC architecture are independent of eachother, they can be developed in isolation. Within the context of the project, where individual members are responsible for different sections of the project - e.g. one for data structures & one for the user interface - the development of these components could happen in tandem.

\newpage

# Included C++ Libraries

Within the TrekStar project management application we have used some C++ Libraries for parsing data, providing access to unit tests and including core functionality that would otherwise not be present. Below you can find an explanation of the included C++ libraries and why we chose to use them:

## JSON for C++ ([GitHub Link](https://github.com/nlohmann/json))
It was decided to use the JSON for C++ library within the application because we are using JSON as our database to store all of the users data. The JSON for C++ library allows us to parse JSON data, request data based on certain keys within a JSON Array or Object and create new JSON Arrays or Objects to be inserted into the database. The JSON for C++ library is quite easily the most feature complete and well documented library for parsing and creating JSON in C++, this was the main driving force behind using this library as we required something that is reliable and suitable for the applications use cases.

## GTest ([GitHub Link](https://github.com/google/googletest))
It was decided to use GTest as our primary unit testing library within the application, whilst we could have used Boost for unit testing, we decided that GTest had the following advantages which solidified our decision to use GTest:

- GTest is much more lightweight when compared to Boost, while GTest is specifically a testing library, Boost has more functionality that also needs to be imported to allow for the Unit Testing section of the library to function, consequently making it larger and less lightweight.
- When compared to other Unit Testing libraries there are more features that we can make use of in the project within GTest, for example, we can use GTests ability to mock objects, this is useful when we need to test the interaction between objects as we can achieve this more efficiently when compared to other libraries. We can also avoid duplication of test setup (creating objects, etc) within each unit test by specifying test fixtures which can be referenced within the unit tests.

## spdlog ([GitHub Link](https://github.com/gabime/spdlog))
It was decided to use spdlog for our logger library, when compared to other libraries spdlog is lightweight, fast and only requires header imports to get started. spdlog also supports all of the operating systems that our application has been developed to work on, which is an important feature to have.

spdlog also allows us to easily generate the required daily reports based on the data we pass from the JSON database, the simplicity of this library was an important consideration as it allows future developers to quickly understand how this function works incase a new feature or bug needs to be added/fixed.

\newpage

# Internal Data Structures

During the design phase of the TrekStar project management application it was decided that an internal data structure of Stack would be used. While there are pros and cons to each data structure, ultimately it was decided that the Stack data structure fit the best with the requirements of our application, you can find the in-depth reasoning behind the decision to use Stack below:

- The Stack data structure allows for the sequential ordering of disks, and make sense within our use cases. For example, if you have a box set of 4 disks and you would like to add a new disk, its likely that the new disk will be the latest episode, therefore it will be inserted sequentially at the end of the list. Another example would be when a user would like to remove a disk from a boxset, it is unlikely that you will want to remove the 3rd episode within the boxset, however if the 3rd episode was to be removed then the 4th episode (the last one in the underlying vector) can be removed allowing for the 3rd episode to then be removed, therefore the Stack data structure is still appropriate.
- Another advantage to the Stack data structure is that data can be accessed quicker sequentially, this is because you can iterate though the underlying vectors data finding items that a requested.
- A final advantage to the Stack data structure is that it uses general programming through the use of templating, as a consequence to this, the Stack data structure supports multiple types.

\newpage

# Search/Sorting Algorithm

## Merge Sort

### Explaination

The merge sort algorithm was used to sort a list of projects based on their title.

Merge sort is a divide and conquer sorting algorithm where the list recursively partitioned in to halves, until each sublist is of length one, and therefore sorted by definition as the single project is the smallest and the largest in that sublist. The sublists are then sorted and merged into larger sublists until they are recombined into a single sorted list.

The list of projects is split into two halves. Each half then goes through a similar process whereby the halves are repeatedly split until they are of length one, which is, by definition, a sorted list.

The sublists in each half are then merged together by following this process until all projects are in the merged list:
* compare the first project in the left half with the first project in the right half;
* if the project in the left half is less than the project in the right half, add the project from the left half to the merged list and read the next project from the left half;
* if the project in the right half is less than the project in the left half, add the project from the right half to the merged list and read the next project from the right half; and
* once either list is empty, any remaining projects are added to the merged list.

The two halves are then merged together by following the same process above until all projects are in the merged list. As merge sort is an "in-place" sorting algorithm and the list of project was passed by reference, there is no return value. The list of projects is now sorted and can be used as such from where the merge sort function was originally called.

### Justification

The implementation of a merge sort algorithm was determined to be necessary in order to benefit from the higher efficiency of sorting using the binary search algorithm, as described below. The merge sort algorithm was used as when compared to other alternatives, such as quick sort, merge sort is more efficient on larger datasets. While the testing was completed with small numbers of projects, it is likely that, if this software was to be used in the real world, there may be hundreds of thousands of projects sorted in the projects list.

Further discussion of the time complexity of merge sort can be found in [INSERT SECTION LINK HERE].

## Binary Search

### Explaination

Binary search algorithm was used to find a project based on its title. The merge sort algorithm described above is performed before, as the binary search has a prerequisite that the list of projects be sorted.

An overload equals operator was created on the *Project* class; this was used to check if the search criteria of a project title was equal to the title attribute in the project when checking if the item at *mid* was the desired project.

The binary search algorithm requires the following variables:
* an integer variable *result* set to -1;
* an integer variable *low* set to 0;
* an integer variable *high* set to the index of the last project in the list; and
* an integer variable *mid*.

While the integer variable *result* is equal to -1 no project has been found that matches the search criteria, and the following steps should be taken repeatedly until a project is found or it has been determined that the project does not exist in the list:
* calculate a midpoint by using the equation *mid = low + ((high - low) / 2)*;
* if the project at the midpoint is equal to the search criteria, *result* can be set to this project;
* if the project at the midpoint is less than the search criteria, set the *low* to *mid + 1*; and
* if the project at the midpoint is greater than the search criteria, set the *high* to *mid – 1*.

After these stages have been completed, the value of *result* can be returned. The subsequent code can then display that the project was not found if *-1* is returned. Otherwise, the *result* can be used as an index value to access the project in the list and display its detail to the user.

### Justification

A movie company, such as TrekStar, may have a large number of projects. It is important that searching these projects is efficient; the binary search algorithm avoids checking every project in the list. This is because comparisons are made to determine which half of the list the target project resides within. As a result, on each iteration, half of the project list is discarded.

Further discussion of the time complexity of binary search can be found in [INSERT SECTION LINK HERE].

\newpage

# UI Screenshots

## Main Menu

![Visual representation of the Main Menu](images/ui-screenshots/main-menu.png)

\newpage

## View Mode

![Visual representation of View Mode](images/ui-screenshots/view-mode.png)

\newpage

### List Projects

![Visual representation of List Projects](images/ui-screenshots/list-projects.png)

<!-- Contents Page Stopper --> ### View Materials

![Visual representation of View Materials](images/ui-screenshots/list-projects-view-materials.png)

\newpage

<!-- Contents Page Stopper --> ### View Crew

![Visual representation of View Crew](images/ui-screenshots/list-projects-view-crew.png)

\newpage

<!-- Contents Page Stopper --> ### View Box Office Reports

![Visual representation of View Box Office Reports](images/ui-screenshots/list-projects-view-box-office-reports.png)

\newpage

### Search Projects

![Visual representation of Search Projects](images/ui-screenshots/search-projects.png)

\newpage

<!-- Contents Page Stopper --> ### Search Title

![Visual representation of Search Title](images/ui-screenshots/search-title.png)

\newpage

<!-- Contents Page Stopper --> ### Search Actor

![Visual representation of Search Actor](images/ui-screenshots/search-actor.png)

\newpage

## Maintenance Mode

![Visual representation of Maintenance Mode](images/ui-screenshots/maintenance-mode.png)

### Add Project

![Visual representation of Add Project](images/ui-screenshots/add-project-need-fix.png)

Requires fix when keyword is back

\newpage

### Update Project

![Visual representation of Update Project](images/ui-screenshots/update-project.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Title

![Visual representation of Edit Title](images/ui-screenshots/update-title.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Summary

![Visual representation of Edit Summary](images/ui-screenshots/update-summary.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Released

![Visual representation of Edit Released](images/ui-screenshots/update-released.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Playing In Theaters

![Visual representation of Edit Playing In Theaters](images/ui-screenshots/update-playing-in-theatres.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Existing Keyword

![Visual representation of Edit Existing Keyword](images/ui-screenshots/update-existing-keyword.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Crew

![Visual representation of Edit Crew](images/ui-screenshots/update-crew.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Name

![Visual representation of Edit Crew Name](images/ui-screenshots/update-crew-name.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Job Title

![Visual representation of Edit Crew Job Title](images/ui-screenshots/update-crew-job-title.png)

\newpage

### Remove Project

![Visual representation of Remove Project](images/ui-screenshots/remove-project.png)

\newpage

### Add Project Materials

![Visual representation of Add Project Materials](images/ui-screenshots/add-project-materials.png)

\newpage

### Add Project Materials - VHS

![Visual representation of Add Project Materials](images/ui-screenshots/add-project-materials-vhs.png)

\newpage

### Update Project Materials

<!-- Contents Page Stopper --> ### Edit Audio Format

![Visual representation of Edit Audio Format](images/ui-screenshots/update-project-material-audio-format.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Run Time

![Visual representation of Edit Run Time](images/ui-screenshots/update-project-material-run-time.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Language

![Visual representation of Edit Language](images/ui-screenshots/update-project-material-language.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Retail Price

![Visual representation of Edit Retail Price](images/ui-screenshots/update-project-material-retail-price.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Subtitles

![Visual representation of Edit Subtitles](images/ui-screenshots/update-project-material-subtitles.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Frame Aspect

![Visual representation of Edit Frame Aspect](images/ui-screenshots/update-project-material-frame-aspect.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Content

![Visual representation of Edit Content](images/ui-screenshots/update-project-material-content.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Additional Language Tracks

![Visual representation of Edit Additional Language Tracks](images/ui-screenshots/update-project-material-additional-language-tracks.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Additional Subtitle Tracks

![Visual representation of Edit Additional Subtitle Tracks](images/ui-screenshots/update-project-material-additional-subtitle-tracks.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Bonus Features

![Visual representation of Edit Bonus Features](images/ui-screenshots/update-project-material-bonus-feature.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Packaging

![Visual representation of Edit Packaging](images/ui-screenshots/update-project-material-packaging.png)

\newpage

### Remove Project Materials

![Visual representation of Remove Project Materials](images/ui-screenshots/remove-project-materials.png)

\newpage

### Add Project Crew

![Visual representation of Add Project Crew](images/ui-screenshots/add-crew.png)

\newpage

### Update Project Crew

<!-- Contents Page Stopper --> ### Edit Crew Name

![Visual representation of Edit Crew Name](images/ui-screenshots/update-crew-name.png)

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Job Title

![Visual representation of Edit Crew Job Title](images/ui-screenshots/update-crew-job-title.png)

\newpage

### Remove Project Crew

![Visual representation of Remove Project Crew](images/ui-screenshots/remove-crew.png)

\newpage

### Add Box Office Report

![Visual representation of Add Box Office Report](images/ui-screenshots/add-box-office.png)

\newpage

### Remove Box Office Report

![Visual representation of Remove Box Office Report](images/ui-screenshots/remove-box-office.png)

\newpage

# Software Testing Procedure
Software Testing is an important part of the SDLC and within our project we have multiple constraints in place to ensure that tested, bug-free code is committed to the GitHub repository. Committing working code to the repository is important for a number of reasons, with some of these being:

- Developers will never pull broken code that will lead to a slow down in development.
- Developers will never have to fix someone elses broken code, avoiding time wasted on parts of the application that is not allocated to that developers.
- In case of a rollback, the repository will always be in a good state, which helps to avoid further rollbacks.

Some of the constraints that we have in place are:

- Developers will only commit code that has the associated unit tests created and those unit tests must pass.
- Developers must never commit broken code that could impede the efficiency of other developers, if a commit is required a new branch should be created.
- If there are known bugs, developers must log these within the GitHub Issues to ensure that other developers know that it is know/being worked on incase they come across it.

Our group is confident that these constraints will allow us to develop the application with fewer interruptions and ensure that only high quality, tested code is being pushed to the repository. 

\newpage

# User Manual

## Software Introduction
The Trekstar project management application has been developed for TrekStar Pictures and allows them to create and manage Projects along with their associated product materials and metadata. This guide will cover how to use the core features of the application, which includes:

* Using the main menu
* Using view mode
* Using maintenance mode

## Using the Main Menu
To use the Main Menu, open the application and you will be presented with the following screen

![Visual representation of the Main Menu](images/user-guide/main-menu/using-the-main-menu.png)

Once on this screen, you can use the following keyboard inputs to navigate around the application, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                            | Information Link                                  |
| :----------: | ------------------------------------------------------------------------- | ------------------------------------------------- |
| 1     | Inputting this value will cause the application to enter View Mode        | [Using View Mode](#using-view-mode)               |
| 2     | Inputting this value will cause the application to enter Maintenance Mode | [Using Maintenance Mode](#using-maintenance-mode) |
| 3     | Inputting this value will cause the application to safely exit            | Not required                                      |

\newpage

## Using View Mode

Once you have reached the View Mode page you will be presented with the following screen

![Visual representation of View Mode](images/user-guide/view-mode/using-view-mode.png)

Once on this screen, you can use the following keyboard inputs to navigate around view mode, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to list projects                   | [Listing Projects](#using-list-projects)       |
| 2     | Inputting this value will cause the application to enter search mode for projects | [Using Search Projects](#using-search-projects) |
| 3     | Inputting this value will cause the application to navigate back to the main menu | [Main Menu](#using-the-main-menu)         |

\newpage

### Using List Projects

Once you have entered the List Projects functionality you will be asked if you wish to sort all of the projects by their title, you can enter _`y`_ to confirm that you wish for the projects to be order by their titles and _`n`_ to decline.

![Visual representation of the application asking if you wish to sort by title](images/user-guide/view-mode/sort-by-title.png)

You will now see the projects that are held within your applications database, you can see an example of this below.

![Visual representation of project listings](images/user-guide/view-mode/listed-projects.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these options allow you to navigate through the projects. You can see the associated input actions below.

| Input Value | Command Action                                                         |        Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | This will cause the application to move onto the next project in the database              | Not Required       |
| 2     | This will cause the application to move onto the previous project in the database | Not Required|
| 3     | This will cause the application to enter the view materials functionality |[View Materials](#using-view-materials)|
| 4     | This will cause the application to enter the view crew functionality |[View Crew](#using-view-crew)|
| 5     | This will cause the application to enter the view box office reports functionality | [View Box Office Reports](#using-view-box-office-reports)|
| 6     | This will cause the application to navigate back to view mode          |  [View Mode](#using-view-mode)         |

\newpage

### Using View Materials

Once you have reached the View Materials page you will be presented with the following screen

![Visual representation of View Materials](images/user-guide/view-mode/using-view-materials.png)

Once on this screen, you can use the following keyboard inputs to navigate around view materials, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next material in the database              |
| 2     | This will cause the application to move onto the previous material in the database | 
| 3     | This will cause the application to navigate back to [List Projects](#using-list-projects)              | 

\newpage

### Using View Crew

Once you have reached the View Crew page you will be presented with the following screen

![Visual representation of View Crew](images/user-guide/view-mode/using-view-crew.png)

Once on this screen, you can use the following keyboard inputs to navigate around view crew, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next crew member in the database              |
| 2     | This will cause the application to move onto the previous member in the database | 
| 3     | This will cause the application to navigate back to [List Projects](#using-list-projects)              | 

\newpage

### Using View Box Office Reports

Once you have reached the View Box Office Reports page you will be presented with the following screen

![Visual representation of View Box Office Reports](images/user-guide/view-mode/using-view-box-office-reports.png)

Once on this screen, you can use the following keyboard inputs to navigate around view box office reports, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next box office report in the database              |
| 2     | This will cause the application to move onto the previous box office report in the database | 
| 3     | This will cause the application to navigate back to [List Projects](#using-list-projects)              | 

\newpage

### Using Search Projects

Once you have entered the Search Projects functionality you will be asked to select what search type you would like to use, the following options will be provided:

| Input Value | Command Action                                                         |        Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | This will cause the application to enter the search by title functionality |[Search By Title](#using-search-by-title)|
| 2     | This will cause the application to enter the search by actor functionality |[View Crew](#using-search-by-actor)|
| 3     | This will cause the application to navigate back to view mode          |  [View Mode](#using-view-mode)         |

\newpage

<!-- Contents Page Stopper --> ### Using Search By Title

![Visual representation of the application asking for a search query](images/user-guide/view-mode/project-title-search.png)

You will now see the associated projects that matched to your search query, you can see an example of this below.

![Visual representation of a project being discovered from a search query](images/user-guide/view-mode/project-search-term.png)

As you can see in Figure CHANGEFIGUREVALUE, there is the option to display the associated materials for this project, you can enter _`y`_ to confirm that you wish to view the materials for the associated project, which will bring up the following information:

![Visual representation of a projects materials being displayed](images/user-guide/view-mode/project-search-list-material.png)

As you can see in CHANGEFIGUREVALUE, there are more options available, you can find what each command does below

You can also enter _`n`_ to confirm that you do not want to view the materials for the associated project, which will bring up the following information:

![Visual representation of a projects materials not being displayed](images/user-guide/view-mode/project-search-materials-decline.png)

As you can see in CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [View Mode](#using-view-mode), therefore you can find more information by reading the [View Mode](#using-view-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Using Search By Actor

![Visual representation of the application asking for a search query](images/user-guide/view-mode/project-actor-search.png)

You will now see the associated projects that matched to your search query, you can see an example of this below.

![Visual representation of a project being discovered from a search query](images/user-guide/view-mode/project-search-actor.png)

As you can see in Figure CHANGEFIGUREVALUE, there is the option to display the associated materials for this project, you can enter _`y`_ to confirm that you wish to view the materials for the associated project, which will bring up the following information:

![Visual representation of a projects materials being displayed](images/user-guide/view-mode/project-search-list-material.png)

As you can see in CHANGEFIGUREVALUE, there are more options available, you can find what each command does below

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next material in the database              |
| 2     | This will cause the application to move onto the previous material in the database | 
| 3     | This will cause the application to navigate back to [View Mode](#using-view-mode)              | 

You can also enter _`n`_ to confirm that you do not want to view the materials for the associated project, which will bring up the following information:

![Visual representation of a projects materials not being displayed](images/user-guide/view-mode/project-search-actor-decline.png)

As you can see in CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [View Mode](#using-view-mode), therefore you can find more information by reading the [View Mode](#using-view-mode) section of this user guide.

\newpage

### Using List Materials

Once you have entered the List Materials functionality you will be asked to input a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to list materials for](images/user-guide/view-mode/list-materials-project-id.png)

You will now see the materials linked to the requested project that are held within your applications database, you can see an example of this below.

![Visual representation of material listings](images/user-guide/view-mode/listed-materials.png)

As you can see in Figure 10, there are more options available to you, these options allow you to navigate through the materials. You can see the associated input actions below.

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next material in the database              |
| 2     | This will cause the application to move onto the previous material in the database | 
| 3     | This will cause the application to navigate back to [View Mode](#using-view-mode)              | 

\newpage

## Using Maintenance Mode

Once you have reached the Maintenance Mode page you will be presented with the following screen

![Visual representation of Maintenance Mode](images/user-guide/main-menu/using-maintenance-mode.png)

Once on this screen, you can use the following keyboard inputs to navigate around maintenance mode, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter add project             | [Adding Projects](#using-add-project)       |
| 2     | Inputting this value will cause the application to enter update project | [Updating Projects](#using-update-project) |
| 3     | Inputting this value will cause the application to enter remove project | [Removing Projects](#using-remove-projects) |
| 4     | Inputting this value will cause the application to enter update project materials| [Add Project Materials](#using-add-project-materials) |
| 4     | Inputting this value will cause the application to enter update project materials| [Updating Project Materials](#using-update-project-materials) |
| 5     | Inputting this value will cause the application to enter remove project materials | [Removing Project Materials](#using-remove-project-materials) |
| 4     | Inputting this value will cause the application to enter update project materials| [Add Project Crew](#using-update-project-crew) |
| 4     | Inputting this value will cause the application to enter update project materials| [Updating Project Crew](#using-update-project-crew) |
| 5     | Inputting this value will cause the application to enter remove project materials | [Removing Project Crew](#using-remove-project-crew) |
| 4     | Inputting this value will cause the application to enter update project materials| [Add Box Office Report](#using-add-box-office-report) |
| 4     | Inputting this value will cause the application to enter update project materials| [Updating Box Office Report](#using-update-box-office-report) |
| 6     | Inputting this value will cause the application to navigate back to the main menu  | [Main Menu](#using-the-main-menu)         |

\newpage

### Using Add Project

Once you have entered the Add Project functionality you will be asked to enter the following information:


Firstly, you need to enter the Project Title, this is the name that you want your project to be called. Any value is accepted.

![Visual representation of the application asking for a Project Title](images/user-guide/maintenance-mode/add-project-title.png)

Next, you will be asked for a project summary. Any value is accepted.

![Visual representation of the application asking for Project Summary](images/user-guide/maintenance-mode/add-project-summary.png)

Next, you will be asked if the project has been released. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project has been released and _`n`_ confirming that the project has not been released.

![Visual representation of the application asking if the project has been released](images/user-guide/maintenance-mode/add-project-released.png)

Next, you will be asked if the project will be playing in theaters. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project will be playing in theatres and _`n`_ confirming that the project will not be playing in theatres.

![Visual representation of the application asking if the project will be playing in theatres](images/user-guide/maintenance-mode/add-project-theatres.png)

Next, you will be asked how many keywords you would like associating with the project. Any numeric value is accepted.

![Visual representation of the application asking how many keywords should be associated with the project](images/user-guide/maintenance-mode/add-project-keywords-amount.png)

Finally, you will be asked what keywords you would like associated with the project, the amount of keyword requests depends on the previously entered numeric value. Any value is accepted.

![Visual representation of the application asking for a keyword](images/user-guide/maintenance-mode/add-project-keywords.png)

As you can see in CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Update Project

Once you have entered the Update Project functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to update the project for](images/user-guide/maintenance-mode/update-project-select-id.png)

Next, you will be presented with multiple options, you can use the following keyboard inputs to update certain aspects of the project, to find out more about each update, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter edit title             | [Edit Title](#edit-title)    |
| 2     | Inputting this value will cause the application to enter edit summary | [Edit Summary](#edit-summary) |
| 3     | Inputting this value will cause the application to enter edit released | [Edit Released](#edit-released) |
| 4     | Inputting this value will cause the application to enter edit playing in theatres | [Edit Playing In Theatres](#edit-playing-in-theaters) |
| 4     | Inputting this value will cause the application to enter edit existing keywords | [Edit Existing Keywords](#edit-existing-keywords) |
| 5     | Inputting this value will cause the application to enter edit existing keywords | [Edit Crew](#edit-crew) |
| 6     | Inputting this value will cause the application to navigate back to the maintenance mode menu  | [Maintenance Mode Menu](#using-maintenance-mode) |

\newpage

<!-- Contents Page Stopper --> ### Edit Title

Once you have entered the Edit Title functionality you will be asked to enter the following information:

You need to enter the new Project Title, this is the new name that you want your project to be called. Any value is accepted.

![Visual representation of the application asking for a new Project Title](images/user-guide/maintenance-mode/update-project-title.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Summary

Once you have entered the Edit Summary functionality you will be asked to enter the following information:

You need to enter the new Project Summary, this is the new summary that you want your project to have. Any value is accepted.

![Visual representation of the application asking for a new Project Summary](images/user-guide/maintenance-mode/update-project-summary.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Released

Once you have entered the Edit Released functionality you will be asked to enter the following information:

You need to enter the new Released value, this is the new released state that you want your project to have. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project is released and _`n`_ confirming that the project is not released.

![Visual representation of the application asking for a new Released value](images/user-guide/maintenance-mode/update-project-released.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Playing In Theaters

Once you have entered the Edit Playing In Theaters functionality you will be asked to enter the following information:

You need to enter the new playing in theatres value, this is the new playing in theaters state that you want your project to have. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project will be playing in theatres and _`n`_ confirming that the project will not be playing in theatres.

![Visual representation of the application asking for a new Project Title](images/user-guide/maintenance-mode/update-project-playing-in-theaters.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Existing Keywords

Once you have entered the Edit Existing Keywords functionality you will be asked to enter the following information:

You need to enter the keyword identifier you wish to update, you can find the identifier in the provided list, an example of this can be seen below:

![Visual representation of the application showing the current Keyword identifiers](images/user-guide/maintenance-mode/update-project-select-keyword.png)

Once you have inputted a valid keyword identifier you will be asked to enter your new Keyword, any value is accepted.

![Visual representation of the application asking for a new keyword](images/user-guide/maintenance-mode/update-project-keyword.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Crew

Once you have entered the Edit Crew functionality you will be asked to enter the following information:

You need to enter the crew identifier you wish to update, you can find the identifier in the provided list, an example of this can be seen below:

![Visual representation of the application showing the current Crew identifiers](images/user-guide/maintenance-mode/update-project-select-crew.png)

Once you have inputted a valid keyword identifier you will be asked to enter the type of data you would like to update, you can find the associated values below, to find out more about each function, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter update crew name                 | [Edit Name](#using-edit-crew-name)       |
| 2     | Inputting this value will cause the application to enter update crew job title | [Edit Job Title](#using-edit-crew-job-title) |
| 3     | Inputting this value will cause the application to navigate back to the maintenance mode menu  | [Maintenance Mode Menu](#using-maintenance-mode)      |

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Name

Once you have entered the Edit Crew Name functionality you will be asked to enter the following information:

You need to enter the new Crew Name, this is the new name for the crew member that you selected. Any value is accepted.

![Visual representation of the application asking for a new Crew Name](images/user-guide/maintenance-mode/update-crew-name.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Job Title

Once you have entered the Edit Crew Job Title functionality you will be asked to enter the following information:

You need to enter the new Crew Job Title, this is the new job title for the crew member that you selected. Any value is accepted.

![Visual representation of the application asking for a new Crew Name](images/user-guide/maintenance-mode/update-crew-job-title.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Remove Project

Once you have entered the Remove Project functionality you will be asked to enter the following information:

You only need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

Once you submit this Project ID it will be removed from the database.

![Visual representation of selecting a Project ID to update the project for](images/user-guide/maintenance-mode/remove-project-select-id.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Add Project Materials

Once you have entered the Add Project Materials functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with selecting a project to add a material to](images/user-guide/maintenance-mode/update-project-select-id.png)

Next, you will be asked to enter the material format identifer you wish to add within the previously selected project, you can find the identifier in the provided list, an example of this can be found below:

![Visual representation of selecting a Material Format ID to add to the project](images/user-guide/maintenance-mode/add-material-select-id.png)

Once you have selected a Material Format ID you will be asked to enter the following information:

Next, you need to enter the Audio Format, this is the audio format that you want your material to have. Any value is accepted.

![Visual representation of the application asking for a Project Title](images/user-guide/maintenance-mode/add-material-audio-format.png)

Next, you will be asked for the material run time. Any numeric value is accepted.

![Visual representation of the application asking for the material Run Time](images/user-guide/maintenance-mode/add-material-run-time.png)

Next, you will be asked for the material language. Any value is accepted.

![Visual representation of the application asking for the material Language](images/user-guide/maintenance-mode/add-material-language.png)

Next, you will be asked for the material retail price. Any numeric value is accepted.

![Visual representation of the application asking for the material Retail Price](images/user-guide/maintenance-mode/add-material-retail-price.png)

Next, you will be asked for the material subtitles. Any value is accepted.

![Visual representation of the application asking for the material Subtitles](images/user-guide/maintenance-mode/add-material-subtitles.png)

Next, you will be asked for the material frame aspect. Any value is accepted.

![Visual representation of the application asking for the material Frame Aspect](images/user-guide/maintenance-mode/add-material-frame-aspect.png)

Next, you will be asked for the material content. Any value is accepted.

![Visual representation of the application asking for the material Content](images/user-guide/maintenance-mode/add-material-content.png)

Next, you will be asked if the material has any additional language tracks. Any value is accepted, if you enter anything other than 0 you will be asked for the Additional Language track otherwise you can move onto the next input.

![Visual representation of the application asking if the material has any additional language tracks](images/user-guide/maintenance-mode/add-material-number-of-additional-language-tracks.png)

If you entered more than 0 the application will ask you to enter the following information for the amount of language tracks added.

![Visual representation of the application asking for material additional language track information](images/user-guide/maintenance-mode/add-material-additional-language-track.png)

Next, you will be asked if the material has any additional subtitle tracks. Any value is accepted, if you enter anything other than 0 you will be asked for the Additional Subtitle track otherwise you can move onto the next input.

![Visual representation of the application asking if the material has any additional subtitle tracks](images/user-guide/maintenance-mode/add-material-number-of-additional-subtitle-tracks.png)

If you entered more than 0 the application will ask you to enter the following information for the amount of subtitle tracks added.

![Visual representation of the application asking for material additional subtitle track information](images/user-guide/maintenance-mode/add-material-additional-subtitle-track.png)

Finally, you will be asked if the material has any additional bonus features. Any value is accepted, if you enter anything other than 0 you will be asked for the Bonus Feature otherwise you can move onto the next input.

![Visual representation of the application asking if the material has any bonus features](images/user-guide/maintenance-mode/add-material-number-of-bonus-features.png)

If you entered more than 0 the application will ask you to enter the following information for the amount of bonus features added.

![Visual representation of the application asking for material bonus feature information](images/user-guide/maintenance-mode/add-material-bonus-features.png)

As you can see in CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage


### Using Update Project Materials

Once you have entered the Update Project Materials functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with selecting a material to update](images/user-guide/maintenance-mode/update-project-select-id.png)

Next, you will be asked to enter the material identifer you wish to update within the previously selected project, you can find the identifier in the provided list, an example of this can be found below:

![Visual representation of selecting a Material ID to update the material for](images/user-guide/maintenance-mode/update-project-material-select-material-id.png)

Next, you will be presented with multiple options, you can use the following keyboard inputs to update certain aspects of the material, to find out more about each update, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter edit audio format         | [Edit Audio Format](#edit-audio-format)    |
| 2     | Inputting this value will cause the application to enter edit run time | [Edit Run Time](#edit-run-time) |
| 3     | Inputting this value will cause the application to enter edit language | [Edit Language](#edit-language) |
| 4     | Inputting this value will cause the application to enter edit retail price | [Edit Retail Price](#edit-retail-price) |
| 5     | Inputting this value will cause the application to enter edit subtitles | [Edit Subtitles](#edit-subtitles) |
| 6     | Inputting this value will cause the application to enter edit frame aspect | [Edit Frame Aspect](#edit-frame-aspect) |
| 7     | Inputting this value will cause the application to enter edit content | [Edit Content](#edit-content) |
| 8     | Inputting this value will cause the application to enter edit additional language tracks | [Edit Additional Language Tracks](#edit-additional-language-tracks) |
| 9     | Inputting this value will cause the application to enter edit additional subtitle tracks | [Edit Additional Subtitle Tracks](#edit-additional-subtitle-tracks) |
| 10     | Inputting this value will cause the application to enter edit bonus features | [Edit Bonus Features](#edit-bonus-features) |
| 11     | Inputting this value will cause the application to navigate back to the maintenance mode menu  | [Maintenance Mode Menu](#using-maintenance-mode)      |

If you selected VHS, you will see the following options.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter edit audio format         | [Edit Audio Format](#edit-audio-format)    |
| 2     | Inputting this value will cause the application to enter edit run time | [Edit Run Time](#edit-run-time) |
| 3     | Inputting this value will cause the application to enter edit language | [Edit Language](#edit-language) |
| 4     | Inputting this value will cause the application to enter edit retail price | [Edit Retail Price](#edit-retail-price) |
| 5     | Inputting this value will cause the application to enter edit subtitles | [Edit Subtitles](#edit-subtitles) |
| 6     | Inputting this value will cause the application to enter edit frame aspect | [Edit Frame Aspect](#edit-frame-aspect) |
| 7     | Inputting this value will cause the application to enter edit packaging | [Edit Packaging](#edit-packaging) |
| 8     | Inputting this value will cause the application to enter edit audio track | [Edit Audio Track](#edit-audio-track) |
| 9     | Inputting this value will cause the application to navigate back to the maintenance mode menu  | [Maintenance Mode Menu](#using-maintenance-mode)      |

\newpage

<!-- Contents Page Stopper --> ### Edit Audio Format

Once you have entered the Audio Format functionality you will be asked to enter the following information:

You need to enter the new Audio Format, this is the new audio format that you want your material to have. Any value is accepted.

![Visual representation of the application asking for a new Audio Format](images/user-guide/maintenance-mode/update-project-material-audio-format.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Run Time

Once you have entered the Edit Run Time functionality you will be asked to enter the following information:

You need to enter the new Run Time, this is the new run time that you want your material to have. Any numeric value is accepted.

![Visual representation of the application asking for a new Run Time](images/user-guide/maintenance-mode/update-project-material-run-time.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Language

Once you have entered the Edit Language functionality you will be asked to enter the following information:

You need to enter the new Language, this is the new language that you want your material to have. Any value is accepted.

![Visual representation of the application asking for a new Language](images/user-guide/maintenance-mode/update-project-material-language.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Retail Price

Once you have entered the Edit Retail Price functionality you will be asked to enter the following information:

You need to enter the new Retail Price, this is the new retail price that you want your material to have. Any numeric value is accepted.

![Visual representation of the application asking for a new Retail Price](images/user-guide/maintenance-mode/update-project-material-retail-price.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Subtitles

Once you have entered the Edit Subtitles functionality you will be asked to enter the following information:

You need to enter the new Subtitles, this is the new subtitles that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Subtitles](images/user-guide/maintenance-mode/update-project-material-subtitles.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Frame Aspect

Once you have entered the Edit Frame Aspect functionality you will be asked to enter the following information:

You need to enter the new Frame Aspect, this is the new frame aspect that you want your material to have. Any value is accepted.

![Visual representation of the application asking for a new Frame Aspect](images/user-guide/maintenance-mode/update-project-material-frame-aspect.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Packaging

Once you have entered the Edit Packaging functionality you will be asked to enter the following information:

You need to select from the list of packaging types, this is the new packaging type that you want your material to have. Any value from 1-2 is accepted.

![Visual representation of the application asking for new Packaging information](images/user-guide/maintenance-mode/update-project-material-packaging.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Content

Once you have entered the Edit Content functionality you will be asked to enter the following information:

You need to enter the new Content details, this is the new content information that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Content information](images/user-guide/maintenance-mode/update-project-material-content.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Additional Language Tracks

Once you have entered the Edit Additional Language Tracks functionality you will be asked to enter the following information

You need to enter the Additional Language Track identifier you wish to update, you can find the identifier in the provided list, an example of this can be seen below:

![Visual representation of the application showing the current Additional Language Track identifiers](images/user-guide/maintenance-mode/update-project-material-additional-language-track-select-id.png)

You need to enter the new Additional Language Tracks details, this is the new additional language tracks information that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Additional Language Tracks information](images/user-guide/maintenance-mode/update-project-material-additional-language-tracks.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Additional Subtitle Tracks

Once you have entered the Edit Subtitle Language Tracks functionality you will be asked to enter the following information

You need to enter the Subtitle Language Track identifier you wish to update, you can find the identifier in the provided list, an example of this can be seen below:

![Visual representation of the application showing the current Additional Subtitle Track identifiers](images/user-guide/maintenance-mode/update-project-material-additional-subtitle-track-select-id.png)

You need to enter the new Additional Subtitle Tracks details, this is the new additional subtitle tracks information that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Additional Subtitle Tracks information](images/user-guide/maintenance-mode/update-project-material-additional-subtitle-tracks.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Bonus Features

Once you have entered the Edit Bonus Features Tracks functionality you will be asked to enter the following information

You need to enter the Bonus Features identifier you wish to update, you can find the identifier in the provided list, an example of this can be seen below:

![Visual representation of the application showing the current Bonus Features identifiers](images/user-guide/maintenance-mode/update-project-material-bonus-feature-select-id.png)

You need to enter the new Bonus Features details, this is the new bonus feature information that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Bonus Features information](images/user-guide/maintenance-mode/update-project-material-bonus-feature.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Audio Track

Once you have entered the Edit Audio Track functionality you will be asked to enter the following information:

You need to enter the new Audio Track details, this is the new audio track that you want your material to have. Any value is accepted.

![Visual representation of the application asking for new Audio Track information](images/user-guide/maintenance-mode/update-project-materials-audio-track.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Remove Project Materials

Once you have entered the Remove Project functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to remove Materials for](images/user-guide/maintenance-mode/remove-project-select-id.png)

Once you have selected a Project ID you will be presented with the associated Material IDs, you need to now select a Material ID from this list and it must be a numeric value.

![Visual representation of selecting a MaterialID to delete](images/user-guide/maintenance-mode/remove-project-materials-select-id.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Add Crew

Once you have entered the Add Crew functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with selecting a project to add crew to](images/user-guide/maintenance-mode/update-project-select-id.png)

Next, you need to enter the Name of the crew member. Any value is accepted.

![Visual representation of the application asking for a Crew members name](images/user-guide/maintenance-mode/add-crew-name.png)

Next, you need to enter the Job Title of the crew member. Any value is accepted.

![Visual representation of the application asking for a Crew members job title](images/user-guide/maintenance-mode/add-crew-job-title.png)

As you can see in CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

### Using Update Crew

Once you have entered the Update Crew functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with selecting a crew member to update](images/user-guide/maintenance-mode/update-project-select-id.png)

Next, you will be asked to enter the crew identifer you wish to update within the previously selected project, you can find the identifier in the provided list, an example of this can be found below:

![Visual representation of selecting a Crew ID to update the information for](images/user-guide/maintenance-mode/update-project-crew-select-crew-id.png)

Next, you will be presented with multiple options, you can use the following keyboard inputs to update certain aspects of the material, to find out more about each update, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter edit crew name         | [Edit Crew Name](#edit-crew-name)    |
| 2     | Inputting this value will cause the application to enter edit crew job title | [Edit Crew Job Title](#edit-run-time) |
| 3     | Inputting this value will cause the application to navigate back to the maintenance mode menu  | [Maintenance Mode Menu](#using-maintenance-mode)      |

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Name

Once you have entered the Edit Crew Name functionality you will be asked to enter the following information:

You need to enter the new Crew Name, this is the new name that you want your crew member to have. Any value is accepted.

![Visual representation of the application asking for a new Crew Name](images/user-guide/maintenance-mode/update-crew-name.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

<!-- Contents Page Stopper --> ### Edit Crew Job Title

Once you have entered the Edit Crew Job Title functionality you will be asked to enter the following information:

You need to enter the new Crew Job Title, this is the new job title that you want your crew member to have. Any value is accepted.

![Visual representation of the application asking for a new Crew Job Title](images/user-guide/maintenance-mode/update-crew-job-title.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Remove Crew

Once you have entered the Remove Crew functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with deleting a crew member](images/user-guide/maintenance-mode/update-project-select-id.png)

Once you submit this Project ID you will need to select the Crew Member to select from the list of IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to update the project for](images/user-guide/maintenance-mode/remove-crew-select-id.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Add Box Office Report

Once you have entered the Add Box Office Report functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to proceed with selecting a crew member to update](images/user-guide/maintenance-mode/update-project-select-id.png)

Once you have selected a Project ID you will be asked to enter the following information:

Next, you need to enter the Week Number, this is the week number that you want your box office report to relate to. Any numeric value is accepted.

![Visual representation of the application asking for a Week Number](images/user-guide/maintenance-mode/add-box-office-report-week-number.png)

Next, you need to enter the Revenue, this is how much money was made during the entered week. Any numeric value is accepted.

![Visual representation of the application asking for a Revenue value](images/user-guide/maintenance-mode/add-box-office-report-revenue.png)

Next, you need to enter the Tickets Sold, this is the amount of tickets sold in the entered week. Any numeric value is accepted.

![Visual representation of the application asking for a Tickets Sold value](images/user-guide/maintenance-mode/add-box-office-report-tickets-sold.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Remove Box Office Report

Once you have entered the Remove Box Office Report functionality you will be asked to enter the following information:

Firstly, you need to enter a Project ID, this must be a numeric value, you can find the accepted Project IDs above the input location, select an ID from this list.

![Visual representation of selecting a Project ID to remove a Box Office Report for](images/user-guide/maintenance-mode/remove-project-select-id.png)

Once you have selected a Project ID you will be presented with the associated Week IDs, you need to now select a Week ID from this list and it must be a numeric value.

![Visual representation of selecting a Box Office Report to delete](images/user-guide/maintenance-mode/remove-box-office-select-id.png)

As you can see in Figure CHANGEFIGUREVALUE, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage


# Conclusion

Discussion and conclusion about your results (reflection on testing approach, reflection on
performance such as computational efficiency, reliability, security, portability, maintainability,
scalability, etc. design of system complexity using e.g. big O- notation).

\newpage

# Appendix

## Managing group work

 Whilst working on this project our group used a multitude of methods to ensure that we were collaborating efficiently and getting the most amount of work completed as possible, these methods included, but are not limited to:

 - Using Facebook Messenger to converse with other group members about certain aspects of the program or documentation, this allowed us to keep in touch and ensure we were on track with the workload.
 - Using GitHub to its full potential, this includes the use of GitHub Issues and Pull Requests in conjunction with code reviews for each major feature. Whenever a bug or issue was discovered the group member that uncovered the issue would create a GitHub issue. If the bug was within another group members individual work then that member would be added as a participant so that they could fix the issue. Once large features were added to the program, pull requests were used with each group member being requested to review the code before merging into the master branch.

Overall, our experience of working as a group has been productive and enjoyable, being able to distribute the workload across group members was an important aspect to the project and allowed us to complete it efficiently. We have all taken learning points from this experience that could be applied to the workplace, or even in our upcoming placements. For example:

- The use of GitHub's features (such as pull requests, issues and code reviewing) will be an excellent skill to have within the workplace, as more often than not, organisations will have some sort of code review system/Quality Assurance (QA) procedure in place and being able to understand how this all works without training will show that you are a competent employee.
- The use of a messaging platform was also important, sometimes organisations have employees working across the globe and having the ability to efficiently collaborate on messaging systems (such as Slack) is an important skill to have. 


## Meeting Minutes

During group meetings a member was nominated to write minutes, these minutes were an important factor during the development of the application as they allowed us to go back and check what work we have all be allocated. On the following pages you can find the minutes for the aforementioned meetings.

![Meeting 1 - Minutes](images/meeting-minutes/meeting-1.png)

![Meeting 2 - Minutes](images/meeting-minutes/meeting-2.png)

![Meeting 3 - Minutes](images/meeting-minutes/meeting-3.png)

![Meeting 4 - Minutes](images/meeting-minutes/meeting-4.png)

![Meeting 5 - Minutes](images/meeting-minutes/meeting-5.png)

![Meeting 6 - Minutes](images/meeting-minutes/meeting-6.png)

# References

[@infotech_2017]
