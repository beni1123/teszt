#include <stdio.h>

enum type{normal, fire, water, electric, grass, ice, fighting, poision, ground, flying, psychic, bug, rock, ghost, dragon, dark, steel, fairy};

typedef struct {
	char name[256];
	int age; //in years
	double strength; //0.0-10.0
	double speed; //0.0-10.0
	enum type typ;
}pokemon;

int faster(pokemon *array, int arraylength, double speed)
{
	int db=0;
	int i;
	for(i=0; i<arraylength; i++)
	{
		if(array[i].speed > speed)
		{
			db++;
		}
	}
	return db;
}

int type(pokemon *array, int arraylength, enum type typ)
{
	int db=0;
	int i;
	for(i=0; i<arraylength; i++)
	{
		if(array[i].typ == typ)
		{
			db++;
		}
	}
	return db;
}

enum type strongest_type(pokemon *array, int arraylength, double strength)
{
	enum type act;
	pokemon strongest=array[0];
	int i;
	for(i=0; i<arraylength; i++)
	{
		if(strongest.strength < array[i].strength)
		{
			strongest=array[i];
		}
	}
	return strongest.typ;
}

double maximal_strength(pokemon *array, int arraylength, enum type typ)
{
	int i, n = 0;
	pokemon act[100];
	double max=array[0].strength;
	for(i=0; i<arraylength; i++)
	{
		if(array[i].typ == typ)
		{
			act[n] = array[i];
			n++;
		}
	}
	for(i=0; i<n; i++)
	{
		if(max < act[i].strength)
		{
			max = act[i].strength;
		}
	}
	return max;
}

int main(void)
{
	pokemon squartle={"squartle", 34, 3.4, 5.6, water};
	pokemon dragon={"dragon", 23, 6.7, 2.3, fire};
	pokemon picatcu={"picatcu", 2, 8.9, 6.7, electric};
	pokemon dragi={"dragi", 3, 6.5, 9.9, electric};

	pokemon array[4];
	array[0]=squartle;
	array[1]=dragon;
	array[2]=dragi;
	array[3]=picatcu;
	printf("%d\n", faster(array, 4, 2.0));
	printf("%d\n", type(array, 4, electric));
	printf("%f\n", maximal_strength(array, 4, electric));
	printf("%d\n", strongest_type(array, 4, 5.6));

	return 0;
}


