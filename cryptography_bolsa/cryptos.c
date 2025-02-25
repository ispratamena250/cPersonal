#include <stdio.h>
#include <stdlib.h>

//Assingments for all the functions
void plotting();

int main(){
  int a, b;

  printf("The equation is: {a*cos(t), a*sin(t)}\nSet a: ");
  scanf("%d", &a);
  printf("\nThe equation is: {b*cos(t), b*sin(t)}\nSet b: ");
  scanf("%d", &b);

  plotting(a, b); 

  printf("\n");
  return 0;
}

void plotting(int a, int b){
  FILE *gnuplot = popen("gnuplot -persist", "w");
  if(!gnuplot){
    printf("Error on gnuplot pipe in 'w' mode\n");
    exit(1);
  }

  int aux1;
  if(a > b){
    aux1 = a+2;
  }else{
    aux1 = b+2;
  }

  fprintf(gnuplot, "set xlabel 'x' offset 2,0\n");
  fprintf(gnuplot, "set ylabel 'y' offset 0,1.5\n");
  fprintf(gnuplot, "set xrange [-%d:%d]\n", aux1, aux1);
  fprintf(gnuplot, "set yrange [-%d:%d]\n", aux1, aux1);

  fprintf(gnuplot, "unset xtics\n");
  fprintf(gnuplot, "unset ytics\n");

  fprintf(gnuplot, "set arrow from %d,0 to %d,-%d nohead lw 1 dt 2 lc rgb 'black'\n", a, a, aux1);
  fprintf(gnuplot, "set arrow from %d,0 to %d,-%d nohead lw 1 dt 2 lc rgb 'black'\n", b, b, aux1);
  fprintf(gnuplot, "set label 1 '%d' at %d,-(%d-0.5) offset 1,0\n", a, a, aux1);
  fprintf(gnuplot, "set label 2 '%d' at %d,-(%d-0.5) offset 1,0\n", b, b, aux1);

  fprintf(gnuplot, "set zeroaxis\n");
  fprintf(gnuplot, "set parametric\n");
  fprintf(gnuplot, "set trange [0:2*pi]\n"); //The angle delta is called 't'
  fprintf(gnuplot, "set size square\n");

  fprintf(gnuplot, "plot %d*cos(t), %d*sin(t) notitle, \
                          %d*cos(t), %d*sin(t) notitle\n", a, a, b, b);

  pclose(gnuplot);
}
