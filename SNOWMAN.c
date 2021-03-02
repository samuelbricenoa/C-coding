// Arup Guha
// 9/26/06
// Program shown in COP 3223

#include <stdio.h>
#define SNOW_DENSITY 0.1
#define pi 3.14
double Sphere_Volume(double radius);
double Mass(double den, double volume);



int main() {
double radius1, radius2, radius3;
double totalvolume, totalmass;
	printf("enter your 3 radii\n" );
	scanf("%lf %lf %lf", &radius1, &radius2, &radius3);
	totalvolume = Sphere_Volume(radius1) + Sphere_Volume(radius2) + Sphere_Volume(radius3);
	totalmass = Mass(SNOW_DENSITY, totalvolume);
	printf("The total mass of your snowman is %lf.\n", totalmass);
	return 0;

}
double Sphere_Volume(double radius){
	return (4/3)*pi*radius*radius*radius;
	
}
double Mass(double den, double volume) {return den*volume;}

