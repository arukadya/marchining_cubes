//
//  marching_cubes.cpp
//  marchining_cubes
//
//  Created by 須之内俊樹 on 2023/03/04.
//

#include "marching_cubes.hpp"
template <typename T>
ImplicitFunction<T>::ImplicitFunction(int num_cells,int nx,int ny,int nz, T dx,T dy,T dz,std::vector<T> &data){
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
template <typename T>
void ImplicitFunction<T>::print_values(){
    for(int i=0;i<nx;++i){
        for(int j=0;j<ny;++j){
            for(int k=0;k<nz;++k){
                std::cout << values[i][j][k] << ",";
            }std::cout << std::endl;
        }std::cout << std::endl;
    }std::cout << std::endl;
}
template <typename T>
void marchine_cubes(double threshold,ImplicitFunction<T> &implicitfunction){

}
