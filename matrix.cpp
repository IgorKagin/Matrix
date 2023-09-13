template<typename S>
constexpr long unsigned getRow()
{
  if constexpr ( std::is_integral_v<S> )
  {
    return 44721;
  }
  else
  {
    return 31622; (is_floating_point_v)
  }

};

template<typename T, int N>
struct Matrix
{
  //constexpr const static size_t X = (std::is_same_v<int, T>? 128: 4);
  constexpr static const long unsigned M = getRow<T>();
  T m_matrix[ M ][ M ] = { N };
};

//struct Aa
//{
//
//public:
//  enum { Rows = 3, Cols = 4 };
//  using TRow = int[ Cols ];
//  TRow & operator []( size_t i )
//  {
//    return matrix[ i ];
//  }
//
//private:
//
//  int matrix[ Rows ][ Cols ];
//};
