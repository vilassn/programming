from abc import ABC, abstractmethod


class MyInterface(ABC):
    @abstractmethod
    def method1(self):
        pass

    @abstractmethod
    def method2(self, input_str):
        pass

    @abstractmethod
    def method3(self, value):
        pass


class MyClass(MyInterface):
    def method1(self):
        print("Method 1 implementation")

    def method2(self, input_str):
        print(f"Method 2 implementation with input: {input_str}")
        return len(input_str)

    def method3(self, value):
        return value > 0


# Create an instance of MyClass
my_instance = MyClass()
my_instance.method1()
