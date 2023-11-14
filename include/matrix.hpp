#pragma once

#include <iostream>
#include <array>
#include <map>


using std::cout;
using std::endl;
using std::map;

namespace CustomMatrix
{  
  // Объявление класса матрицы
  template<typename T, T defaultValue >
  class Matrix final
  {
  private:
    // Объявление класса итератора матрицы
    class Iterator
    {
    private:
      typename std::map<std::pair<size_t, size_t>, T>::iterator m_matrixIter; //

    public:
      Iterator( typename std::map<std::pair<size_t, size_t>, T>::iterator val):m_matrixIter(val){};

      //!
      bool operator!=( Iterator&other)
      {
        #ifdef DEBUG
        std::cout << "operator !=() Of Iterator" << std::endl;
        #endif

        return m_matrixIter != other.m_matrixIter;
      }
      //!
      Iterator operator ++()
      {
        #ifdef DEBUG
        std::cout << "operator ++() Of Iterator" << std::endl;
        #endif

        ++m_matrixIter;
        return *this;
      }
      //!
      auto operator*()
      {
        #ifdef DEBUG
        std::cout << "operator*() Of Iterator" << std::endl;
        #endif

        return *m_matrixIter;
      }
    };
    // Объявление класса хранилища матрицы
    class StorageOfMatrix
    { 
    private:
      std::map<std::pair<size_t, size_t>, T>&   m_matrixRef;  //
      size_t                                    row;          //
      size_t                                    col;          //

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

      //!
      void SetIndex( const size_t& index )
      {
        row = index;
      }
      //!
      operator T()
      {
        #ifdef DEBUG
        std::cout << "operator () Of StorageOfMatrix" << std::endl;
        #endif

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
      //!
      StorageOfMatrix& operator[]( const size_t& index )
      {
        #ifdef DEBUG
        std::cout << "operator[] Of StorageOfMatrix" << std::endl;
        #endif

        col = index;

        return *this;  
      }
      //!
      void operator = ( const T& value )
      {
        #ifdef DEBUG
        std::cout << "operator = Of StorageOfMatrix" << std::endl;
        #endif

        m_matrixRef.emplace( std::make_pair( row, col ), value );
      }
    };
 
  public:
    Matrix(){}
    Matrix( const Matrix& ) = delete;
    Matrix& operator = ( const Matrix& ) = delete;
    Matrix( Matrix&& ) = delete;
    Matrix& operator = ( Matrix&& ) = delete;

    //!
    StorageOfMatrix& operator[]( size_t index ) noexcept;
    //!
    size_t size() noexcept;
    //!
    Iterator begin() noexcept;
    //!
    Iterator end() noexcept;
    //!
    operator std::tuple<int, int, int>()
    {
    #ifdef DEBUG
        std::cout << "operator std::tuple<int, int, int>() Of Matrix" << std::endl;
    #endif
        auto res = std::make_tuple(1, 1, 314 );

        return res;
    }
    private:
      std::map<std::pair<size_t, size_t>, T> m_matrixMap;                      // переменная матрицы
      StorageOfMatrix                        m_storageControl{ m_matrixMap };  // управление содержимым матрицы

  };
#include "matrix.ipp"
}