#include <iostream>
#include "adopter.h"
#include <vector>

using namespace std;


void printPreference(vector<string> v){
    for(int i = 0; i < (int) v.size(); i++){
        cout << i << ": " << v.at(i) << endl;
    }
    cout << endl;
}

void printPreferences(Preferences p){
    cout << "Age: " << endl;
    printPreference(p.getAge());

    cout << "Breed: " << endl;
    printPreference(p.getBreed());

    cout << "Size: " << endl;
    printPreference(p.getSize());

    cout << "Shelter: " << endl;
    printPreference(p.getShelter());

    cout << "Temp: " << endl;
    printPreference(p.getTemperament());

    cout << "Species: " << endl;
    printPreference(p.getSpecies());

    cout << "Goodwith: " << endl;
    printPreference(p.getGoodWith());


}

int main(){
    Adopter adopter = Adopter();
    adopter.setUsername("user1");
    adopter.fillPreferences();
    //adopter.removePreference("qwerty", "shelter");
    printPreferences(adopter.getPreferences());

    return 0;
}
