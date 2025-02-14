#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *file1 = fopen("simetria.dat", "w");
  if(!file1){
    printf("Erro ao abrir simetria.dat em 'w'\n");
    exit(1);
  }

  int p = 50;

  for(int x=0; x<p; x++){
    for(int y=0; y<p; y++){
      if(y % p == (2*x*x + 3*x - 4) % p){
        fprintf(file1, "%d %d\n", x, y);
      }
    }
  }
  fclose(file1);

  FILE *gnuplot = popen("gnuplot -persistant", "w");
  if(!gnuplot){
    printf(" Erro ao abir pipe\n");
    exit(1);
  }

  fprintf(gnuplot, "set xlabel 'x'\n");
  fprintf(gnuplot, "set ylabel 'f(x)'\n");
  fprintf(gnuplot, "set title 'Existe simetria?'\n");
  fprintf(gnuplot, "plot 'simetria.dat' u 1:2 w p pt 7 lc rgb 'blue' notitle, %d/2 w l lc rgb 'green' notitle\n", p);

  pclose(gnuplot);

  printf("\n");
  return 0;
}
