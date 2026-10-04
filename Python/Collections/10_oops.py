"""
10. OOPS in Python (mirrors the C++ OOPS/ folder: oops_1 .. oops_11)
-------------------------------------------------------------------
Class & Object | Encapsulation | Constructor | self (this) | Shallow/Deep copy |
Destructor | Inheritance | Types of inheritance | Polymorphism | Abstraction | Static
+ Python extras: dunder methods, @property, dataclass, __slots__
"""

import copy
from abc import ABC, abstractmethod
from dataclasses import dataclass, field

# ============================================================
# 1. Class & Object  (oops_1)
# ============================================================
class Teacher:
    school = "ABC School"              # CLASS attribute (shared by all objects)

    def __init__(self, name, dept, salary):   # constructor
        self.name = name               # INSTANCE attributes
        self.dept = dept
        self.salary = salary

    def change_dept(self, new_dept):   # instance method -> first param is `self`
        self.dept = new_dept

    def get_info(self):
        return f"{self.name} ({self.dept})"

t1 = Teacher("Shradha", "CS", 25000)
t1.change_dept("IT")
print(t1.get_info(), Teacher.school, t1.school)

# ============================================================
# 2. Encapsulation & access modifiers  (oops_2)
#    Python has NO real private. Convention:
#      name     -> public
#      _name    -> protected (internal use)
#      __name   -> private (name-mangled to _Class__name)
# ============================================================
class Account:
    def __init__(self, owner, balance):
        self.owner = owner
        self._type = "savings"
        self.__balance = balance       # private

    # getter via @property (Pythonic replacement for getBalance())
    @property
    def balance(self):
        return self.__balance

    # setter with validation
    @balance.setter
    def balance(self, value):
        if value < 0:
            raise ValueError("balance can't be negative")
        self.__balance = value

    def deposit(self, amt):
        self.__balance += amt

acc = Account("Tanmay", 100)
acc.deposit(50)
acc.balance = 200                      # calls setter
print(acc.balance)                     # calls getter -> 200
# print(acc.__balance)                 # AttributeError
print(acc._Account__balance)           # name mangling (don't do this in real code)

# ============================================================
# 3. Constructors  (oops_3)
#    No overloading in Python -> use default args or @classmethod factories
# ============================================================
class Student:
    def __init__(self, name="Unknown", marks=None):
        self.name = name
        self.marks = marks if marks is not None else []   # avoid mutable default!

    @classmethod
    def from_string(cls, s):           # alternative constructor
        name, *marks = s.split(",")
        return cls(name, list(map(int, marks)))

s1 = Student()                         # "non-parameterized"
s2 = Student("Aman", [90, 80])         # parameterized
s3 = Student.from_string("Riya,95,88")

# ============================================================
# 4. self  (oops_4 : `this` pointer)
#    `self` is the explicit reference to the current object.
#    Return self for method chaining.
# ============================================================
class Builder:
    def __init__(self):
        self.parts = []
    def add(self, p):
        self.parts.append(p)
        return self                    # like `return *this`
print(Builder().add("a").add("b").parts)

# ============================================================
# 5. Shallow vs Deep copy  (oops_5 : copy constructor)
# ============================================================
s4 = copy.copy(s2)                     # shallow: s4.marks IS s2.marks
s5 = copy.deepcopy(s2)                 # deep: independent marks list
s2.marks.append(70)
print(s4.marks, s5.marks)              # [90,80,70] [90,80]
alias = s2                             # NOT a copy, same object
print(alias is s2)                     # True

# ============================================================
# 6. Destructor  (oops_6)
#    __del__ runs when refcount hits 0 (timing not guaranteed). Rarely needed;
#    use context managers (`with`) for resource cleanup instead.
# ============================================================
class Resource:
    def __init__(self, name):
        self.name = name
    def __del__(self):
        print(f"destroying {self.name}")
    # context manager protocol
    def __enter__(self):
        return self
    def __exit__(self, exc_type, exc, tb):
        print(f"closing {self.name}")

r = Resource("temp")
del r                                  # -> destroying temp
with Resource("file") as f:
    pass                               # -> closing file (then destroyed)

# ============================================================
# 7. Inheritance  (oops_7)
# ============================================================
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def intro(self):
        return f"I am {self.name}"

class StudentP(Person):                # single inheritance
    def __init__(self, name, age, roll):
        super().__init__(name, age)    # call parent constructor
        self.roll = roll
    def intro(self):                   # method overriding
        return super().intro() + f", roll {self.roll}"

sp = StudentP("Raj", 20, 7)
print(sp.intro())
print(isinstance(sp, Person), issubclass(StudentP, Person))

# ============================================================
# 8. Types of inheritance  (oops_8)
# ============================================================
class GradStudent(StudentP):           # multilevel: Person -> StudentP -> GradStudent
    pass

class Teacher2(Person):                # hierarchical: Person -> StudentP, Teacher2
    pass

class A:
    def hello(self): return "A"
class B(A):
    def hello(self): return "B->" + super().hello()
