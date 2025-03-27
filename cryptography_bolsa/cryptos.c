#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double x, y;
}Reduction;

//Assingments for rall the functions
void plotting(double ra, double tetaA, double rb, double tetaB, double rc);
void generating(double ra, double rb, double rc);
Reduction reduction(double x, double y, double r, double teta);

int main(){
	double ra, rb, rc, tetaA, tetaB;

	printf("The first equation is: {ra*cos(t), ra*sin(t)}\nSet ra: ");
	scanf("%lf", &ra);
	printf("Difine tetaA: ");
	scanf("%lf", &tetaA);
	printf("\nThe second equation is: {rb*cos(t), rb*sin(t)}\nSet rb: ");
	scanf("%lf", &rb);
	printf("Difine tetaB: ");
	scanf("%lf", &tetaB);
	printf("\nThen the third equation is: {(ra+rb)*cos(t), (ra+rb)*sin(t)}\nC: %.2lf\n", ra+rb);
	rc = ra + rb;

	plotting(ra, tetaA, rb, tetaB, rc);
	generating(ra, rb, rc);

	printf("\n");
	return 0;
}

void generating(double ra, double rb, double rc){
	FILE *file1 = fopen("drados_cryptos.dat", "w");
	if(!file1){
		printf("Error in file1 in generrating() in 'w' mode\n");
		exit(1);
	}
	
	for(double x=0; x<rc; x++){
		for(double y=0; y<rc; y++){
			if((ra*cos(x) + rb*cos(y)) % rc == (ra*sin(x) + rb*sin(y)) % rc){
				fprintf(file1, "%lf\t%lf\n", x, y);
			}
		}
	}
	
	system("open drados_cryptos.dat");
	
	fclose(file1);
}

void plotting(double ra, double tetaA, double rb, double tetaB, double rc){
	FILE *gnuplot = popen("gnuplot -persist", "w");
	if(!gnuplot){
		printf("Error on gnuplot pipe in 'w' mode in plotting()\n");
		exit(1);
	}

	Reduction r;
	double xa = ra*cos(tetaA);
	double ya = ra*sin(tetaA);
	r = reduction(xa, ya, ra, tetaA);
	xa = r.x;
	ya = r.y;

	double xb = rb*cos(tetaB); 
	double yb = rb*sin(tetaB);
	r = reduction(xb, yb, rb, tetaB);
	xb = r.x;
	yb = r.y;

	//fprintf(gnuplot, "set xlabel 'x'\n");
	//fprintf(gnuplot, "set ylabel 'y'\n");
	fprintf(gnuplot, "set xrange [-%lf:%lf]\n", rc+2, rc+2);
	fprintf(gnuplot, "set yrange [-%lf:%lf]\n", rc+2, rc+2);

	fprintf(gnuplot, "unset xtics\n");
	fprintf(gnuplot, "unset ytics\n");
	fprintf(gnuplot, "set title 'r_{1} = %.2lf, r_{2} = %.2lf, r_{3} = %.2lf' offset 0, 0.5\n", ra, rb, rc);
	//fprintf(gnuplot, "set object 1 rectangle from 30, -42 to 50, -48 fillstyle solid border lc 'black'\n");

	fprintf(gnuplot, "set zeroaxis\n");
	fprintf(gnuplot, "set parametric\n");
	fprintf(gnuplot, "set trange [0:2*pi]\n"); //The angle delta is called 't'
	fprintf(gnuplot, "set size square\n");

	fprintf(gnuplot, "set label 1 'A=(%.2lf, %.2lf)' at %lf, %lf offset 1, 0\n", xa, ya, xa, ya);
	fprintf(gnuplot, "set label 2 'B=(%.2lf, %.2lf)' at %lf, %lf offset 1, 0\n", xb, yb, xb, yb);
	fprintf(gnuplot, "$dados << EOD\n");
	fprintf(gnuplot, "%lf\t%lf\n", xa, ya);
	fprintf(gnuplot, "%lf\t%lf\n", xb, yb);
	fprintf(gnuplot, "EOD\n");

	fprintf(gnuplot, "plot $dados u 1:2 w p pt 7 ps 1 lc 'red' notitle, %lf*cos(t), %lf*sin(t) lw 2 title 'r_{1}', %lf*cos(t), %lf*sin(t) lw 2 title 'r_{2}', %lf*cos(t), %lf*sin(t) lw 2 title 'r_{3}'\n", ra, ra, rb, rb, rc, rc);

	pclose(gnuplot);
}

//Reducing to the first quradrant
Reduction reduction(double x, double y, double r, double teta){
	Reduction result;

	if(x < 0 && y >0){ //Second
		x = r*((cos(M_PI - teta))*(-1));
		result.x = x;
		y = r*sin(M_PI - teta);		
		result.y = y;
	}else if(x < 0 && y < 0){ //Third
		x = r*((cos(teta - M_PI))*(-1));
		result.x = x;
		y = r*((sin(teta - M_PI))*(-1));
		result.y = y;
	}else if(x > 0 && y < 0){//Fourth
		x = r*cos(2*M_PI - teta);
		result.x = x;
		y = r*((sin(2*M_PI - teta))*(-1));
		result.y = y;
	}else{
		x = r*cos(teta);
		result.x = x;
		y = r*sin(teta);
		result.y = y;
	}

	return result;
}
