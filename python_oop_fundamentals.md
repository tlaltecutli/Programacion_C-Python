# Object-Oriented Programming Fundamentals in Python

## Table of Contents
1. [Introduction to OOP](#introduction-to-oop)
2. [Classes and Objects](#classes-and-objects)
3. [Attributes and Methods](#attributes-and-methods)
4. [The Four Pillars of OOP](#the-four-pillars-of-oop)
5. [Special Methods (Magic Methods)](#special-methods-magic-methods)
6. [Class vs Instance Attributes](#class-vs-instance-attributes)
7. [Property Decorators](#property-decorators)
8. [Best Practices](#best-practices)

## Introduction to OOP

Object-Oriented Programming (OOP) is a programming paradigm that organizes code into objects and classes. It allows you to model real-world entities and their relationships, making code more organized, reusable, and maintainable.

**Key Benefits:**
- **Modularity**: Code is organized into separate, interchangeable components
- **Reusability**: Classes can be reused across different parts of a program
- **Maintainability**: Changes to one part of code don't affect other parts
- **Abstraction**: Complex implementations are hidden behind simple interfaces

## Classes and Objects

### What is a Class?
A class is a blueprint or template for creating objects. It defines the attributes (data) and methods (functions) that objects of that class will have.

### What is an Object?
An object is an instance of a class. It's a concrete realization of the class blueprint with actual values for its attributes.

```python
# Define a class
class Car:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 0
    
    def start_engine(self):
        print(f"The {self.year} {self.make} {self.model} engine is now running!")
    
    def drive(self, miles):
        self.odometer += miles
        print(f"Driven {miles} miles. Total odometer: {self.odometer}")

# Create objects (instances)
my_car = Car("Toyota", "Camry", 2020)
friend_car = Car("Honda", "Civic", 2019)

# Use the objects
my_car.start_engine()  # The 2020 Toyota Camry engine is now running!
my_car.drive(100)      # Driven 100 miles. Total odometer: 100
```

### The `__init__` Method
The `__init__` method is a special method called a constructor. It's automatically called when a new object is created and is used to initialize the object's attributes.

```python
class Person:
    def __init__(self, name, age):
        self.name = name  # Instance attribute
        self.age = age    # Instance attribute
        
    def introduce(self):
        print(f"Hi, I'm {self.name} and I'm {self.age} years old.")

person = Person("Alice", 30)
person.introduce()  # Hi, I'm Alice and I'm 30 years old.
```

## Attributes and Methods

### Instance Attributes
Attributes that belong to a specific instance of a class. Each object has its own copy.

### Instance Methods
Functions defined within a class that operate on instance data. They always take `self` as the first parameter.

```python
class BankAccount:
    def __init__(self, account_holder, initial_balance=0):
        self.account_holder = account_holder
        self.balance = initial_balance
        self.transaction_history = []
    
    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transaction_history.append(f"Deposited ${amount}")
            print(f"Deposited ${amount}. New balance: ${self.balance}")
        else:
            print("Deposit amount must be positive")
    
    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            self.transaction_history.append(f"Withdrew ${amount}")
            print(f"Withdrew ${amount}. New balance: ${self.balance}")
        else:
            print("Invalid withdrawal amount")
    
    def get_balance(self):
        return self.balance

# Usage
account = BankAccount("John Doe", 1000)
account.deposit(500)   # Deposited $500. New balance: $1500
account.withdraw(200)  # Withdrew $200. New balance: $1300
print(account.get_balance())  # 1300
```

## The Four Pillars of OOP

### 1. Encapsulation
Bundling data and methods together within a class and controlling access to them.

```python
class Student:
    def __init__(self, name, student_id):
        self.name = name
        self._student_id = student_id  # Protected attribute (convention)
        self.__grade = None            # Private attribute
    
    def set_grade(self, grade):
        if 0 <= grade <= 100:
            self.__grade = grade
        else:
            print("Grade must be between 0 and 100")
    
    def get_grade(self):
        return self.__grade
    
    def display_info(self):
        print(f"Student: {self.name}, ID: {self._student_id}, Grade: {self.__grade}")

student = Student("Alice", "12345")
student.set_grade(95)
print(student.get_grade())  # 95
student.display_info()     # Student: Alice, ID: 12345, Grade: 95

# student.__grade  # This would raise an AttributeError
```

### 2. Inheritance
Creating new classes based on existing classes, inheriting their attributes and methods.

```python
# Base class (Parent)
class Animal:
    def __init__(self, name, species):
        self.name = name
        self.species = species
    
    def make_sound(self):
        print(f"{self.name} makes a sound")
    
    def eat(self):
        print(f"{self.name} is eating")

# Derived class (Child)
class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name, "Canine")  # Call parent constructor
        self.breed = breed
    
    def make_sound(self):  # Override parent method
        print(f"{self.name} barks: Woof!")
    
    def fetch(self):  # New method specific to Dog
        print(f"{self.name} is fetching the ball")

class Cat(Animal):
    def __init__(self, name, color):
        super().__init__(name, "Feline")
        self.color = color
    
    def make_sound(self):
        print(f"{self.name} meows: Meow!")
    
    def climb(self):
        print(f"{self.name} is climbing a tree")

# Usage
dog = Dog("Buddy", "Golden Retriever")
cat = Cat("Whiskers", "Orange")

dog.make_sound()  # Buddy barks: Woof!
dog.eat()         # Buddy is eating (inherited method)
dog.fetch()       # Buddy is fetching the ball

cat.make_sound()  # Whiskers meows: Meow!
cat.climb()       # Whiskers is climbing a tree
```

### 3. Polymorphism
The ability of different classes to be treated as instances of the same type through a common interface.

```python
class Shape:
    def area(self):
        raise NotImplementedError("Subclass must implement area method")
    
    def perimeter(self):
        raise NotImplementedError("Subclass must implement perimeter method")

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def perimeter(self):
        return 2 * (self.width + self.height)

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return 3.14159 * self.radius ** 2
    
    def perimeter(self):
        return 2 * 3.14159 * self.radius

# Polymorphism in action
def print_shape_info(shape):
    print(f"Area: {shape.area()}")
    print(f"Perimeter: {shape.perimeter()}")

shapes = [
    Rectangle(5, 3),
    Circle(4),
    Rectangle(2, 8)
]

for shape in shapes:
    print_shape_info(shape)  # Same function works with different shape types
    print("---")
```

### 4. Abstraction
Hiding complex implementation details and showing only essential features.

```python
from abc import ABC, abstractmethod

class Vehicle(ABC):  # Abstract base class
    def __init__(self, make, model):
        self.make = make
        self.model = model
    
    @abstractmethod
    def start_engine(self):
        pass
    
    @abstractmethod
    def stop_engine(self):
        pass
    
    def display_info(self):  # Concrete method
        print(f"{self.make} {self.model}")

class ElectricCar(Vehicle):
    def start_engine(self):
        print("Electric motor started silently")
    
    def stop_engine(self):
        print("Electric motor stopped")

class GasCar(Vehicle):
    def start_engine(self):
        print("Gas engine started with a roar")
    
    def stop_engine(self):
        print("Gas engine stopped")

# Cannot instantiate abstract class
# vehicle = Vehicle("Generic", "Car")  # This would raise an error

electric_car = ElectricCar("Tesla", "Model 3")
gas_car = GasCar("Ford", "Mustang")

electric_car.display_info()    # Tesla Model 3
electric_car.start_engine()    # Electric motor started silently
```

## Special Methods (Magic Methods)

Special methods allow you to define how objects behave with built-in Python operations.

```python
class Book:
    def __init__(self, title, author, pages):
        self.title = title
        self.author = author
        self.pages = pages
    
    def __str__(self):  # String representation for users
        return f"'{self.title}' by {self.author}"
    
    def __repr__(self):  # String representation for developers
        return f"Book('{self.title}', '{self.author}', {self.pages})"
    
    def __len__(self):  # Define behavior for len() function
        return self.pages
    
    def __eq__(self, other):  # Define behavior for == operator
        if isinstance(other, Book):
            return self.title == other.title and self.author == other.author
        return False
    
    def __lt__(self, other):  # Define behavior for < operator
        if isinstance(other, Book):
            return self.pages < other.pages
        return NotImplemented

book1 = Book("1984", "George Orwell", 328)
book2 = Book("Animal Farm", "George Orwell", 112)

print(book1)           # '1984' by George Orwell
print(repr(book1))     # Book('1984', 'George Orwell', 328)
print(len(book1))      # 328
print(book1 == book2)  # False
print(book2 < book1)   # True (fewer pages)
```

## Class vs Instance Attributes

```python
class Dog:
    species = "Canis lupus"  # Class attribute (shared by all instances)
    
    def __init__(self, name, age):
        self.name = name     # Instance attribute
        self.age = age       # Instance attribute
    
    @classmethod
    def get_species(cls):
        return cls.species
    
    @staticmethod
    def bark_sound():
        return "Woof!"

dog1 = Dog("Buddy", 3)
dog2 = Dog("Max", 5)

print(dog1.species)    # Canis lupus
print(dog2.species)    # Canis lupus
print(Dog.species)     # Canis lupus

print(dog1.name)       # Buddy
print(dog2.name)       # Max

print(Dog.get_species())  # Canis lupus
print(Dog.bark_sound())   # Woof!
```

## Property Decorators

Properties allow you to access methods like attributes, providing controlled access to class data.

```python
class Temperature:
    def __init__(self, celsius=0):
        self._celsius = celsius
    
    @property
    def celsius(self):
        return self._celsius
    
    @celsius.setter
    def celsius(self, value):
        if value < -273.15:
            raise ValueError("Temperature cannot be below absolute zero")
        self._celsius = value
    
    @property
    def fahrenheit(self):
        return (self._celsius * 9/5) + 32
    
    @fahrenheit.setter
    def fahrenheit(self, value):
        self.celsius = (value - 32) * 5/9
    
    @property
    def kelvin(self):
        return self._celsius + 273.15

temp = Temperature(25)
print(temp.celsius)     # 25
print(temp.fahrenheit)  # 77.0
print(temp.kelvin)      # 298.15

temp.fahrenheit = 100
print(temp.celsius)     # 37.77777777777778
```

## Best Practices

### 1. Use Meaningful Names
```python
# Good
class BankAccount:
    def calculate_interest(self):
        pass

# Avoid
class BA:
    def calc_int(self):
        pass
```

### 2. Keep Classes Focused (Single Responsibility Principle)
```python
# Good - Each class has a single responsibility
class User:
    def __init__(self, username, email):
        self.username = username
        self.email = email

class EmailSender:
    def send_email(self, user, message):
        pass

# Avoid - User class doing too many things
class User:
    def __init__(self, username, email):
        self.username = username
        self.email = email
    
    def send_email(self, message):  # This should be separate
        pass
```

### 3. Use Composition Over Inheritance When Appropriate
```python
# Composition example
class Engine:
    def start(self):
        print("Engine started")

class Car:
    def __init__(self):
        self.engine = Engine()  # Car "has-a" Engine
    
    def start(self):
        self.engine.start()
```

### 4. Document Your Classes
```python
class Rectangle:
    """
    A class representing a rectangle.
    
    Attributes:
        width (float): The width of the rectangle
        height (float): The height of the rectangle
    """
    
    def __init__(self, width, height):
        """
        Initialize a Rectangle.
        
        Args:
            width (float): The width of the rectangle
            height (float): The height of the rectangle
        """
        self.width = width
        self.height = height
    
    def area(self):
        """Calculate and return the area of the rectangle."""
        return self.width * self.height
```

This document covers the fundamental concepts of object-oriented programming in Python. Practice these concepts by creating your own classes and experimenting with inheritance, encapsulation, polymorphism, and abstraction to build robust, maintainable code.