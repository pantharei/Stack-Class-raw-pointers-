#include "Stack.h"
#include <iostream>

Stack::Stack(int in_size){
    max_size = in_size;
    ptr_array = new Record*[max_size]{};
}

//metodo che ritorna se lo stack è vuoto
bool Stack::isEmpty()const{
    return (top == -1);
}

//metodo che ritorna se lo stack è pieno
bool Stack::isFull()const{
    return (top == max_size-1);
}

//Inserisce un nuovo Record, 
//copiando il contenuto di p_record in una istanza interna a Stack. 
bool Stack::push(const Record& r){
    bool ret = false;
    if(!isFull()){
        ptr_array[++top] = new Record(r);
        ret = true;
    }
    return ret;
}

//Ritorna il puntatore ad una copia dell'ultimo Record, 
//eliminandolo dallo Stack.
Record* Stack::pop(){
    Record* ret = nullptr;
    if(!isEmpty()){
        ret = new Record(*ptr_array[top]); //copia dell'ultimo Record
        delete ptr_array[top]; //deallocazione dallo stack

        //assegnamento al puntatore deallocato il valore nullptr
        //(decrementando anche top)
        ptr_array[top--] = nullptr; 
    }
    return ret;
}

//metodo che stampa gli elementi dello stack
//nel seguente formato '(m_id, m_value)'
void Stack::print()const{
    if(!isEmpty()){
        std::cout << "[TOP] ";
        std::cout << "- [Size]=" << top+1 << std::endl; 
    for(int i = top; i >= 0; i--){
        ptr_array[i]->print();
    }
}
}

//distruttore con deallocazione dinamica
Stack::~Stack(){
    if(ptr_array){
        for(int i = 0; i < max_size; i++){
            delete ptr_array[i];
            ptr_array[i] = nullptr;
        }
        delete [] ptr_array;
        ptr_array = nullptr;
    }
}