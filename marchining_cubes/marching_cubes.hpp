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
#include <unordered_map>
#include <queue>
#include "Hasher.h"
#include "Eigen/Core"

using VertexID = std::tuple<int,int,int>;
using edge = std::pair<int,int>;
using worldEdge = std::pair<VertexID,VertexID>;
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
                for(int k=0;k<nz;++k){
                    values[i][j][k] = data[i + j*nx + k*nx*ny];
                }
            }
        }
        std::cout << "through" << std::endl;
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
    T getValue(VertexID id){
        auto [x,y,z] = id;
        return values[x][y][z];
    }
};
struct mesh{
    std::vector<Eigen::Vector3d> Vertices;
    std::vector<VertexID> Faces;
};
void addTriangle(VertexID glidID, Eigen::Vector3d origin, Eigen::Vector3d dist, double threshold, ImplicitFunction<double> &imp,  std::vector<Eigen::Vector3d> &Vertices, std::vector<std::vector<int>> &Faces,std::set<worldEdge> &used_edge);

void addVertex(VertexID x0ID,VertexID x1ID, Eigen::Vector3d origin, Eigen::Vector3d dist, double threshold, ImplicitFunction<double> &imp,  std::vector<Eigen::Vector3d> &Vertices, std::set<worldEdge> &used_edge);

void edge2addVertex(int edgeID, VertexID glidID, Eigen::Vector3d origin, Eigen::Vector3d dist, double threshold, ImplicitFunction<double> &imp,  std::vector<Eigen::Vector3d> &Vertices, std::set<worldEdge> &used_edge);

int getVertexTable(VertexID v_id,ImplicitFunction<double> &implicitfunction,double threshold);

Eigen::Vector3d linearInterporation(double isoValue,Eigen::Vector3d x0,Eigen::Vector3d x1,double value0,double value1);

Eigen::Vector3d getWorldPosition(VertexID glidID, Eigen::Vector3d origin, Eigen::Vector3d dist);

int transIndexL2W(VertexID glidID, int localID, int nx, int ny, int nz);

std::pair<int,int> edge2Vertex(int edgeID);

void marching_cubes(std::vector<Eigen::Vector3d> &Vertices,std::vector<std::vector<int>> &Faces,Eigen::Vector3d origin,Eigen::Vector3d &dist,ImplicitFunction<double> &imp,double threshold);

void cubetest(VertexID id,ImplicitFunction<double> &implicitfunction);

#endif /* marching_cubes_hpp */
