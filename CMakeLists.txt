CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)


SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
        tests/unit_test.cpp	
	composite/src/sub.cpp
        composite/src/rand.cpp
        composite/src/op.cpp
        composite/src/add.cpp
        composite/src/mult.cpp
	composite/src/div.cpp
	composite/src/pow.cpp
	binary_iterator.cpp
	preorder_iterator.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
