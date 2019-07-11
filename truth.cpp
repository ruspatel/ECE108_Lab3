#include <iostream>


bool** get_adjacency_matrix();

int main(){
    std::string cur_char;
        while(std::cin >> cur_char){
        std::cout<<cur_char << " ";
    }
}




bool** get_adjacency_matrix(){
    
    int size = 0;
    //std::cin >> size;
    std::string cur_char;
    bool** array = new bool*[size];

    for(int i = 0; i < size; i++){
        
        array[i] = new bool[size];

        for(int j = 0; j < 0 ;j++){
            array[i][j] = 0;
        }
    }

    while(std::cin >> cur_char){
        std::cout<<cur_char << " ";
    }






}



