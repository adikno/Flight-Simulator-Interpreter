cmake_minimum_required(VERSION 3.12)
project(untitled9)

set(CMAKE_CXX_STANDARD 14 )
set(CMAKE_CXX_FLAGS -pthread )
add_executable(untitled9 main.cpp Command.h OpenServerCommand.cpp ConnectCommand.cpp ClientParams.cpp Expression.h BinaryExpression.h Number.h Plus.cpp Minus.cpp Div.cpp Mult.cpp CommandExpression.cpp CommandExpression.h Interpreter.cpp Interpreter.h ConditionParser.h LoopCommand.cpp IfCommand.cpp PrintCommand.cpp ShuntingYard.cpp ShuntingYard.h SleepCommand.cpp EqualsCommand.cpp EqualsCommand.h BooleanExpression.cpp Maps.h ConnectCommand.h ParamsCommand.cpp SereverParams.h OpenServerCommand.h)