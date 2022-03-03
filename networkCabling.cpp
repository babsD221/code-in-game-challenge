#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int main()
{
    int N;
    vector<pair<int,int>>Points;
    cin >> N; cin.ignore();
    int max=0,min=numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        if(X > max)
            max=X;
        if(X <min)
            min=X;
        Points.push_back(make_pair(X,Y));
    }
    std::sort(Points.begin(),Points.end(),sortbysec);
    long long dist=0;
    int m;
    if(N%2 == 0){
        m=Points[N/2].second;
    }
    else{
        m=floor((Points[(N-1)/2].second + Points[N/2].second)/2.0);
    }
    for(int i=0;i<N;i++){
        //if(abs(Points[i].second-Points[(N-1)/2].second)>0)
        dist+=abs(Points[i].second -m);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    dist+=max-min; 
    cout << dist << endl;
}