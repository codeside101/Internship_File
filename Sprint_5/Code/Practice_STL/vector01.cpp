#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> numbers;
    numbers.push_back(0);
    for (int i=1; i<=10; i++)
    {
        numbers.push_back(i);
    }
    //1. print vctor elements.............
    for (int n:numbers)
    cout<<n<<endl;
    //2. print vector element with itertors..........
    cout<<"iterator......................................"<<endl;
    for (auto it = numbers.begin(); it!=numbers.end(); it++) 
    {
       // cout<<it<<endl; //not valid in iterators
        cout<<*it<<endl;
        // cout<<&it<<endl;
        // cout<<&(*it)<<endl;
    }
    auto it =numbers.begin();
    cout<<"element index 5 is "<<*(it+5)<<endl;

//imp functionalities.....................................
cout<<"size "<<numbers.size()<<endl;
cout<<"max_size "<<numbers.max_size()<<endl;
cout<<"capacity "<<numbers.capacity()<<endl;

numbers.resize(5);
cout<<"size after resizing "<<numbers.size()<<endl;
if(numbers.empty())
cout<<"vector is empty "<<endl;
cout<<"element[0] is "<<numbers[0]<<endl;
cout<<"element at (0) is "<<numbers.at(0)<<endl;
cout<<"front "<<numbers.front()<<endl;
cout<<"back "<<numbers.back()<<endl;
//insert element at specific position in vector..........
 numbers.insert(numbers.begin()+2,88);
//erase element from a specific position.............
 numbers.erase(numbers.begin()+2);
//remove last element of vector.......
numbers.pop_back();
//clear all the elements of vector...................
numbers.clear();
cout<<"size after clear : "<<numbers.size()<<endl;
    return 0;
}