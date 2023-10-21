from abc import ABC


class Base(ABC):
    def say_hello(self):
        print("I am in base")


class MyClass(Base):
    first_name = ""

    def __init__(self, first_name):
        self.first_name = first_name

    def say_hello(self):
        print("Hello, " + self.first_name)


my_class_instance = MyClass(str(5))
my_class_instance.say_hello()
