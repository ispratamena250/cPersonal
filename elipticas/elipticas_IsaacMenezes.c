/*
 * C program to implement the elliptic curve cryptography
 * Isaac Menezes Pereira, 190088885
 *
 * Compile: gcc -Wall elipticas_IsaacMenezes.c -o elipticas_IsaacMenezes.x 
 * Run: ./elipticas_IsaacMenezes.x a b p
 * */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[4]){
  if(argc != 4){
    printf("Error! Run $ ./elipticas_IsaacMenezes.x a b p\n");
    exit(1);
  }

  FILE *file1 = fopen("pontosElipticas.dat", "w");
  if(!file1){
    printf("Error on openning pontosElipticas.dat\n");
    exit(1);
  }
  FILE *gnuplot = popen("gnuplot -persistent", "w");
  if(!gnuplot){
    printf("Error on openning gnuplot pipe\n");
    exit(1);
  }

  int a = atoi(argv[1]), 
      b = atoi(argv[2]),
      p = atoi(argv[3]),
      n = 0;

  for(int x=0; x<p; x++){
    for(int y=0; y<p; y++){
      if(y*y % p == (x*x*x + a*x + b) % p){
        n++;
        if(n < 250){
          printf("G%d = (%d %d)\n", n, x, y);
        }else{
          break;
        }
        fprintf(file1, "%d\t%d\n", x, y);
      }
    }
  }

  fclose(file1);

  fprintf(gnuplot, "set terminal wxt size 1700,850\n");
  fprintf(gnuplot, "set multiplot layout 1,2 title 'Graphs: mod p and |R (reals field)'\n");
  fprintf(gnuplot, "set xlabel 'x'\n");
  fprintf(gnuplot, "set ylabel 'f(x) mod %d'\n", p);
  fprintf(gnuplot, "set title 'Elliptc curve graph: y^2 = x^3 + %dx + %d (mod %d)'\n", a, b, p);
  fprintf(gnuplot, "plot 'pontosElipticas.dat' u 1:2 w p lc rgb 'red' pt 7 notitle\n");

  fprintf(gnuplot, "set xlabel 'x'\n");
  fprintf(gnuplot, "set ylabel 'f(x)'\n");
  fprintf(gnuplot, "set title 'Elliptc curve graph over the |R field'\n");
  fprintf(gnuplot, "set zeroaxis\n");
  fprintf(gnuplot, "set samples 100000\n");
  fprintf(gnuplot, "f(x) = (x**3 + %d*x + %d >=0) ? sqrt(x**3 + %d*x + %d) : 1/0\n", a, b, a, b);
  fprintf(gnuplot, "fl(x) = (x**3 + %d*x + %d >=0) ? -sqrt(x**3 + %d*x + %d) : 1/0\n", a, b, a, b);
  fprintf(gnuplot, "plot f(x) w l lw 2 lc rgb 'red' t 'y^2 = x^3 + %dx + %d', fl(x) w l lw 2 lc rgb 'red' notitle\n", a, b);
  pclose(gnuplot);

  system("open pontosElipticas.dat");

  return 0;
}
