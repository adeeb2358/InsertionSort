//
//  main.cpp
//  InsertionSort
//
//  Created by adeeb mohammed on 04/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// algorithm for insertion sort

#include <vector>
#include <iostream>

// more optimal soultion
void swap(int i, int j, std::vector<int> &array){
    int temp  = array.at(i);
    array.at(i) = array.at(j);
    array.at(j) = temp;
}

std::vector<int> insertionSort(std::vector<int> array){
    if(array.empty()){
        return array;
    }
    for(int i = 1; i < array.size(); i++){
        int j = i;
        while(j > 0 && array[j] < array[j-1]){
            swap(j,j-1,array);
            j--;
        };
    }
    return array;
}

// normal solution
std::vector<int> insertionSortOrg(std::vector<int> array) {
    int arraySize = (int)array.size();
    bool swapFlag = false;
    int tempElement = 0;
    int j         = 0;
    int currentPos = 0;
    for(int i = 1; i < arraySize; ++i){
        j = i - 1;
        currentPos = i;
        swapFlag = false;
        do{
            if(array.at(currentPos) < array.at(j)){
                tempElement = array.at(currentPos);
                array.at(currentPos) = array.at(j);
                array.at(j) = tempElement;
                swapFlag = true;
                currentPos = j;
                j--;
            }else{
                swapFlag = false;
            }
        }while(swapFlag == true && j >= 0 );
    }
    return array;
}
int main(int argc, const char * argv[]) {
    
    std::cout << "Function for doing insertion sort" << std::endl;
    auto array = {8,3,5,10,1,-2,-3};
    //auto result = insertionSortOrg(array);
    auto result = insertionSort(array);
    for(auto it : result){
        std::cout << it << " ";
    }
    return 0;
}
