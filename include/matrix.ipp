#include "matrix.hpp"

using namespace CustomMatrix;

template<typename T, T defaultValue >
typename Matrix< T, defaultValue >::StorageOfMatrix& Matrix< T, defaultValue >::operator[]( size_t index ) noexcept
{
#ifdef DEBUG
    std::cout << "operator [] Of Matrix" << std::endl;
#endif
    m_storageControl.SetIndex( index );

    return m_storageControl;
}

template<typename T, T defaultValue >
size_t Matrix< T, defaultValue >::size() noexcept
{
#ifdef DEBUG
    std::cout << "size() Of Matrix" << std::endl;
#endif

    return m_matrixMap.size();
}

template<typename T, T defaultValue >
typename Matrix< T, defaultValue >::Iterator Matrix< T, defaultValue >::begin() noexcept
{
#ifdef DEBUG
    std::cout << "Iterator begin() Of Matrix" << std::endl;
#endif
    return Iterator( m_matrixMap.begin() );
}

template<typename T, T defaultValue >
typename Matrix< T, defaultValue >::Iterator Matrix< T, defaultValue >::end() noexcept
{
#ifdef DEBUG
    std::cout << "Iterator end() Of Matrix" << std::endl;
#endif
    return  Iterator( m_matrixMap.end() ); 
}

