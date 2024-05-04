# build an executable named main from main.cpp
all: main.cpp headers/back_data.cpp
  g++ -o  main  main.cpp  headers/back_data.cpp headers/base.cpp

# run the program
run: all
  ./main

