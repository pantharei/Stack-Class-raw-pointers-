#include "Stack.h"
#include <iostream>

int main(){

    Stack s(7);
    s.print();

    srand(time(NULL)); //generazione numeri casuali [init]

    while( s.push( Record(rand()%100,rand()%100) ) ); //riempio la pila finché non è piena

    s.push(Record());
    s.push(Record(7,5));
    s.print();

    //test della pop

    Record* pop_element = s.pop();
    std::cout << "Elemento ";
    if(pop_element){
        std::cout << "estratto = ";
        pop_element->print();
    }else std::cout << "non estratto, Stack Vuoto!\n";

    //deallocazione puntatore pop_element
    //che contiene una copia dell'elemento estratto (heap)
    delete pop_element;
    pop_element = nullptr;

    s.print();

    return 0;
}