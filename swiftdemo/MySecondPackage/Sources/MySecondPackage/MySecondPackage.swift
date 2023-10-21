// The Swift Programming Language
// https://docs.swift.org/swift-book

import MyFirstPackage

// In MySecondPackage.swift
public func callFunctionFromFirstPackage() -> String {
    print("in MySecondPackage, calling MyFirstPackage")
	myFunction() 
    return "Hello from MySecondPackage!"
}
