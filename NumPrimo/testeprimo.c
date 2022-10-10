# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <mpi.h>
#define MAX 5000000

int main ( int argc, char *argv[] )
{
  int i;
  int id;
  int id_n_hi;
  int id_n_lo;
  int id_total;
  int j;
  int n_lo = 2;
  int p;
  int prime;
  double wtime;
  int total;

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &p);

  MPI_Comm_rank(MPI_COMM_WORLD, &id);
/*
  Work that only process 0 should do.
*/
  if(id == 0)
  {
    total = 0;
    wtime = MPI_Wtime ( );
  }
/*
  Each process computes a portion of the sum.
*/
  id_total = 0;

  id_n_lo = ((p - id) *n_lo + (id) * (MAX + 1))/(p);

  id_n_hi = ((p-id-1)*n_lo + (id + 1) * (MAX + 1))/(p) - 1;

  for ( i = id_n_lo; i <= id_n_hi; i++ )
  {
    prime = 1;

    for ( j = 2; j < i; j++ )
    {
      if ( i % j == 0 )
      {
        prime = 0;
        break;
      }
    }
    if (prime)
    {
      id_total = id_total + 1;
    }
  }
  printf ( "  Id do processo: %8d  Numero inicial do processo: %8d  Numero maximo do processo: %8d  Numeros primos encontrados: %12d\n", id, id_n_lo, id_n_hi, id_total );
/*
  Use REDUCE to gather up the partial totals and send to process 0.
*/
  MPI_Reduce(&id_total, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if ( id == 0 )
  {
    wtime = MPI_Wtime() - wtime;
    printf ("\n");
    printf (" Numero Inicial: %8d  Numero final: %8d  Numeros primos encontrados no intervalo: %12d  Tempo gasto para encontrar os numeros: %14f\n", n_lo, MAX, total, wtime);
  }
  MPI_Finalize();

  return 0;
}
