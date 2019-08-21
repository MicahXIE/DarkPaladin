#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <algorithm>
#include <iostream>

typedef struct {
    time_t nTimeStamp;
    int nTtlPax;
    int nTtlRegPax;
    int nTtlNonregPax;
    int nFemale;
    int nMale;
    int nKid;
    int nTeenager;
    int nAdult;
    int nElder;
} csData;

typedef struct  {
    int nStartIdx;
    std::vector<csData> gStatData;
} cShared;

csData csd;
cShared csh;

int main()
{

    using namespace boost::interprocess;

    try {
        //A special shared memory where we can
        //construct objects associated with a name.
        //Connect to the already created shared memory segment
        //and initialize needed resources
        managed_shared_memory segment(open_only, "MySharedMemory");  //segment name

        typedef allocator<csData, managed_shared_memory::segment_manager>csDataAlloc;
        typedef allocator<cShared, managed_shared_memory::segment_manager>cSharedAlloc;

        typedef vector<csData, csDataAlloc>csDataVec;
        typedef vector<cShared, cSharedAlloc>cSharedVec;

        csDataVec *csDataPtr = segment.find<csDataVec>("csDataVec").first;
        cSharedVec *cSharedPtr = segment.find<cSharedVec>("cSharedVec").first;

        for (int i=0; i<60; i++) {
            std::cout << csDataPtr->at(i).nTimeStamp << "\n";
        }

        std::cout << cSharedPtr->at(0).nStartIdx << "\n";

        segment.destroy<csDataVec>("csDataVec");
        segment.destroy<cSharedVec>("cSharedVec");
    }
    catch (...) {
        shared_memory_object::remove("MySharedMemory");
        throw;
    }

    shared_memory_object::remove("MySharedMemory");
    return 0;
}

// brew install boost
// g++ shm_reader.cpp -o shm_reader -std=c++11 -pthread  -I /usr/local/include