class C(A):
    def hello(self): return "C->" + super().hello()
class D(B, C):                         # multiple + diamond (hybrid)
    def hello(self): return "D->" + super().hello()

print(D().hello())                     # D->B->C->A  (follows MRO)
print([cls.__name__ for cls in D.__mro__])   # Method Resolution Order

# ============================================================
# 9. Polymorphism  (oops_9)
#    - Method overriding (runtime)  -> shown above
#    - Duck typing: "if it quacks like a duck..."
#    - Operator overloading via dunder methods
#    - "Overloading" via default / *args
# ============================================================
class Dog:
    def speak(self): return "Woof"
class Cat:
    def speak(self): return "Meow"
for animal in (Dog(), Cat()):
    print(animal.speak())              # no common base class needed

def add(*args):                        # variable args ~ overloading
    return sum(args)
print(add(1, 2), add(1, 2, 3))

def describe(**kwargs):                # keyword args
    return ", ".join(f"{k}={v}" for k, v in kwargs.items())
print(describe(a=1, b=2))

# ============================================================
# 10. Abstraction  (oops_10 : pure virtual function / abstract class)
# ============================================================
class Shape(ABC):
    @abstractmethod
    def area(self) -> float:
        ...

class Circle(Shape):
    def __init__(self, r):
        self.r = r
    def area(self):
        return 3.14159 * self.r ** 2

class Square(Shape):
    def __init__(self, a):
        self.a = a
    def area(self):
        return self.a * self.a

# Shape()                              # TypeError: can't instantiate abstract class
print([round(s.area(), 2) for s in (Circle(1), Square(2))])

# ============================================================
# 11. Static  (oops_11)
#    class attribute = static member variable
#    @staticmethod   = static function (no self, no cls)
#    @classmethod    = gets the class (cls), can access class attributes
# ============================================================
class Counter:
    count = 0                          # static variable

    def __init__(self):
        Counter.count += 1             # modify via class, NOT self.count += 1

    @staticmethod
    def is_valid(x):
        return x >= 0

    @classmethod
    def how_many(cls):
        return cls.count

Counter(); Counter()
print(Counter.how_many(), Counter.is_valid(-1))

# ============================================================
# 12. Dunder (magic) methods -> operator overloading & built-in support
# ============================================================
class Vector:
    def __init__(self, x, y):
        self.x, self.y = x, y
    def __repr__(self):                # for debugging: repr(v), shown in lists
        return f"Vector({self.x}, {self.y})"
    def __str__(self):                 # for print(v)
        return f"({self.x}, {self.y})"
    def __add__(self, o):              # v1 + v2
        return Vector(self.x + o.x, self.y + o.y)
    def __sub__(self, o):
        return Vector(self.x - o.x, self.y - o.y)
    def __mul__(self, k):              # v * 3
        return Vector(self.x * k, self.y * k)
    def __eq__(self, o):               # ==
        return (self.x, self.y) == (o.x, o.y)
    def __hash__(self):                # needed if __eq__ defined & used in set/dict
        return hash((self.x, self.y))
    def __lt__(self, o):               # < -> enables sorted() & heapq
        return (self.x, self.y) < (o.x, o.y)
    def __len__(self):                 # len(v)
        return 2
    def __getitem__(self, i):          # v[0]
        return (self.x, self.y)[i]
    def __iter__(self):                # for c in v / unpacking
        yield self.x
        yield self.y
    def __contains__(self, val):       # val in v
        return val in (self.x, self.y)
    def __bool__(self):                # if v:
        return bool(self.x or self.y)
    def __call__(self):                # v()
        return (self.x ** 2 + self.y ** 2) ** 0.5

v1, v2 = Vector(1, 2), Vector(3, 4)
print(v1 + v2, v1 * 3, v1 == Vector(1, 2), v1 < v2, len(v1), v1[0], list(v2), 2 in v1, v2())
print(sorted([v2, v1]), {v1, Vector(1, 2)})

# ============================================================
# 13. @dataclass -> auto __init__, __repr__, __eq__ (and ordering)
# ============================================================
@dataclass(order=True)                 # order=True -> __lt__ etc. by field order
class Item:
    priority: int
    name: str = field(compare=False)
    tags: list = field(default_factory=list, compare=False)

items = sorted([Item(3, "c"), Item(1, "a")])
print(items[0])                        # Item(priority=1, name='a', tags=[])

@dataclass(frozen=True)                # immutable + hashable
class Pt:
    x: int
    y: int
print({Pt(1, 2): "ok"}[Pt(1, 2)])

# ============================================================
# 14. __slots__ -> fixed attributes, less memory (good for many nodes)
# ============================================================
class Node:
    __slots__ = ("val", "next")
    def __init__(self, val, next=None):
        self.val, self.next = val, next

# ============================================================
# 15. Introspection helpers
# ============================================================
print(type(v1).__name__, hasattr(v1, "x"), getattr(v1, "x"), vars(t1))
setattr(t1, "salary", 30000)

print("10_oops OK")
