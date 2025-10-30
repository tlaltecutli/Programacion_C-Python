# 🎓 Object-Oriented Programming (OOP) Course

## 🧭 1. Course Overview
This course provides a comprehensive introduction to **Object-Oriented Programming (OOP)** principles, design patterns, and best practices.  
It emphasizes **abstraction**, **encapsulation**, **inheritance**, and **polymorphism** using a modern programming language (Python, Java, or C++).

### **Prerequisites**
- Basic programming knowledge (variables, control structures, functions).  
- Familiarity with at least one high-level language (e.g., Python, C, JavaScript).

### **Duration**
10–12 weeks  
**Structure:** 2 hours lecture + 1 hour lab per week

---

## 🎯 2. Course Objectives
By the end of this course, students will be able to:

1. Understand the key concepts of object-oriented programming.  
2. Apply encapsulation, inheritance, and polymorphism in program design.  
3. Design modular, reusable, and maintainable software.  
4. Use UML diagrams to model object-oriented systems.  
5. Implement real-world applications using OOP principles.  
6. Apply common design patterns and solid software design principles.

---

## 🧩 3. Learning Outcomes
Students who successfully complete this course will be able to:

- Define and manipulate **classes** and **objects**.  
- Implement **constructors**, **methods**, and **properties**.  
- Differentiate between **class variables** and **instance variables**.  
- Create **class hierarchies** and apply **inheritance** effectively.  
- Override and overload methods.  
- Apply **polymorphism** for code generalization.  
- Use **interfaces** and **abstract classes**.  
- Design and implement **OOP-based applications**.

---

## 📚 4. Course Modules

### **Module 1. Introduction to OOP**
**Topics**
- From procedural to object-oriented programming.  
- Advantages and applications of OOP.  
- The four pillars: abstraction, encapsulation, inheritance, polymorphism.  
- Classes vs. objects.

**Lab**
Create a simple `Car` class with attributes and methods.

---

### **Module 2. Classes, Objects, and Methods**
**Topics**
- Defining a class.  
- Creating objects and accessing attributes.  
- Instance vs. class attributes.  
- Method definitions and `self`/`this`.  
- Constructors and destructors.

**Example (Python)**
```python
class Car:
    def __init__(self, brand, model):
        self.brand = brand
        self.model = model

    def start_engine(self):
        print(f"The {self.brand} {self.model} engine starts.")
```

**Lab**
Build a `BankAccount` class with `deposit()` and `withdraw()` methods.

---

### **Module 3. Encapsulation and Data Hiding**
**Topics**
- Public, protected, and private members.  
- Getters and setters.  
- Property decorators.  
- Importance of encapsulation.

**Lab**
Implement a `Student` class with private attributes and property accessors.

---

### **Module 4. Inheritance and Code Reuse**
**Topics**
- Base and derived classes.  
- Method overriding.  
- The `super()` function.  
- Multiple inheritance.

**Example**
```python
class Vehicle:
    def move(self):
        print("Moving...")

class Car(Vehicle):
    def move(self):
        print("Driving a car.")
```

**Lab**
Implement a class hierarchy for `Shape → Rectangle → Square`.

---

### **Module 5. Polymorphism and Abstract Classes**
**Topics**
- Method overriding and dynamic method dispatch.  
- Interfaces and abstract base classes.  
- Duck typing (Python).

**Lab**
Implement polymorphic behavior for different `Payment` types (`CreditCard`, `PayPal`, etc.).

---

### **Module 6. Composition and Aggregation**
**Topics**
- Difference between inheritance and composition.  
- “Has-a” vs. “Is-a” relationships.  
- Implementing composition in design.

**Lab**
Create a `Library` class composed of multiple `Book` objects.

---

### **Module 7. Error Handling and Exceptions**
**Topics**
- Exception classes.  
- Custom exceptions.  
- Handling exceptions in constructors and methods.

**Lab**
Implement a `BankAccount` class that raises exceptions for insufficient funds.

---

### **Module 8. UML and Object Modeling**
**Topics**
- Class diagrams.  
- Sequence diagrams.  
- Object interaction modeling.

**Lab**
Model an online shopping system using UML diagrams.

---

### **Module 9. Design Patterns and Best Practices**
**Topics**
- Introduction to design patterns.  
- Singleton, Factory, Observer, Strategy patterns.  
- SOLID principles.

**Lab**
Implement a simple Factory pattern in code.

---

### **Module 10. Capstone Project**
**Objective**
Develop a complete OOP-based application (e.g., Inventory Management, Library System, Hotel Reservation).

**Deliverables**
- UML design.  
- Source code with documentation.  
- Presentation and demonstration.

---

## 🧮 5. Assessment and Evaluation
| Component | Weight |
|------------|---------|
| Weekly assignments & labs | 30% |
| Midterm exam | 20% |
| Final project | 40% |
| Participation | 10% |

---

## 📘 6. Recommended Resources

### **Textbooks**
- Booch, G. *Object-Oriented Analysis and Design with Applications.* Addison-Wesley, 3rd ed.  
- Lafore, R. *Object-Oriented Programming in C++.* Sams Publishing.  
- Lutz, M. *Learning Python.* O’Reilly Media.

### **Online Resources**
- [Python Language Reference](https://docs.python.org/3/)  
- [Oracle Java Tutorials](https://docs.oracle.com/javase/tutorial/)  
- [Design Patterns in Python](https://refactoring.guru/design-patterns)

---

## 🧠 Instructor Notes
- Reinforce the difference between OOP principles through **interactive examples**.  
- Encourage students to apply OOP principles in small personal projects.  
- Gradually introduce **UML diagrams** before the final project.

---

## 🧩 Suggested Tools
- Python 3.x or Java SDK  
- VS Code / PyCharm / IntelliJ IDEA  
- UML Designer, Draw.io, or Lucidchart

---

## 🏁 End of Course
> “Programs must be written for people to read, and only incidentally for machines to execute.”  
> — *Harold Abelson*
