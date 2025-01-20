/*
 * C programto analise the trigonometric functions with gnuplot
 * Compile: $ gcc -Walltrigonometricas.c -lm -o trigonometricas.x
 * Run: $ ./trigonometricas.x
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 200

//Assinatura
double log_base(double x, double base);

int main(){
  FILE *gnuplot = popen("gnuplot -persistent", "w") ;
  if(gnuplot == NULL){
    printf("Error on openning gnuplot pipe\n");
    exit(1);
  }

  FILE *file1 = fopen("dados1_trigonometricas.txt", "w");
  if(file1 == NULL){
    printf("Error on openning dados1_trinometricas.txt\n");
    exit(1);
  }

  for(int i=-TAM; i<=TAM; i++){
    double n = i;
    fprintf(file1, "%d\t", i); //1
    fprintf(file1, "%.2f\t", sin(n)); 
    fprintf(file1, "%.2f\t", cos(n)); //3
    fprintf(file1, "%.2f\t",tan(n));
    fprintf(file1, "%.2f\t", (fabs(n) <= 1.0 ? asin(n) : NAN));
    fprintf(file1, "%.2f\t", (fabs(n) < 1.0 ? acos(n) : NAN)); //6
    fprintf(file1, "%.2f\t", atan(n));
    fprintf(file1, "%.2f\t", sinh(n));
    fprintf(file1, "%.2f\t", cosh(n)); //9
    fprintf(file1, "%.2f\t",tanh(n));
    fprintf(file1, "%.2f\t", asinh(n)); 
    fprintf(file1, "%.2f\t", (fabs(n) <= 1.0 ? acosh(n) : NAN)); //12
    fprintf(file1, "%.2f\t", (fabs(n) <= 1.0 ? atanh(n) : NAN));
    fprintf(file1, "%.2f\t", exp(n));
    fprintf(file1, "%.2f\t", (n >= 0) ? sqrt(n) : NAN); //15
    fprintf(file1, "%.2f\t", (n > 0 ) ? log10(n) : NAN);
    fprintf(file1, "%.2f\t", (n > 0) ? log_base(n, 2.0) : NAN);
    fprintf(file1, "%.2f\t", (n > 0) ? log_base(n, 3.0) : NAN); //18
    //fprintf(file1, "%.2f\t", ln(n));
    fprintf(file1, "%.2f\t", pow(n, 2));
    fprintf(file1, "%.2f\t", pow(n, 3)); //21
    fprintf(file1, "%.2f\t", pow(n, (1.0/3.0)));
    fprintf(file1, "%.2f\t", pow(n, -1));
    fprintf(file1, "%.2f\t", pow(n, -2)); //24
    fprintf(file1, "%.2f\t", pow(n, -3));
    fprintf(file1, "%f\n", fabs(n));
  }
  fclose(file1);

  fprintf(gnuplot, "set xrange [-10:10]\n");
  fprintf(gnuplot, "set yrange [-10:10]\n");
  fprintf(gnuplot, "set xlabel 'x'\n");
  fprintf(gnuplot, "set ylabel 'f(x)'\n");
  fprintf(gnuplot, "set title 'Some functions and some values'\n");
  fprintf(gnuplot, "plot 'dados1_trigonometricas.txt' u 1:2 w l notitle, \\\n"); //t 'sin(x)'
  fprintf(gnuplot,  "'' u 1:3 w l notitle'notitle, \\\n"); //t 'cos(x)'
  fprintf(gnuplot,  "'' u 1:4 w l notitle', \\\n"); //t 'tan(x)'
  fprintf(gnuplot,  "'' u 1:5 w l notitle', \\\n"); //t 'asin(x)'
  fprintf(gnuplot,  "'' u 1:6 w l notitle', \\\n"); //t 'acos(x)'
  fprintf(gnuplot,  "'' u 1:7 w l notitle', \\\n"); //t 'atan(x)'
  fprintf(gnuplot,  "'' u 1:8 w l notitle', \\\n"); //t 'sinh(x)'
  fprintf(gnuplot,  "'' u 1:9 w l notitle', \\\n"); //t 'cosh(x)'
  fprintf(gnuplot,  "'' u 1:10 w l notitle', \\\n"); //t 'tanh(x)'
  fprintf(gnuplot,  "'' u 1:11 w l notitle', \\\n"); //t 'asinh(x)'
  fprintf(gnuplot,  "'' u 1:12 w l notitle', \\\n"); //t 'acosh(x)'
  fprintf(gnuplot,  "'' u 1:13 w l notitle', \\\n"); //t 'atanh(x)'
  fprintf(gnuplot,  "'' u 1:14 w l notitle', \\\n"); //t 'exp(x)'
  fprintf(gnuplot,  "'' u 1:15 w l notitle', \\\n"); //t 'sqrt(x)'
  fprintf(gnuplot,  "'' u 1:16 w l notitle', \\\n"); //t 'log10(x)'
  fprintf(gnuplot,  "'' u 1:17 w l notitle', \\\n"); //t 'log2(x)'
  fprintf(gnuplot,  "'' u 1:18 w l notitle', \\\n"); //t 'log3(x)'
  fprintf(gnuplot,  "'' u 1:19 w l notitle', \\\n"); //t 'ln(x)'
  fprintf(gnuplot,  "'' u 1:20 w l notitle', \\\n"); //t 'x^2'
  fprintf(gnuplot,  "'' u 1:21 w l notitle', \\\n"); //t 'x^3'
  fprintf(gnuplot,  "'' u 1:22 w l notitle', \\\n"); //t 'x^1/3'
  fprintf(gnuplot,  "'' u 1:23 w l notitle', \\\n"); //t 'x^-1'
  fprintf(gnuplot,  "'' u 1:24 w l notitle',\\\n"); //t 'x^-2'
  fprintf(gnuplot,  "'' u 1:25 w l notitle', \\\n"); //t 'x^-3'
  fprintf(gnuplot,  "'' u 1:26 w l notitle'\n"); //t 'abs(x)'

  pclose(gnuplot);
  return 0;
}

double log_base(double x, double base){
  return log(x) / log(base);
}
