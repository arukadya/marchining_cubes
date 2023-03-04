//
//  ioVTK.cpp
//  marchining_cubes
//
//  Created by 須之内俊樹 on 2023/03/04.
//

#include "ioVTK.hpp"



int inputVTK(int &num_cells,std::vector<int> &nums,std::vector<double> &dists,std::vector<double> &v,std::string InputFlieName){
    std::ifstream Inputfile(InputFlieName);
    if (!Inputfile.is_open()) {
        std::cerr << "Could not open the file - '"
             << InputFlieName << "'" << std::endl;
        return EXIT_FAILURE;
    }
    std::string line;
    std::string word;
    std::getline(Inputfile,line);
    std::stringstream ss_nums{line};
    for(int i=0;i<3;++i){
        getline(ss_nums,word,' ');
        nums.push_back(std::stoi(word));
    }
    std::getline(Inputfile,line);
    std::stringstream ss_dists{line};
    for(int i=0;i<3;++i){
        getline(ss_dists,word,' ');
        dists.push_back(std::stod(word));
    }
    std::getline(Inputfile,line);
    std::stringstream ss_num{line};
    getline(ss_num,word);
    num_cells = std::stoi(word);
    while(getline(Inputfile,line)){
        std::stringstream ss{line};
        getline(ss,word);
        v.push_back(std::stod(word));
    }
    //for(auto &x:v)std::cout << x << std::endl;
    Inputfile.close();
    return EXIT_SUCCESS;
}