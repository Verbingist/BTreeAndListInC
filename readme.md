g++ main.cpp -o app \
    -lsfml-graphics -lsfml-window -lsfml-system

g++ -std=c++17 main.cpp LinkedList.cpp ListNode.cpp ListData.cpp -o program

g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o cppgraph

g++ $(find . -name "*.cpp")     -lsfml-graphics -lsfml-window -lsfml-system     -o cppgraph