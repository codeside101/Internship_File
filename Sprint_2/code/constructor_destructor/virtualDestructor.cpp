#include<iostream>
using namespace std;

class Base{
    public:
    Base(){ cout<<"Base Constructor\n";}
    ~Base(){ cout<<"Base Destructor\n";}
};
class Derived: public Base{
    public:
    Derived(){
        m_array=new int[5];
        cout<<"Derived Constructor\n";
    }
    ~Derived(){
        delete[] m_array;
        cout<<"Derived Destructor\n";
    }
    private:
    int* m_array;
};
int main(){
    Base* base=new Base();
    delete base;
    cout<<"---------------------------------------"<<endl;
    Derived* derived=new Derived();
    delete derived;
    cout<<"---------------------------------------"<<endl;
    Base* poly=new Derived();
    delete poly;
 
}