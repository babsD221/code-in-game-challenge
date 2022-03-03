#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int x1=0;
    int y1=0;
    int x2=W-1;
    int y2=H-1;
    int x=X0;
    int y=Y0;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        int n=std::string::npos;
        if(bombDir.rfind("U")!=n){
            y2=y-1;
        }
        else if(bombDir.rfind("D")!=n){
            y1=y+1;
        }
        if(bombDir.rfind("L")!=n){
            x2=x-1;
        }
        else if(bombDir.rfind("R")!=n){
            x1=x+1;
        }
            
          x= x1 +(x2-x1)/2;
         y=y1 +(y2-y1)/2;

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // the location of the next window Batman should jump to.
        cout<<x<<" "<<y << endl;
    }
}