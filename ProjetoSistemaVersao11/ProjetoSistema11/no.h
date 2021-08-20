#ifndef NO_H
#define NO_H

namespace wictor {
template <class type>
class no
{
private:
    no<type>* back;
    type value;
    no<type>* next;
public:
    no();
    no(type dado);
    no<type>* getBack()const{return back;}
    void setBack(no<type>* back){this->back = back;}
    type getValue()const{return value;}
    void setValue(type value){this->value = value;}
    no<type>* getNext()const{return next;}
    void setNext(no<type>* next){this->next = next;}
};

template <class type>
no<type>::no():
    back(0),
    value(0),
    next(0)
{}

template <class type>
no<type>::no(type value):
    back(0),
    next(0)
{
    this->value = value;
}
}
#endif // NO_H
