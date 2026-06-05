# CPP Modules 00-09

![Score](https://img.shields.io/badge/score-100%2F100-success)
![C++](https://img.shields.io/badge/language-C++98-blue)
![OOP](https://img.shields.io/badge/concept-OOP-success)

## 📑 Table of Contents
- [📌 Overview](#-overview)
- [💡 Core Concept Explored](#-core-concept-explored)
- [📥 How to Clone](#-how-to-clone)
- [🚀 The Modules Breakdown](#-the-modules-breakdown)
  - [CPP 00: Basics of OOP](#cpp-00-basics-of-oop)
  - [CPP 01: Memory Allocation](#cpp-01-memory-allocation)
  - [CPP 02: Polymorphism & Orthodox Canonical Form](#cpp-02-polymorphism--orthodox-canonical-form)
  - [CPP 03: Inheritance](#cpp-03-inheritance)
  - [CPP 04: Subtype Polymorphism](#cpp-04-subtype-polymorphism)
  - [CPP 05: Exceptions](#cpp-05-exceptions)
  - [CPP 06: C++ Casts](#cpp-06-c-casts)
  - [CPP 07: C++ Templates](#cpp-07-c-templates)
  - [CPP 08: STL & Iterators](#cpp-08-stl--iterators)
  - [CPP 09: Advanced STL](#cpp-09-advanced-stl)
- [🛠️ Usage](#️-usage)
- [🧠 What I Learned](#-what-i-learned)

## 📌 Overview
Welcome to the **CPP Modules** repository! These projects were completed at 1337 (42 Network) to teach Object-Oriented Programming (OOP) using C++98.

As a Software Engineer, OOP is a crucial paradigm for building scalable, maintainable, and modular software. These modules transition from procedural C to advanced C++ paradigms.

## 💡 Core Concept Explored
### Object-Oriented Programming (OOP)
**Definition:** OOP is a programming paradigm based on the concept of "objects," which can contain data (attributes) and code (methods). It focuses on organizing software design around data, rather than functions and logic.
**Problem Solved:** OOP solves the complexity of procedural code by promoting code reusability, modularity, and encapsulation, making large-scale software systems easier to maintain and extend.

## 📥 How to Clone
To clone this project, use the following command:
```bash
git clone git@github.com:Anasqabbal/CPP.git
cd CPP
```

## 🚀 The Modules Breakdown

### CPP 00: Basics of OOP
- **Concept Learned:** Namespaces, classes, member functions, initialization lists.
- **Problem Solved:** Transitioning from unstructured procedural logic to self-contained objects.
- **Implemented Concept:** Creating basic classes with encapsulated state and behaviors.

### CPP 01: Memory Allocation
- **Concept Learned:** `new`/`delete`, references, and pointers to members.
- **Problem Solved:** Safe dynamic memory management natively in C++ instead of using `malloc`/`free`.
- **Implemented Concept:** RAII (Resource Acquisition Is Initialization) basics and heap vs. stack allocation.

### CPP 02: Polymorphism & Orthodox Canonical Form
- **Concept Learned:** Ad-hoc polymorphism, operator overloading, and Canonical classes.
- **Problem Solved:** Allowing operators and functions to behave differently depending on the types of arguments, creating uniform and safe copy semantics.
- **Implemented Concept:** Fixed-point numbers class and operator overloads.

### CPP 03: Inheritance
- **Concept Learned:** Class inheritance and protected visibility.
- **Problem Solved:** Code duplication by allowing classes to inherit attributes and methods from base classes.
- **Implemented Concept:** A game-like character hierarchy inheriting from a base `ClapTrap` class.

### CPP 04: Subtype Polymorphism
- **Concept Learned:** Subtype polymorphism, abstract classes, and virtual functions.
- **Problem Solved:** Designing interfaces that can be implemented differently by various derived classes, decoupling usage from specific implementations.
- **Implemented Concept:** Animal interfaces and deep copy implementation of internal states like a "Brain".

### CPP 05: Exceptions
- **Concept Learned:** Exceptions handling (`try`/`catch`/`throw`).
- **Problem Solved:** Handling runtime errors cleanly without cluttering the main logic with return code checks.
- **Implemented Concept:** A hierarchical bureaucrat structure with custom exception classes.

### CPP 06: C++ Casts
- **Concept Learned:** C++ Casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`).
- **Problem Solved:** Safe and explicit type conversions depending on the underlying memory semantics.
- **Implemented Concept:** Serializers, type identifiers, and explicit type conversion programs.

### CPP 07: C++ Templates
- **Concept Learned:** Function templates and class templates.
- **Problem Solved:** Writing type-agnostic code, preventing code duplication for different variable types.
- **Implemented Concept:** A generic array class and generic utility functions.

### CPP 08: STL & Iterators
- **Concept Learned:** Templated containers, iterators, and standard algorithms.
- **Problem Solved:** Efficient data storage, retrieval, and manipulation using standard, optimized data structures instead of raw arrays.
- **Implemented Concept:** Stacks, vectors, and custom search/manipulation algorithms.

### CPP 09: Advanced STL
- **Concept Learned:** Advanced Standard Template Library usage.
- **Problem Solved:** Applying complex, specific algorithmic logic to practical parsing and mathematical tasks.
- **Implemented Concept:** A Bitcoin exchange rate calculator, Reverse Polish Notation evaluator, and the Ford-Johnson sorting algorithm.

## 🛠️ Usage
Each module has its own directory (e.g., `CPP-00`, `CPP-01`). Inside each module, there are specific exercises. 
Navigate to the specific exercise directory, compile, and run the basic tests using the `Makefile` provided in that directory:
```bash
cd CPP-00/ex00
make
./<executable_name> # (e.g., ./megaphone)
```

## 🧠 What I Learned
- Deep understanding of Object-Oriented Design (OOD) principles.
- The Orthodox Canonical Class Form (Constructors, Copy Constructors, Assignment Operators, Destructors).
- Safe memory management in C++ (RAII).
- The power of Templates and the STL for generic programming.

## 🌐 Connect with me
[![GitHub](https://img.shields.io/badge/GitHub-black?logo=github)](https://github.com/Anasqabbal)
[![LinkedIn](https://img.shields.io/badge/-IN-0A66C2?logo=linkedin&logoColor=0a66c2)](https://www.linkedin.com/in/anasqabbal/)

