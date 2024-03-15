/*
Lo Stack ha una dimensione massima preallocata, 
passata come parametro al costruttore e contiene puntatori a Record's (utilizzare un array).
*/
#include <iostream>
struct Record {
        short int m_id;
        float m_value;
        public:
        Record(short int in_id, float in_v):m_id(in_id),m_value(in_v){}
        Record():Record(0,0){}
        void print()const{
            std::cout << '(';
            std::cout << m_id;
            std::cout << ',';
            std::cout << m_value;
            std::cout << ")\n";
        }
    };

class Stack{

    int max_size{0}; //dimensione massima Stack
    int top = -1;
    Record** ptr_array{nullptr}; //array di puntatori a Record
    bool isEmpty()const;
    bool isFull()const;

    public:
    
    Stack(int);
    bool push(const Record& p_record);
    Record* pop();
    void print()const;
    ~Stack();

};