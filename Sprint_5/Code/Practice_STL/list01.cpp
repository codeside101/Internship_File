#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_front(30);
    mylist.push_front(40);
    mylist.push_front(50);
    mylist.push_front(60);
    mylist.push_front(70);
    for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
    {
        cout<<*it<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
    mylist.erase(mylist.begin());
    mylist.erase(mylist.begin());
    mylist.erase(mylist.begin());
        for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}