# CC = g++
# CC_FLAGS = -Wall -ansi
# CPLUS_INCLUDE_PATH=/home/abid/NUCLISUN/Codes/armadillo-7.100.3/include -DARMA_DONT_USE_WRAPPER -lblas -llapack 
# export CPLUS_INCLUDE_PATH
# EXEC = NUCLISUN
# SOURCES = $(wildcard *.cpp)
# OBJECTS = $(SOURCES:.cpp=.o)

# $(EXEC): $(OBJECTS)
# 	$(CC) $(OBJECTS) -o $(EXEC)

# %.o: %.cpp
# 	$(CC) -c $(CC_FLAGS) $< -o $@

# clean:
# 	rm -r -f $(EXEC) $(OBJECTS)

path = `pwd`
LIBS=$(path)/armadillo-7.100.3/include

all: NUCLIUS

NUCLIUS: main.o kmer_feature.o eigenvalues.o dna_stability.o format_dataset.o data_normalization.o
	g++ main.o kmer_feature.o eigenvalues.o dna_stability.o format_dataset.o data_normalization.o -o NUCLIUS -I $(LIBS) -DARMA_DONT_USE_WRAPPER -lblas -llapack

main.o: main.cpp
	g++ -c main.cpp -I $(LIBS) -DARMA_DONT_USE_WRAPPER -lblas -llapack

kmer_features.o: kmer_feature.cpp
	g++ -c kmer_feature.cpp

eigenvalues.o: eigenvalues.cpp
	g++ -c eigenvalues.cpp -O2 -I $(LIBS) -DARMA_DONT_USE_WRAPPER -lblas -llapack

dna_stability.o:
	g++ -c dna_stability.cpp 

format_dataset.o:
	g++ -c format_dataset.cpp

data_normalization.o:
	g++ -c data_normalization.cpp


clean:
	rm -rf *.o *.txt eigens NUCLIUS
