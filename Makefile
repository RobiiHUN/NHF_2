# build an executable named main from main.cpp
all: main.cpp headers/back_data.cpp
    g++ main.cpp -o headers/back_data.cpp -o  main

# run the program


clean: 
  $(RM) main