#include "./include/matrix.hpp"
#include <cassert>

using namespace CustomMatrix;

int main( int, char** )
{
  std::cout<<"main()"<<std::endl;
  {
    Matrix<int, -1> matrix;
    assert( matrix.size() == 0 ); // все ячейки свободны
    auto a = matrix[ 0 ][ 0 ];
    assert( a == -1 );
    assert( matrix.size() == 0 );
    matrix[ 100 ][ 100 ] = 314;
    assert( matrix[ 100 ][ 100 ] == 314 );
    assert( matrix.size() == 1 );

#ifdef DEBUG
    std::cout << "for: "<< std::endl;
#endif
    for ( const auto& el : matrix )
    {
#ifdef DEBUG
    std::cout << "el: "<< std::endl;
#endif
      int x;
      int y;
      int v;
      std::tie( x, y, v ) = matrix[el];
      std::cout << x << y << v << std::endl;
    }
    //std::tuple<int, int, int> t = matrix;
  }

}
