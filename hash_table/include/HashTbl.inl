/*!
 *  @file hash_table.inl
 *  @brief Hash Table Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with Hash Table implementations
 */

#include <iostream>
#include <cmath>
#include "HashTbl.hpp"

bool is_prime(int _n) {
    if (_n == 1) return false;
    for (int i = 2; i <= std::sqrt(_n); i++)
        if (_n % i == 0)
            return false;
    return true;
}

int find_next_prime(int _n) {
    while (!is_prime(++_n));
    return _n;
}

//! MyHashTable namespace encapsulates all class related to a simple hash function definition.
namespace MyHashTable {
    //----------------------------------------------------------------------------------------
    //! Default construtor.
    /*! Creates a hash table of the required capacity, which uses an external hash function
     *  that maps keys to unsigned long integers.
     *  If no external hash function is provided, an \r UndefinedHashFunctionException is generated.
     *  \param _initSize Required hash table capacity.
     *  \param _pfHF Pointer to an external hash function that does the first hashing and returns an unsigned long int.
     *  \throw UndefinedHashFunctionException if no external hash function is provided.
    */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    HashTbl<KeyType, DataType, KeyHash, KeyEqual>::HashTbl(int _initSize)
        : mSize(_initSize), mCount(0u) {
            mSize = find_next_prime(_initSize);
            std::unique_ptr<std::forward_list<Entry>[]> aux(new std::forward_list<Entry>[mSize]);
            mpDataTable = std::move(aux);
    }

    //----------------------------------------------------------------------------------------
    //! Destrutor that just frees the table memory, clearing all collision lists.
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    HashTbl<KeyType, DataType, KeyHash, KeyEqual>::~HashTbl() {
        clear();
    }

    //----------------------------------------------------------------------------------------
    //! Inserts data into the hash table.
    /*! For an insertion to occur, the client code should provide a key and the data itself
     *  If the data is already stored in the table, the function updates the data with the
     *  new information provided.
     *  \param _newKey Key associated with the data, used to get to the stored information.
     *  \param _newDataItem Data to be stored or updated, in case the information is already stored in the hash table.
     *  \return true if the data is already stored in the table and it is updated; false, otherwise.
     *  \throw std::bad_alloc In case no memory is available for dynamic allocation required in the insertion procedure.
    */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::insert(const KeyType &_newKey, const DataType &_newDataItem) throw (std::bad_alloc) {
        // Flag used to indicate whether the data has been found or not.
        auto bDataFound(false);
        return bDataFound;
    }


    //----------------------------------------------------------------------------------------
    //! Removes data from the hash table.
    /*! Removse a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \return true if the data item is found; false, otherwise.
    */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::remove(const KeyType &_searchKey) {
        // TODO
        auto bRemoved(false);
        return bRemoved;
    }

    //----------------------------------------------------------------------------------------
    //! Retrieves data from the table.
    /*! Retrieves a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \param _dataItem Data record to be filled in when data item is found.
     *  \return true if the data item is found; false, otherwise.
    */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::retrieve(const KeyType &_searchKey, DataType &_dataItem) const {
        // TODO
        auto bFound(false);
        return bFound;
    }

    //! Clears the data table.
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear() {
        while (mCount > 0)
            (&mpDataTable[--mCount])->~forward_list();
    }

    //! Tests whether the table is empty.
    /*!
     * \return true is table is empty, false otherwise.
     */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::isEmpty() const {
        return (mCount == 0);
    }

    //! Counts the number of elements currently stored in the table.
    /*!
     * \return The current number of elements in the table.
     */
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::count() const {
        return mCount;
    }

    //! Prints out the hash table content.
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::showStructure() const {
        KeyHash hashFn;

        // Traverse the list associated with the based address (idx), calculated before.
        for (auto i(0u); i < mSize; ++i) {
            std::cout << i << ": {key = ";
            for (auto &e : mpDataTable[i]) {
                std::cout << hashFn(e.mKey) << "; " << e.mData << " ";
            }
            std::cout << "}\n";
        }
    }

}  // namespace MyHashTable
