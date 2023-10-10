#include "matrix.h"
#include <cassert>

int main( int, char** )
{
    Matrix<int, -1> matrix;
    assert( matrix.size() == 0 ); // все ячейки свободны
    auto a = matrix[ 0 ][ 0 ];
    assert( a == -1 );
    assert( matrix.size() == 0 );
    matrix[ 100 ][ 100 ] = 314;
    assert( matrix[ 100 ][ 100 ] == 314 );
    assert( matrix.size() == 1 );

    for ( auto& c : matrix )
    {
      int x;
      int y;
      int v = 9;
      //std::tie( x, y, v ) = c;
      //std::cout << x << y << v << std::endl;
    }
}
