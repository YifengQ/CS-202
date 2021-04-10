//
// Created by Yifen on 12/10/2017.
//

#ifndef CS202_PROJECT11_VECTORRECURSION_H
#define CS202_PROJECT11_VECTORRECURSION_H

using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>


template <class T>
class vectorProj{

public:
    void vector_resort(std::vector<int>&);

    int vector_research(std::vector<int>&, const T&value);

    vector<int> & vector_copy(std::vector<int>&, std::vector<int>&);
};

template <class T>
void vectorProj<T>::vector_resort (std::vector<int>& newVector) {	//takes in a new vector

    //sort(newVector.begin(), newVector.end());

    int temp = 0;
    int size = newVector.size();

    for(int i = 0; i < size; i++){	//bubble sort
	
        for(int j = 1; j < size - 1; j++){

            if(newVector[j] > newVector[i]){	//checks the value to all the values

                temp = newVector[j];	//stores it in a temp
                newVector[j] = newVector[i];	//move the proverious ove by one
                newVector[i] = temp;	// buts back the larger one in front
				
            }

        }

    }
}

template <class T>
int vectorProj<T>::vector_research(std::vector<int>& otherVector, const T&value){

    int place = otherVector.size() / 2;	//gets the pivot reset
   	int i = place / 2;
	int count = 0;

    while(otherVector[place] != value){	//runs unitl it finds the same value

        if(otherVector[place] > value){	//if the stored value is greater 
   
			if(i == 0){	//makes sure it always goes down
				i = 1;
			}

		
            place = place - i;	// finds pivot in the bottom half
			count++;
        }

        else if(otherVector[place] < value){	//if the stored value is lower 
	
          	if(i == 0){	//makes sure it always goes up
				i = 1;
			}

            place = i + place;	// finds pivot in the upper half
			count++;
        }

		
		else if(count < 50){

			return -1;
		}

		i = i / 2;
    }
    return place;

}

template <class T>
vector<int> & vectorProj<T>::vector_copy(std::vector<int>& vec1, std::vector<int>& vec2){

    int size = vec1.size();	//gets size

    for(int i = 0; i < size ; i++){

        int value = vec1[i];	//stores the value in a temp	
        vec2.push_back(value);	// puts it into the new vector
    }


    return vec2;	//returns the new vector
}

#endif //CS202_PROJECT11_VECTORRECURSION_H

