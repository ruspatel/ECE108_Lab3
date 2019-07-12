#include <iostream>
#include "trust.h"

int main(){
    int size;
    std::cin >> size;
    bool** adj_array = get_adjacency_matrix(size);

    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < size; j++){
    //         std::cout << adj_array[i][j] << " ";
    //     }
    //     std::cout<< std::endl;
    // }
    bool** ref_array = get_reflexive_matrix(size, adj_array);
    std::cout <<std::endl;

    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < size; j++){
    //         std::cout << ref_array[i][j] << " ";
    //     }
    //     std::cout<< std::endl;
    // }

    print_equivalency(size,ref_array);
    return 0;
}




bool** get_adjacency_matrix(int size_input){
    
    int size = size_input;
    std::string cur_char;
    bool** array = new bool*[size];

    for(int i = 0; i < size; i++){
        
        array[i] = new bool[size];

        for(int j = 0; j < 0 ;j++){
            array[i][j] = 0;
        }
    }

    int row_count = 0;
    while(std::cin >> cur_char){
        int cur_char_num = std::stoi(cur_char);
        if(cur_char_num == 0){
            row_count++;
        }
        else if (cur_char_num != row_count + 1){
            array[row_count][cur_char_num - 1] = true;
        }
    }

    return array;


}

bool** get_reflexive_matrix(int size_input, bool** array){
    int size = size_input;
    bool** return_array = array;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j){
                return_array[i][j] = true;
            }
        }
    }  

    return return_array;
}

void print_equivalency(int size_input, bool** array){
    int size = size_input;
    bool** reflex_array = array;

    int num_array[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j<size; j++){
            if(reflex_array[i][j] == true){
                num_array[i][j] = 1;
            }else{
                 num_array[i][j] = 0;
            }
        }
        
    }

    for(int t = 0; t < size; t++){
        bool equal = true;
        bool t_good = true;

        while(num_array[t][0] == -1){
            if(t != size - 1){
                t++;
            }else{
                t_good = false;
                break;
            }
        }
        if(t_good == false){
            break;
        }
        std::cout << "{" << t + 1;
        for(int y = t + 1; y < size; y++){
            bool y_good = true;
            while(num_array[y][0] == -1){
                if(y != size - 1){
                    y++;
                }else{
                    y_good = false;
                    break;
                }
            }
            if(y_good == false){
                break;
            }
            for(int u = 0; u < size; u++){
                equal = true;
                if(num_array[t][u] != num_array[y][u]){
                    equal = false;
                    break;
                }
            }
            if(equal != false){
                std::cout << "," << y + 1;
                num_array[y][0]  = -1;
            }
        }
        std::cout << "}" <<std::endl;
        num_array[t][0]  = -1;
    }
}



