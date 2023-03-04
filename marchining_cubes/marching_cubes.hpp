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
#include "Eigen/Core"

const long long INF=1LL<<60;
template <typename T>
struct ImplicitFunction{
    int nx,ny,nz;
    T dx,dy,dz;
    int num_cells;
    std::vector<std::vector<std::vector<T>>> values;
    ImplicitFunction(int num_cells,int nx,int ny,int nz, T dx,T dy,T dz,std::vector<T> &data){
        this->num_cells = num_cells;
        this->nx = nx;
        this->ny = ny;
        this->nz = nz;
        this->dx = dx;
        this->dy = dy;
        this->dz = dz;
        values.resize(nx);
        for(int i=0;i<nx;++i){
            values[i].resize(ny);
            for(int j=0;j<ny;++j){
                values[i][j].resize(nz);
                for(int k=0;k<nz;k++){
                    values[i][j][k] = data[i*nx*ny + j*nx + k];
                }
            }
        }
    }
    void print_values(){
        for(int i=0;i<nx;++i){
            for(int j=0;j<ny;++j){
                for(int k=0;k<nz;++k){
                    std::cout << values[i][j][k] << ",";
                }std::cout << std::endl;
            }std::cout << std::endl;
        }std::cout << std::endl;
    }
};

#endif /* marching_cubes_hpp */
