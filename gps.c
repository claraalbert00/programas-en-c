#include <stdio.h>
#include <stdlib.h>
#define N 8

int comptanumero (n){
    int comptadorlat,comptadorlon;
    int i;
    typedef struct gps_points{
        double lat;
        double lon;
    } GPSPoint;
    GPSPoint v[N];

    for (i=0;i<N;i++){
        if (v[i].lat==n){
            comptadorlat++;
        }
        if (v[i].lon==n){
            comptadorlon++;
        }
    }
    return comptadorlat;
    return comptadorlon;
}
int ex1a5()
{
    typedef struct gps_points{
        double lat;
        double lon;
    } GPSPoint;

    int i;
    GPSPoint v[N];
    FILE*f=fopen("gps.txt","r");
    for (i=0;i<N;i++){
        fscanf(f,"%lf\t%lf\n",&v[i].lat,&v[i].lon);
    }
    fclose(f);

    for (i=0;i<N;i++){
        printf("%lf  %lf\n",v[i].lat,v[i].lon);
    }
    double sumalat=0,sumalon=0,mitjanalat,mitjanalon;
    for (i=0;i<N;i++){
        sumalat=sumalat+v[i].lat;
        sumalon=sumalon+v[i].lon;
    }
    mitjanalat=sumalat/N;
    mitjanalon=sumalon/N;

    printf("\nLa suma de les latituds es %lf\n",sumalat);
    printf("La suma de les longituds es %lf\n",sumalon);
    printf("La mitjana de les latituds es %lf\n",mitjanalat);
    printf("La mitjana de les longituds es %lf\n",mitjanalon);

    int comptadorlat=0;
    int comptadorlon=0;
    double n;

    for (i=0;i<N;i++){
        if (v[i].lat==10){
            comptadorlat++;
        }
        if (v[i].lon==10){
            comptadorlon++;
        }
    }
    printf("\nHi apareixen %i vegades 10 en latitud\n",comptadorlat);
    printf("Hi apareixen %i vegades 10 en longuitud\n",comptadorlon);

    scanf("Introdueix un numero:%lf",&n);
    comptanumero (n);

    double maxlat=0;
    double maxlon=0;

    for (i=0;i<N;i++){
        if (v[i].lat>maxlat){
            maxlat=v[i].lat;
        }
        if (v[i].lon>maxlon){
            maxlon=v[i].lon;
        }
    }

    printf("\nLa latitud maxima es:%lf\n",maxlat);
    printf("La longuitud maxima es:%lf\n",maxlon);
}

int main ()
{
    typedef struct gps_pointsAlt {
        double lat;
        double lon;
        double alt;
    } GPSPointAlt;
    int i;
    GPSPointAlt v[N];
    FILE*f=fopen("gps altura.txt","r");

    for(i=0;i<N;i++){
        fscanf(f,"%lf\t%lf\t%lf\n",&v[i].lat,&v[i].lon,&v[i].alt);
    }
    fclose (f);
    for (i=0;i<N;i++){
        printf("%lf\t%lf\t%lf\n",v[i].lat,v[i].lon,v[i].alt);
    }
    double desnivell;
    double desnivellacum=0;
    for (i=0;i<N-1;i++){
        desnivell=v[i+1].alt-v[i].alt;
        desnivellacum=desnivell+desnivellacum;
    }
    printf("\nEl desnivell acumulat es %lf\n",desnivellacum);

    double desnivellacumpos=0;
    for (i=0;i<N-1;i++){
        desnivell=v[i+1].alt-v[i].alt;
    if (desnivell>0){
        desnivellacumpos=desnivell+desnivellacumpos;
    }
    }
    printf("\nEl desnivell acumulat de pujada es %lf\n",desnivellacumpos);
}
