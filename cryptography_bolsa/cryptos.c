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

  fprintf(gnuplot, "set xlabel 'x' offset 20.5, 9.2\n");
  fprintf(gnuplot, "set ylabel 'y' offset 22.3, 8.7 rotate by 360\n");
  fprintf(gnuplot, "set xrange [-%d:%d]\n", aux1, aux1);
  fprintf(gnuplot, "set yrange [-%d:%d]\n", aux1, aux1);

  fprintf(gnuplot, "unset xtics\n");
  fprintf(gnuplot, "unset ytics\n");
  fprintf(gnuplot, "set title 'r_{1} = %d, r_{2} = %d' offset 0, 0.5\n", a, b);
  //fprintf(gnuplot, "set object 1 rectangle from 30, -42 to 50, -48 fillstyle solid border lc 'black'\n");

  fprintf(gnuplot, "set zeroaxis\n");
  fprintf(gnuplot, "set parametric\n");
  fprintf(gnuplot, "set trange [0:2*pi]\n"); //The angle delta is called 't'
  fprintf(gnuplot, "set size square\n");

  fprintf(gnuplot, "plot %d*cos(t), %d*sin(t) lw 2 notitle, \
                          %d*cos(t), %d*sin(t) lw 2 notitle\n", a, a, b, b);

  pclose(gnuplot);
}
