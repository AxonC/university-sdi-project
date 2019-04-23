---
title: "Software Design and Implementation"
author: [Callum Axon (N0727303), Callum Carney (N0741707), Matthew Robinson (N0724629)]
subtitle: "TrekStar Software System"
lang: "en"
linkcolor: darkgray
titlepage: true
titlepage-color: "06386e"
titlepage-text-color: "FFFFFF"
titlepage-rule-color: "FFFFFF"
titlepage-rule-height: 1
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
- [Class Diagram](#class-diagram)
	- [Cohesion and Coupling Considerations](#cohesion-and-coupling-considerations)
- [Sequence Diagram](#sequence-diagram)
- [State Diagram](#state-diagram)
- [Component Diagram](#component-diagram)
- [Deployment Diagram](#deployment-diagram)
	- [Individual Installation](#individual-installation)
	- [Company-Wide Installation](#company-wide-installation)
- [Design Pattern](#design-pattern)
- [Planned Architecture](#planned-architecture)
- [Included C++ Libraries](#included-c-libraries)
	- [JSON for C++ (GitHub Link)](#json-for-c-github-link)
	- [GTest (GitHub Link)](#gtest-github-link)
	- [spdlog (GitHub Link)](#spdlog-github-link)
- [Internal Data Structures](#internal-data-structures)
- [Search/Sorting Algorithm](#searchsorting-algorithm)
- [UI Screenshots](#ui-screenshots)
- [Software Testing Procedure](#software-testing-procedure)
- [User Manual](#user-manual)
	- [Software Introduction](#software-introduction)
	- [Using the Main Menu](#using-the-main-menu)
	- [Using View Mode](#using-view-mode)
		- [Using List Projects](#using-list-projects)
		- [Using Search Projects](#using-search-projects)
		- [Using List Materials](#using-list-materials)
	- [Using Maintenance Mode](#using-maintenance-mode)
		- [Using Add Project](#using-add-project)
		- [Using Remove Projects](#using-remove-projects)
- [Conclusion](#conclusion)
- [Appendix](#appendix)
	- [Managing group work](#managing-group-work)
	- [Meeting Minutes](#meeting-minutes)

\newpage

# Todo - **_remove me before submission pls_**

## User Guide
  - [Using List Materials](#using-list-materials) requires screenshot that shows projectid listings when id issue is resolved.
  - [Using Maintenance Mode](#using-maintenance-mode) requires screenshot of the maintenance main menu when remove project is added.
  - User guide details required for when the application is able to manage crew and materials/projects fully.
  - Update [Using Add Project](#using-add-project) to reflect changes to saving a project.

\newpage

# Contributions

## Callum Axon (N0727303) - Member A
* Class Diagram
* A description of how cohesion and coupling have been considered in the class design
* An explanation of the internal data structures used and the reason for the choices.
  
## Callum Carney (N0741707) - Member C
* Component Diagrams
* Deployment Diagrams
* Screenshots of User Interface

## Matthew Robinson (N0724629) - Member B
* Sequence diagram
* State machine diagram
* An explanation of the search or sorting algorithm used

All other contributions have been completed as part of a group effort.

\newpage

# System Description

The Trekstar system has been developed in order to allow TrekStar Pictures to accomplish the following

- Create and Manage Projects including any relevant metadata
- Create and Manage Project Materials (single-sided DVDs, Blu-rays, etc)
- Create Projects that are "unreleased" and cannot be modified once created
- Include details in regards to the crew working on a Project

\newpage

# Class Diagram

Include class diagram here.

## Cohesion and Coupling Considerations

A justification and explanation of how cohesion and coupling have been considered in the
design. 

\newpage

# Sequence Diagram

Include sequence diagram here

\newpage

# State Diagram

Include state diagram here

\newpage

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

Include explanation of any design patterns used

\newpage

# Planned Architecture

An explanation of the planned architecture and the reason of the choices according to ATAM
(follow step 4 and 5, i.e., identify possible architecture styles and choose one with respect to
the identified utility tree, you need to explain the reason).

\newpage

# Included C++ Libraries

Within the TrekStar project management application we have used some C++ Libraries for parsing data, providing access to unit tests and including core functionality that would otherwise not be present. Below you can find an explanation of the included C++ libraries and why we chose to use them:

## JSON for C++ ([GitHub Link](https://github.com/nlohmann/json))
We decided to use the JSON for C++ library within the application because we are using JSON as our database to store all of the users data. The JSON for C++ library allows us to parse JSON data, request data based on certain keys within a JSON Array or Object and create new JSON Arrays or Objects to be inserted into the database. The JSON for C++ library is quite easily the most feature complete and well documented library for parsing and creating JSON in C++, this was the main driving force behind using this library as we required something that is reliable and suitable for the applications use cases.

## GTest ([GitHub Link](https://github.com/google/googletest))
We decided to use GTest as our primary unit testing library within the application, whilst we could have used Boost for unit testing, we decided that GTest had the following advantages which solidified our decision to use GTest:

- GTest is much more lightweight when compared to Boost, while GTest is specifically a testing library, Boost has more functionality that also needs to be imported to allow for the Unit Testing section of the library to function, consequently making it larger and less lightweight.
- When compared to other Unit Testing libraries there are more features that we can make use of in the project within GTest, for example, we can use GTests ability to mock objects, this is useful when we need to test the interaction between objects as we can achieve this more efficiently when compared to other libraries. We can also avoid duplication of test setup (creating objects, etc) within each unit test by specifying test fixtures which can be referenced within the unit tests.

## spdlog ([GitHub Link](https://github.com/gabime/spdlog))
We decided to use spdlog for our logger library, when compared to other libraries spdlog is lightweight, fast and only requires header imports to get started. spdlog also supports all of the operating systems that our application has been developed to work on, which is an important feature to have.

spdlog also allows us to easily generate the required daily reports based on the data we pass from the JSON database, the simplicity of this library was an important consideration as it allows future developers to quickly understand how this function works incase a new feature or bug needs to be added/fixed.

\newpage

# Internal Data Structures

Include explanation of what internal data structures were used.

\newpage

# Search/Sorting Algorithm

Include explanation of the search/sorting algo used.

\newpage

# UI Screenshots

Include screenshots of console app here.

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

We are confident that these constraints will allow us to develop the application with fewer interruptions and ensure that only high quality, tested code is being pushed to the repository. 

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
| 2     | Inputting this value will cause the application to enter search mode for materials | [Using Search Projects](#using-search-projects) |
| 3     | Inputting this value will cause the application to list materials                  | [Listing Materials](#using-list-materials) |
| 4     | Inputting this value will cause the application to navigate back to the [Main Menu](#using-the-main-menu)  | Not required           |

\newpage

### Using List Projects

Once you have entered the List Projects functionality you will be asked if you wish to sort all of the projects by their title, you can enter _`y`_ to confirm that you wish for the projects to be order by their titles and _`n`_ to decline.

![Visual representation of the application asking if you wish to sort by title](images/user-guide/view-mode/sort-by-title.png)

You will now see the projects that are held within your applications database, you can see an example of this below.

![Visual representation of project listings](images/user-guide/view-mode/listed-projects.png)

As you can see in Figure 6, there are more options available to you, these options allow you to navigate through the projects. You can see the associated input actions below.

| Input Value | Command Action                                                                
| :----------: | ------------------------------------------------------------------------- |
| 1     | This will cause the application to move onto the next project in the database              |
| 2     | This will cause the application to move onto the previous project in the database | 
| 3     | This will cause the application to navigate back to [View Mode](#using-view-mode)              | 

\newpage

### Using Search Projects

Once you have entered the Search Projects functionality you will be asked to input a search query, this can be any value and data will only be returned if there is an associated project title held within the database.

![Visual representation of the application asking for a search query](images/user-guide/view-mode/project-title-search.png)

You will now see the associated projects that matched to your search query, you can see an example of this below.

![Visual representation of a project being discovered from a search query](images/user-guide/view-mode/project-search-term.png)

As you can see in Figure 8, there are more options available to you, these are the options associated with [View Mode](#using-view-mode), therefore you can find more information by reading the [View Mode](#using-view-mode) section of this user guide.

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

![Visual representation of Maintenance Mode](images/user-guide/view-mode/using-maintenance-mode.png)

Once on this screen, you can use the following keyboard inputs to navigate around maintenance mode, to find out more about each feature, click the associated information link.

| Input Value | Command Action                                                                     | Information Link                               |
| :----------: | ------------------------------------------------------------------------- | ---------------------------------------------- |
| 1     | Inputting this value will cause the application to enter add project             | [Adding Projects](#using-add-project)       |
| 2     | Inputting this value will cause the application to enter remove project | [Removing Projects](#using-remove-projects) |
| 3     | Inputting this value will cause the application to save all changes to the database           | Not required |
| 4     | Inputting this value will cause the application to navigate back to the [Main Menu](#using-the-main-menu)  | Not required           |

\newpage

### Using Add Project

Once you have entered the Add Project functionality you will be asked to enter the following information:


Firstly, you will be asked to enter the Project Title, this is the name that you want your project to be called. Any value is accepted.

![Visual representation of the application asking for a Project Title](images/user-guide/maintenance-mode/add-project-title.png)

Next, you will be asked if the project has been released. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project has been released and _`n`_ confirming that the project has not been released.

![Visual representation of the application asking if the project has been released](images/user-guide/maintenance-mode/add-project-released.png)

Next, you will be asked if the project will be playing in theaters. Only the values _`y`_ and _`n`_ are accepted. With _`y`_ confirming that the project will be playing in theatres and _`n`_ confirming that the project will not be playing in theatres.

![Visual representation of the application asking if the project will be playing in theatres](images/user-guide/maintenance-mode/add-project-theatres.png)

Next, you will be asked how many keywords you would like associating with the project. Any numeric value is accepted.

![Visual representation of the application asking how many keywords should be associated with the project](images/user-guide/maintenance-mode/add-project-keywords-amount.png)

Finally, you will be asked what keywords you would like associated with the project, the amount of keywords requests depends on the previously entered numeric value. Any value is accepted.

![Visual representation of the application asking for a keyword](images/user-guide/maintenance-mode/add-project-keywords.png)

As you can see in Figure 16, there are more options available to you, these are the options associated with [Maintenance Mode](#using-maintenance-mode), therefore you can find more information by reading the [Maintenance Mode](#using-maintenance-mode) section of this user guide.

\newpage

### Using Remove Projects

todo

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

\newpage