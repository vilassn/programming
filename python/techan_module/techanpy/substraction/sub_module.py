# sub_module.py
from techanpy.addition import add_module


def func_in_module1():
    print("in substract moudle" + __name__)
    print(add_module.func_in_module2())
    return "Function in module1"
