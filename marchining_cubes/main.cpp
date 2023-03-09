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
#include "OFF.h"

#include <bitset>
int main(int argc, const char * argv[]) {
    std::vector<int>nums;
    Eigen::Vector3d dists;
    std::vector<double> v;
    Eigen::Vector3d origin;
    int num_cells;
    std::string InputFlieName = "resources/SDF_armadillo.vtk";
    std::string OutputFlieName = "allmagilo.off";
    
    inputVTK(num_cells,nums,dists,origin,v,InputFlieName);
    ImplicitFunction<double> imp = ImplicitFunction<double>(num_cells,nums[0],nums[1],nums[2],dists[0],dists[1],dists[2],v);
    
    std::vector<Eigen::Vector3d> vertices;
    std::vector<std::vector<int>> faces;
    marching_cubes(vertices, faces, origin, dists, imp, 0.5);
    outputOFF(OutputFlieName.c_str(), vertices, faces);

    return 0;
}
