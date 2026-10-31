CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Istates -Itask -Idata
SRCS := main.cpp $(wildcard states/*.cpp)

todo: $(SRCS) $(wildcard states/*.hpp task/*.hpp data/*.hpp)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@
