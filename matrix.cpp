#pragma once

#include <iostream>
#include <array>
#include <map>


using std::cout;
using std::endl;

namespace CustomMatrix
{
  // Реализация класса матрицы
  template<typename T, T defaultValue >
  class Matrix final
  {
  private:
    // Реализация класса хранения и обработки элементов матрицы 
    class StorageOfMatrix
    {
    private:
      std::map<std::pair<size_t, size_t>, T>&   m_matrixRef;
      size_t                                    row;
      size_t                                    col;

    public:
      StorageOfMatrix( std::map<std::pair<size_t, size_t>, T>& val )
        : m_matrixRef( val )
        , row( 0 )
        , col( 0 )
      {

      }

      StorageOfMatrix( const StorageOfMatrix& ) = default;
      StorageOfMatrix& operator = ( const StorageOfMatrix& ) = delete;
      StorageOfMatrix( StorageOfMatrix&& ) = delete;
      StorageOfMatrix& operator = ( StorageOfMatrix&& ) = delete;

      void SetIndex( const size_t& index )
      {
        row = index;
      }

      operator T()
      {
        std::cout << "operator () OF StorageOfMatrix" << std::endl;
        std::pair<size_t, size_t> temp( row, col );
        if ( m_matrixRef.find( temp ) == m_matrixRef.end() )
        {
          return defaultValue;
        }
        else
        {
          return m_matrixRef.at( temp );
        }
      }
      StorageOfMatrix& operator[]( const size_t& index )
      {
        std::cout << "operator[] OF StorageOfMatrix" << std::endl;
        col = index;

        return *this;  
      }

      void operator = ( const T& value )
      {
        std::cout << "operator = OF StorageOfMatrix" << std::endl;

        m_matrixRef.emplace( std::make_pair( row, col ), value );
      }
    };
 
  public:
    Matrix()
    {
     
    }
    Matrix( const Matrix& ) = delete;
    Matrix& operator = ( const Matrix& ) = delete;
    Matrix( Matrix&& ) = delete;
    Matrix& operator = ( Matrix&& ) = delete;

    StorageOfMatrix& operator[]( size_t index )
    {
      std::cout << "operator [] OF Matrix" << std::endl;
      m_storageControl.SetIndex( index );

      return m_storageControl;
    }

    // Возвращает размер матрицы
    size_t size() noexcept
    {
      return m_matrixMap.size();
    }
    
    private:
      std::map<std::pair<size_t, size_t>, T> m_matrixMap;
      StorageOfMatrix                        m_storageControl{ m_matrixMap };

  };
  //#include "matrix.hpp"
}
