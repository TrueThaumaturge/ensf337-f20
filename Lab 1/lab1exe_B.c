/*
*  lab1exe_B.c
*  ENSF 337 - Fall 2020 Lab 1, exercise B
*  Completed by: Quentin Jennings
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* G is a constant: gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654  /* PI is constant */

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;

    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);

    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }

    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }

  create_table(velocity);

    return 0;
}


void create_table(double v)
{
	printf("Angle \t\tt \t\t\td \n(deg) \t\t(sec) \t\t\t(m)\n"); //sets up table

	for(int a = 0; a <= 90; a += 5) //angle loop
	{
		printf("%d \t\t", a); //prints angle first

		printf("%lf \t\t", Projectile_travel_time(a, v)); //then prints time

		printf("%lf\n", Projectile_travel_distance(a, v)); //then prints distance and starts new line
	}
}

//time formula
double Projectile_travel_time(double a, double v)
{
	return 2 * v * sin(degree_to_radian(a)) / G;
}

//distance formula
double Projectile_travel_distance(double a, double v)
{
	return v * v * sin(2*degree_to_radian(a)) / G;
}

//conversion
double degree_to_radian(double d)
{
	return d * PI / 180;
}
