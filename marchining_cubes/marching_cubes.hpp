//
//  marching_cubes.hpp
//  marchining_cubes
//
//  Created by 須之内俊樹 on 2023/03/04.
//

#ifndef marching_cubes_hpp
#define marching_cubes_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
const long long INF=1LL<<60;
template <typename T>
struct ImplicitFunction{
    int nx,ny,nz;
    T dx,dy,dz;
    int num_cells;
    std::vector<std::vector<std::vector<T>>> values;
    ImplicitFunction(int num_cells,int nx,int ny,int nz, T dx,T dy,T dz,std::vector<T> &data);
    void print_values();
};

#endif /* marching_cubes_hpp */
