#include <iostream>
#include <list>
using namespace std;
//this is for displaying the rating..................
void display(const list<int>&playerRating){
    for(list<int>::const_iterator it=playerRating.begin(); it !=playerRating.end(); it++ )
    cout<<"player rating: "<<*it<<endl;
}
//this function is sorting the rating order...............
void playersRatingOrder( int orderedRating, list<int>& rating ){
    for (list<int>::iterator it =rating.begin(); it !=rating.end();it++){
    if (*it>orderedRating)
    {
        rating.insert(it,orderedRating);
        return;
    }
    }
    rating.push_back(orderedRating);
}

int main()
{
    list<int> allplayer = {2, 3, 4, 8, 6, 10, 9, 8, 1, 7, 5};
    list<int> beginner;
    list<int> pros;
    for (list<int>::iterator it = allplayer.begin(); it != allplayer.end(); it++)
    {
        int rating = *it;
        if (rating >= 1 && rating <= 5)
            // beginner.push_back(rating);
            playersRatingOrder(rating,beginner);
        else if (rating > 5 && rating <= 10)
            // pros.push_back(rating);
            playersRatingOrder(rating,pros);
    }
    // cout<<"Beginners: "<<endl;
    // for (list<int>::iterator it = beginner.begin(); it != beginner.end(); it++)
    // cout <<"player rating: "<< *it << endl;
    
    // cout << "--------------------" << endl;
    // cout<<"Pros: "<<endl;
    // for (list<int>::iterator it = pros.begin(); it != pros.end(); it++)     
    // cout << "player rating: "<<*it << endl;

    cout<<"Beginners: "<<endl;
    display(beginner);
    cout<<"Pros: "<<endl;
    display(pros);

    return 0;
}