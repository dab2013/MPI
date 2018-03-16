#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <cstdio>

//using namespace std;
//
//int main(int argc, char *argv[])
//{
//	int ID = 0;
//	int SendData = 0;
//	int RecieveData = 0;
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &ID);
//
//	if (ID == 0)
//	{
//		SendData = 100;
//		MPI_Send(&SendData, 1, MPI_INT, 1, 7, MPI_COMM_WORLD);
//	}
//
//	MPI_Status status;
//	if (ID == 1) {
//		MPI_Recv(&RecieveData, 1, MPI_INT, 0, 7, MPI_COMM_WORLD, &status);
//		std::cout << "Recieved Data is: " << RecieveData;
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

