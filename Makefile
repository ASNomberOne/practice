# ОБЪЯВЛЕНИЕ КОНСТАНТ КОМПИЛЯЦИИ
CC = g++ 
CCFLAGS = -std=c++11 -Wall  -pedantic
ALL_OBJECT = kmeans.o managercluster.o \
			 fileiostream.o featurepoint.o \
			 euclidianmetric.o descriptor.o
RM = rm -rf

#ДЕБАГ ВЕРСИЯ
ifeq ($(mode), release)
	CCFLAGS += -g0 -DNDEBUG
endif

ifeq ($(mode), debug)
	CCFLAGS += -g3
endif

# СБОРКА ПРОЕКТА
prog_cluster: main.o $(ALL_OBJECT)
	$(CC) $(CCFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

# ОЧИСТКА ПРОЕКТА
clear:
	$(RM) *.o prog_cluster
