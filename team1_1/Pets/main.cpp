#include <iostream>
#include "pet.h"

using namespace std;

int main(){
    /*
    Pet p = Pet();
    p.setID(1);
    p.setName("levi");
    p.fillMediaFiles("../../projectDB.sqlite");

    vector<string> imageFiles = p.getImageFiles();
    vector<string> videoFiles = p.getVideoFiles();
    cout << "Pet : " << p.getName() << endl;

    cout << "Pet Images: " << endl;
    for(int i = 0; i < (int) imageFiles.size(); i++){
        cout << "File: " << imageFiles.at(i) << endl;
    }

    cout << "Pet Videos: " << endl;
    for(int i = 0; i < (int) videoFiles.size(); i++){
        cout << "File: " << videoFiles.at(i) << endl;
    }

    */
    Pet p = Pet();
    p.getDistance(18042, 18055);

    return 0;
}
