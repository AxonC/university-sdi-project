---
title: "Software Design and Implementation"
author: [Callum Axon (N0727303), Callum Carney (N0741707), Matthew Robinson (N0724629)]
date: "2019-04-28"
subtitle: "TrekStar Software System"
lang: "en"
titlepage: true
titlepage-color: "06386e"
titlepage-text-color: "FFFFFF"
titlepage-rule-color: "FFFFFF"
titlepage-rule-height: 1
...

# Table of Contents

- [Table of Contents](#table-of-contents)
- [Contributions](#contributions)
	- [Callum Axon (N0727303)](#callum-axon-n0727303)
	- [Callum Carney (N0741707)](#callum-carney-n0741707)
	- [Matthew Robinson (N0724629)](#matthew-robinson-n0724629)
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
- [Internal Data Structures](#internal-data-structures)
- [Search/Sorting Algorithm](#searchsorting-algorithm)
- [UI Screenshots](#ui-screenshots)
- [Software Testing Prodcedure](#software-testing-prodcedure)
- [User Manual](#user-manual)
- [Conclusion](#conclusion)
- [Appendix](#appendix)

\newpage

# Contributions

## Callum Axon (N0727303)
* Stuff

## Callum Carney (N0741707)
* Other Stuff

## Matthew Robinson (N0724629)
* More Stuff

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

1. An indivdual user will have the TrekStar project management system installed on their machine, using a locally stored JSON Database.
2. TrekStar Pictures will release the TrekStar project management system company-wide, using a shared JSON Database for each installation.

These two deployments are different due to the change in the data storage location, in which the latter will support company-wide collaboration through the application. 

However, no matter where the application is installed the following Operating Systems are supported:

* Windows
* Mac OS
* Linux

On the following pages you can find a visual representation of the aformentioned Deployment scenarios.

## Individual Installation
![Visual Representation of Individual TrekStar installation](deployment-diagrams/trekstar-individual-installation.png)

## Company-Wide Installation
![Visual Represenation of Company-Wide TrekStar installation](deployment-diagrams/trekstar-company-installation.png)

\newpage

# Design Pattern

Include explaination of any design patterns used

\newpage

# Planned Architecture

An explanation of the planned architecture and the reason of the choices according to ATAM
(follow step 4 and 5, i.e., identify possible architecture styles and choose one with respect to
the identified utility tree, you need to explain the reason).

\newpage

# Included C++ Libraries

Include explaination of any C++ Libraries used

\newpage

# Internal Data Structures

Include explaination of what internal data structures were used.

\newpage

# Search/Sorting Algorithm

Include explaination of the search/sorting algo used.

\newpage

# UI Screenshots

Include screenshots of console app here.

\newpage

# Software Testing Prodcedure

Include explaination of software testing procedure here.

\newpage

# User Manual

Include user manual here

\newpage

# Conclusion

Discussion and conclusion about your results (reflection on testing approach, reflection on
performance such as computational efficiency, reliability, security, portability, maintainability,
scalability, etc. design of system complexity using e.g. big O- notation).

\newpage

# Appendix

\newpage