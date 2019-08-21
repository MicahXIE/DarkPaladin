#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
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

       shared_memory_object::remove("MySharedMemory");
       //create the shared memory 
       managed_shared_memory segment(create_only, "MySharedMemory", 65536);
       std::cout << segment.get_free_memory() << std::endl;

       //create the allocators for the struct elements to be accessed as vectors
       typedef allocator<csData, managed_shared_memory::segment_manager>csDataAlloc;
       typedef allocator<cShared, managed_shared_memory::segment_manager>cSharedAlloc;
       //typedef allocator<wire, managed_shared_memory::segment_manager>outwire_alloc;

       //create a boost vector with an associated allocator to it
       typedef vector<csData, csDataAlloc>csDataVec;
              typedef vector<cShared, cSharedAlloc>cSharedVec;
       //typedef vector<wire, outwire_alloc>outwire_vec;

       //Initialize shared memory STL-compatible allocator
       const csDataAlloc alloc_inst(segment.get_segment_manager());
       const cSharedAlloc alloc_inst1(segment.get_segment_manager());
       //const outwire_alloc alloc_inst2(segment.get_segment_manager());

       //construct the segment for pushing the data into it
       csDataVec *csDataPtr = segment.construct<csDataVec>("csDataVec")
                                                          (alloc_inst);
       cSharedVec *cSharedPtr = segment.construct<cSharedVec>("cSharedVec")
                                                             (alloc_inst1);
       //outwire_vec *outwire_data = segment.construct<outwire_vec>("outwiredata")(alloc_inst2);

       //push the data into the vectors

       time_t t = 1566387907;
       for (int i=0; i<60; i++) {
           csd.nTimeStamp=t;
           csd.nTtlPax=10;
           csd.nTtlRegPax=10;
           csd.nTtlNonregPax=10;
           csd.nFemale=1;
           csd.nMale=0;
           csd.nKid=12;
           csd.nTeenager=21;
           csd.nAdult=12;
           csd.nElder=21;
           csDataPtr->push_back(csd);
           t++;
       }

       csh.nStartIdx=10;
       cSharedPtr->push_back(csh);

   } catch (...) {
       shared_memory_object::remove("MySharedMemory");
       throw;
   }

   //shared_memory_object::remove("MySharedMemory");
   return 0;
}

// brew install boost
// g++ shm_writer.cpp -o shm_writer -std=c++11 -lrt -pthread  -I /usr/local/include

