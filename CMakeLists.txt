cmake_minimum_required(VERSION 3.21)
project(AdvancedProgramming1)

set(CMAKE_CXX_STANDARD 11)

add_executable(AdvancedProgramming main.cpp BridgePattern.h composite.h decorator.h facade.h FlyWeight.h Proxy.h FactoryPattern.h AbstractFactory.h Prototype.h Builder.h Singelton.h Command.h Iterator.h ObserverPattern.h)
