#include "edges.h"
#include <iostream>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  int start;
  int end;
  int i, j;
  int vertex1;
  int vertex2;

  start = 0;
  end = 1;
  for(int p = 0; p < 2; p++){
    if(end == 2){ start = 1;}
    else { end = end + 1; }

    for(i = 0; i < F.rows(); i++){
      vertex1 = F(i, start);
      vertex2 = F(i, end);
      for(j = i + 1; j < F.rows(); j++){ // = to i to avoid repeats
        if(vertex1 == F(j, 0) || vertex1 == F(j, 1) || vertex1 == F(j, 2)){
          if(vertex2 == F(j, 0) || vertex2 == F(j, 1) || vertex2 == F(j, 2)){
            E.resize(E.rows() + 1,2);
            E(E.rows() - 1, 0) = i;
            E(E.rows() - 1, 1) = j;
          }
        }
      }
    }
  }

  std::cout << "The matrix E is of size "
            << E.rows() << "x" << E.cols() << std::endl;
  return E;
}
