#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mpi.h>

#define LIMITE 5000000


int primo(int n){
  int raiz, fator;
  raiz = (int) sqrt((double) n);
  for(fator = 2; fator <= raiz; fator++){
    if(n % fator == 0){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char** argv){
  int my_rank, numprocs;
  int totalPrimosId, totalPrimos;
  int i, menor = 0, maior;
  double tempo;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  if(my_rank == 0)
  {
    tempo = MPI_Wtime();
  }
  menor = ((numprocs - my_rank) *menor + (my_rank) *(LIMITE + 1))/(numprocs);
  maior = ((numprocs - my_rank - 1)*menor + (my_rank + 1) * (LIMITE + 1))/(numprocs) - 1;

  for (i = menor + 1; i <= maior; i++)
  {
    if (primo(i))
    {
      totalPrimosId++;
    }
  }

  printf("O id %d pegou %d numeros primos com intervalo de %d ate %d\n", my_rank, totalPrimosId,menor,maior);

  MPI_Reduce(&totalPrimosId, &totalPrimos, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if (my_rank == 0)
  {
    tempo = MPI_Wtime() - tempo;
    printf("Numero total de primos é %d.\n", totalPrimos);
    printf("\ntempo de execução: %14f\n", tempo);
  }

  MPI_Finalize();
  return 0;
}
