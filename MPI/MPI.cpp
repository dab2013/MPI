#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <cstdio>

//using namespace std;
//
//const int MAX_STRING = 100;
//
//void main(int argc, char *argv[])
//{
//	char greeting[MAX_STRING];
//	int comm_sz;
//	int my_rank;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
//	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
//
//	if (my_rank != 0) {
//		sprintf_s(greeting, "Greetings from process %d of %d!", my_rank, comm_sz);
//		MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
//	}
//	else {
//		printf("Greetings from process %d of %d!\n", my_rank, comm_sz);
//
//		for (int q = 1; q < comm_sz; q++) {
//			MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
//			printf("%s\n", greeting);
//		}
//
//	}
//
//
//
//	MPI_Finalize();
//}

