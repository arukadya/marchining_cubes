//
//  main.cpp
//  marchining_cubes
//
//  Created by 須之内俊樹 on 2023/03/04.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include "marching_cubes.hpp"
#include "ioVTK.hpp"
int main(int argc, const char * argv[]) {
    std::vector<int>nums;
    std::vector<double>dists;
    std::vector<double> v;
    int num_cells;
    std::string InputFlieName = "resorces/SDF_armadillo.vtk";
    inputVTK(num_cells,nums,dists,v,InputFlieName);
    ImplicitFunction<double> imp = ImplicitFunction<double>(num_cells,nums[0],nums[1],nums[2],dists[0],dists[1],dists[2],v);
    imp.print_values();
    return 0;
}
