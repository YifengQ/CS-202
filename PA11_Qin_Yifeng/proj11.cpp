#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"

using namespace std;

int main(){

    vectorProj <int> lol;
    // Vector creation
    std::vector<int> vecInt;

    // Vector population with input values
    std::ifstream fin("RandomData.txt");
    while(fin){
        int fin_in;
        fin >> fin_in;
        if (!fin)
            break;
        vecInt.push_back( fin_in );
    }

    // Vector indexing and output ( using operator[] or at() )
    for (size_t i=0; i<vecInt.size(); ++i){
        std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl;
    }
	cout << "\n" <<
          "////////////////////////////\n" <<
          "/////   Resort   /////\n" <<
          "////////////////////////////" << endl;

   
    lol.vector_resort(vecInt); 	//calls the sorting function


    // Vector indexing and output ( using iterator )
    for (std::vector<int>::iterator it=vecInt.begin() + 1; it!=vecInt.end(); ++it){
        std::cout << *it << std::endl;
    }
		cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Research   /////\n" <<
          "////////////////////////////" << endl;

	cout << "@ " << lol.vector_research(vecInt, 25) << endl; //goes to find position 23 starting from 0.

    cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Copy   /////\n" <<
          "////////////////////////////" << endl;


    vector<int> newVec;
    lol.vector_copy(vecInt, newVec);

    for (size_t i=1; i<newVec.size(); ++i){
        std::cout << newVec[i] <<  std::endl;
    }

    return 0;
}

