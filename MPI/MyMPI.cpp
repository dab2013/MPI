#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <cstdio>

double Trap(double left_endpt, double right_endpt, int trap_count, double base_len);

using namespace std;

int main(int argc, char *argv[])
{
	int my_rank, comm_sz, n = 1024, local_n;
	double a = 0.0, b = 3.0, h, local_a, local_b;
	double local_int, total_int;
	int source;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	h = (b - a) / n;
	local_n = n / comm_sz;

	local_a = a + my_rank*local_n*h;
	local_b = local_a + local_n*h;
	local_int = Trap(local_a, local_b, local_n, h);

	if (my_rank != 0) {
		//std::cout << local_int << ", " << my_rank;
		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else {
		total_int = local_int;
		for (source = 1; source < comm_sz; source++) {
			MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			std::cout << local_int << ": " << source << ", ";
		}

		total_int += local_int;
	}

	if (my_rank == 0) {
		std::cout << "\nWith n = " << n << " trapezoids, our estimate \n";
		std::cout << "of the integral from " << a << " to " << b << " = " << total_int <<"\n";

	}
	MPI_Finalize();
	return 0;
}

double Trap(double left_endpt, double right_endpt, int trap_count, double base_len){
	double estimate, x;
	int i;

	estimate = ((left_endpt) + (right_endpt)) / 2.0;
	for (i = 0; i < trap_count - 1; i++) {
		x = left_endpt + i * base_len;
		estimate += x;
	}

	estimate = estimate * base_len;

	return estimate;
}

