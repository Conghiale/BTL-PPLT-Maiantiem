//============================================================================
// Name        : maiantiem.c
// Author      : Nguyen Quoc Thuan
// Version     : 1.0
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/**********************************************************************
 * Ham: read_File
 * Sinh vien can hoan chinh ham doc_File de thuc hien viec doc gia tri file input.inp
**********************************************************************/
int doc_File(int *hp, int *d, int *s, char t[])
{
	//sinh vien viet code de thuc hien viec doc cac gia tri tu file output.out tai thu muc lam viec
	FILE *infile;
	infile = fopen("input.inp", "r");
	fscanf(infile, "%d%d%d%s", hp, d, s, t);
	fclose(infile);
	return 0;
}

/**********************************************************************
 * Ham: ghi_File
 * Sinh vien can hoan chinh ham ghi_file de thuc hien viec ghi ket qua p vao file output.out tai thu muc lam viec
**********************************************************************/
void ghi_File(double p)
{
	//sinh vien viet code de thuc hien viec ghi ket qua p vao file output.out tai thu muc lam viec
	FILE *outfile;
	outfile = fopen("output.out", "w");
	if(p <= 0 && p != -1)
	{
		p = 0;
	}else if(p >= 1)
	{
		p = 1;
	}
	fprintf(outfile, "%.3lf", p);
	fclose(outfile);
}

int kiemTraDuLieu(int *hp, int *d, int *s, char t[])
{
	if(*hp >= 1 && *hp <= 999 && *d >= 1 && *d <= 1000 && *s >= 1 && *s <= 100)
	{
		if(strcmp(t, "Flood") == 0 || strcmp(t, "Storm") == 0 || strcmp(t, "Rain") == 0 || strcmp(t, "Shower") == 0 || strcmp(t, "Drizzle") == 0 || strcmp(t, "Cloudy") == 0)
		{
			return 1;
		}
	}
	return 0;
}

int SNT(int n)
{
	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			count++;
		}
	}
	if(count == 2)
	{
		return 1;
	}else
	{
		return 0;
	}
}

int fb(int n)
{
	int a = 1; int b = 2;
	while(a <= n || b <= n)
	{
		if(a == n || b == n)
		{
			return 1;
		}
		
		a += b;
		b += a;
	}
	return 0;
}

int T(int n)
{
	int T = 0;
	for(int i = 1; i <= n; i++)
	{
		T += i;
	}
	return T;
}

void p12(int *hp, int *d, double *P1, double *P2, int *s)
{
	if(SNT(*hp) == 1)
	{
		*P1 = 1000;
		*P2 = (*hp + *s)%1000;
	}
	if(SNT(*hp) == 0)
	{
		*P1 = *hp;
		*P2 = (*hp + *d)%100;
	}
}

double gs(int *s)
{
	double gs;
	switch(*s % 6)
	{
		case 0:
			gs = *s / 2;
			break;
		case 1:
			gs = 2 * *s;
			break;
		case 2:
			gs = -(pow(*s % 9, 3) / 5);
			break;
		case 3:
			gs = -pow(*s % 30, 2) + (3 * *s);
			break;
		case 4:
			gs = -(*s);
			break;
		case 5:
			gs = -(T((*s % 5) + 5));
			break;
	}
	return gs;
}

double pt(int *s, char t[])
{
	double pt;
	switch(*s % 6)
	{
		case 5:
			if(strcmp(t, "Flood") == 0)
			{
				pt = 0;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = (double)5/100;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = (double)10/100;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = (double)15/100;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = (double)20/100;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = (double)25/100;
			}
			break;
		case 4:
			if(strcmp(t, "Flood") == 0)
			{
				pt = (double)-5/100;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = 0;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = (double)5/100;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = (double)10/100;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = (double)15/100;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = (double)20/100;
			}
			break;
		case 0:
			if(strcmp(t, "Flood") == 0)
			{
				pt = (double)-10/100;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = (double)-5/100;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = 0;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = (double)5/100;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = (double)10/100;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = (double)15/100;
			}
			break;
		case 1:
			if(strcmp(t, "Flood") == 0)
			{
				pt = (double)-15/100;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = (double)-10/100;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = (double)-5/100;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = 0;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = (double)5/100;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = (double)10/100;
			}
			break;
		case 2:
			if(strcmp(t, "Flood") == 0)
			{
				pt = (double)-20/100;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = (double)-15/100;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = (double)-10/100;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = (double)-5/100;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = 0;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = (double)5/100;
			}
			break;
		case 3:
			if(strcmp(t, "Flood") == 0)
			{
				pt = (double)-25/100;
			}
			if(strcmp(t, "Storm") == 0)
			{
				pt = (double)-20/100;
			}
			if(strcmp(t, "Rain") == 0)
			{
				pt = (double)-15/100;
			}
			if(strcmp(t, "Shower") == 0)
			{
				pt = (double)-10/100;
			}
			if(strcmp(t, "Drizzle") == 0)
			{
				pt = (double)-5/100;
			}
			if(strcmp(t, "Cloudy") == 0)
			{
				pt = 0;
			}
			break;
	}
	return pt;
}

void fdst(int *d, int *s, char t[], double *p, double *P1, double *P2, int *hp, double *f)
{
	if(*d < 200 && fb(*d + *s) == 0)
	{
		*f = 0;
		*p = (*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
	}
	
	if(*d >= 200 && *d <= 800 || fb(*d + *s) == 1)
	{
		if(*d >= 200 && *d < 300)
		{
			double h = (double)(*d + *P1 + *P2)/1000;
			if(h > 0.8)
			{
				*p = 0;
			}
			if(h > 0.6 && h <= 0.8)
			{
				*hp -= 50;
				p12(hp, d, P1, P2, s);
				*f = (double)(40 - ((fabs(*d - 500)) / 20) + gs(s)) * (1 + pt(s, t));
				*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
			}
			if(h > 0.4 && h <= 0.6)
			{
				*hp -= 30;
				p12(hp, d, P1, P2, s);
				*f = (double)(40 - ((fabs(*d - 500)) / 20) + gs(s)) * (1 + pt(s, t));
				*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
			}
			if(h > 0.2 && h <= 0.4)
			{
				*hp -= 20;
				p12(hp, d, P1, P2, s);
				*f = (double)(40 - ((fabs(*d - 500)) / 20) + gs(s)) * (1 + pt(s, t));
				*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
			}
			if(h > 0 && h <= 0.2)
			{
				*f = (double)(40 - ((fabs(*d - 500)) / 20) + gs(s)) * (1 + pt(s, t));
				*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
			}
		}
		if(*d >= 300 && *d <= 800 || *d < 200)
		{
			*f = (double)(40 - ((fabs(*d - 500)) / 20) + gs(s)) * (1 + pt(s, t));
			*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
		}
	}
	if(*d > 800)
	{
		*f = (double)(-(*d) * *s) / 1000;
		*p = (double)(*P1 + *P2 * *f) / (1000 + fabs(*P2 * *f));
	}
}

/**********************************************************************
 * Name: main
 * Target: Implements your application
 **********************************************************************/
int main() 
{
	int hp = 0, d = 0, s = 0;
	char t[100];
	double P1 = 0, P2 = 0, p = -1, f = 0;

	doc_File(&hp, &d, &s, t);
	if(kiemTraDuLieu(&hp, &d, &s, t) == 1)
	{
		p12(&hp, &d, &P1, &P2, &s);
		gs(&s);
		pt(&s, t);
		fdst(&d, &s, t, &p, &P1, &P2, &hp, &f);
		ghi_File(p);
	}else
	{
		ghi_File(p);
	}
	return 2020;
}
