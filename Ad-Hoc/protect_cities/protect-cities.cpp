#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main(){
    LL test_count;
    LL cities_count;
    LL xCity, yCity;
    LL minxCity, maxxCity, minyCity, maxyCity;
    LL maxX, maxY, max;

    cin >> test_count;

    while(test_count--){
        cin >> cities_count;

        // reset max and min values
        minxCity = minyCity = LONG_MAX;
        maxxCity = maxyCity = LONG_MIN;

        while(cities_count--){
            cin >> xCity >> yCity;

            if (xCity > maxxCity) maxxCity = xCity;
            if (xCity < minxCity) minxCity = xCity;
            if (yCity > maxyCity) maxyCity = yCity;
            if (yCity < minyCity) minyCity = yCity;
        }

        maxX = maxxCity - minxCity;
        maxY = maxyCity - minyCity;

        max = maxX > maxY ? maxX : maxY;
        max *= max;
        cout << max << endl;

    }
    
    return 0;
}