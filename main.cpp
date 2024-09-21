///Ejercicio: JUEGO 500/ESCALERA
///Autor: Guzman Jonatan RODRIGO
///Fecha: 10/07
///Comentario:

#include <windows.h>

#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "Funciones.h"

int main()
{
    char nombre1[15],nombre2[15];
    int opc,dados1[6],dados2[6],puntos=0,ronda=1;
    int c,i,numero,suma,maximo,quinientos=1,lanzamiento=1;
    int lanzamiento1=1,ronda1=1,puntos1=0,r;
    while (true)
    {
        recuadro (1,1,110,8,15,0);
        gotoxy(40,2);
        cout<<"-------> MENU PRINCIPAL <-------";
        gotoxy(40,3);
        cout<<"OPCION 1---> MODO UN JUGADOR----";
        gotoxy(40,4);
        cout<<"OPCION 2---> MODO DOS JUGADORES-";
        gotoxy(40,5);
        cout<<"OPCION 0---> FINALIZA EL JUEGO--";
        gotoxy(40,6);
        cout<<"------> ELIJA UNA OPCION -------";
        gotoxy(40,7);
        cin>>opc;
        system("cls");
        switch (opc)
        {
        case 1: ///MODO 1 JUGADOR<---------------------------
            recuadro (1,1,110,8,15,0);
            gotoxy(40,2);
            cout<<">>> MODO UN JUGADOR <<<";
            gotoxy(40,4);
            cout<<"  INGRESE SU NOMBRE:";
            cin.ignore();
            gotoxy(45,5);
            cin.getline(nombre1,15);
            cout<<endl;
            gotoxy(40,8);
            cout<<">>> COMIENZA EL JUEGO <<<";
            gotoxy(1,10);
            system ("pause");
            system ("cls");

            while (quinientos!=0||puntos<500)
            {
                int escalera=0,sexteto6=0,numrepetidos=0,sextetoX=0,menosde3=0,masde3=0;
                recuadro (1,1,110,8,15,0);
                gotoxy(20,2);
                cout<<"JUGADOR: ",cout<<nombre1<<"\t",cout<<"LANZAMIENTO: "<<lanzamiento<<"\t",cout<<"RONDA: "<<ronda<<"\t",cout<<"SUS PUNTOS SON: ",cout<<puntos;
                cargarAleatorio (dados1, 6,6);
                gotoxy(31,5);
                mostrarVector (dados1,6);
                cout<<endl;
                for(i=0; i<6; i++)
                {
                    numero=dados1[i];
                    numrepetidos=contarNumerosRepetidos (dados1,numero,6);
                    if (dados1[i]==i+1&&numrepetidos==1)
                    {
                        escalera++;
                    }
                    if (numrepetidos==6)
                    {
                        sexteto6++;
                    }
                    if (dados1[i]!=6&&numrepetidos==6)
                    {
                        sextetoX++;
                    }
                    if (numrepetidos<3&&escalera!=6)
                    {
                        menosde3++;
                    if (dados1[1]>dados1[5]){
                        maximo=dados1[1];
                    }
                    else {
                        maximo=dados1[5];
                    }
                    }
                    if (numrepetidos>=3&&numrepetidos<6)
                    {
                        masde3++;
                        maximo=dados1[i];
                    }
                }///for de combinaciones
                if (escalera==6)
                {
                    recuadro (1,1,110,8,15,0);
                    gotoxy(40,2);
                    cout<<"FELICITACIONES USTED GANO EL JUEGO"<<endl;
                    gotoxy(40,4);
                    cout<<"----------> ESCALERA!! <----------"<<endl;
                    gotoxy(31,6);
                    mostrarVector (dados1,6);
                    puntos=500;
                    quinientos=0;
                    gotoxy(40,8);
                    cout<<"AHORA SUS PUNTOS SON: "<<puntos<<endl;
                    gotoxy(1,10);
                    system ("pause");
                }
                if (sexteto6==6)
                {
                    gotoxy(40,7);
                    cout<<"PERDIO SUS PUNTOS";
                    suma=0;
                    gotoxy(40,8);
                    cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                }
                if (sextetoX==6)
                {
                    suma=numero*50;
                    puntos=suma+puntos;
                    gotoxy(40,8);
                    cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                }
                if (menosde3==6)
                {
                    suma=sumarVector(dados1,6);
                    puntos=suma+puntos;
                    gotoxy(40,8);
                    cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                }
                if (masde3>=3)
                {
                    suma=maximo*10;
                    puntos=suma+puntos;
                    gotoxy(40,8);
                    cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                }
                if (puntos>500)
                {
                    quinientos=0;
                }
                if (lanzamiento>=3)
                {
                    lanzamiento=0;
                    ronda++;
                    gotoxy(1,10);
                    system ("pause");
                    recuadro (1,1,110,8,15,0);
                    gotoxy(40,2);
                    cout<<">>> RONDA N:  "<<ronda;
                    gotoxy(40,4);
                    cout<<">>> JUGADOR:  "<<nombre1;
                    gotoxy(40,6);
                    cout<<">>> SU PUNTAJE ES: "<<puntos;
                    gotoxy(40,8);
                    cout<<"---------------------------";
                }
                lanzamiento++;
                gotoxy(1,10);
                system ("pause");
                system ("cls");
            }///while
            ronda++;
            recuadro (1,1,110,8,15,0);
            gotoxy(40,2);
            cout<<">>> JUGADOR: ",cout<<nombre1;
            gotoxy(40,4);
            cout<<">>> TERMINO SU RONDA:  "<<ronda;
            gotoxy(40,8);
            cout<<">>> SUS PUNTOS SON: "<<puntos;
            ronda=1,puntos=0,quinientos=1,lanzamiento=1;
            break;
        case 2: ///MODO 2 JUGADORES<---------------------------
            recuadro (1,1,110,8,15,0);
            gotoxy(40,2);
            cout<<">>> MODO DOS JUGADORES <<<";
            gotoxy(40,3);
            cout<<"JUGADOR UNO INGRESE SU NOMBRE:";
            cin.ignore();
            gotoxy(40,4);
            cin.getline(nombre1,15);
            gotoxy(40,5);
            cout<<"JUGADOR DOS INGRESE SU NOMBRE:";
            gotoxy(40,6);
            cin.getline(nombre2,15);
            gotoxy(40,8);
            cout<<">>> COMIENZA EL JUEGO <<<";
            gotoxy(1,10);
            system ("pause");
            system ("cls");
            while (quinientos!=0)
            {
                for (c=0; c<3; c++) ///FOR RONDA JUGADOR 1
                {
                    int escalera=0,sexteto6=0,numrepetidos=0,sextetoX=0,menosde3=0,masde3=0;
///LANZAMIENTO JUGADOR 1<-----------------------------------------------
                    recuadro (1,1,110,8,15,0);
                    gotoxy(20,2);
                    cout<<"JUGADOR: ",cout<<nombre1<<"\t",cout<<"LANZAMIENTO: "<<lanzamiento<<"\t",cout<<"RONDA: "<<ronda<<"\t",cout<<"SUS PUNTOS SON: ",cout<<puntos;
                    cargarAleatorio (dados1, 6,6);
                    gotoxy(31,5);
                    mostrarVector (dados1,6);
                    cout<<endl;
                    for(i=0; i<6; i++)
                    {
                        numero=dados1[i];
                        numrepetidos=contarNumerosRepetidos (dados1,numero,6);
                        if (dados1[i]==i+1&&numrepetidos==1)
                        {
                            escalera++;
                        }
                        if (numrepetidos==6)
                        {
                            sexteto6++;
                        }
                        if (dados1[i]!=6&&numrepetidos==6)
                        {
                            sextetoX++;
                        }
                        if (numrepetidos<3&&escalera!=6)
                        {
                            menosde3++;
                        }
                        if (numrepetidos>=3&&numrepetidos<6)
                        {
                            masde3++;
                            maximo=dados1[i];
                        }
                    }///for de combinaciones
                    if (sexteto6==6)
                    {
                        gotoxy(40,7);
                        cout<<"PERDIO SUS PUNTOS";
                        suma=0;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (sextetoX==6)
                    {
                        suma=numero*50;
                        puntos=suma+puntos;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (menosde3==6)
                    {
                        suma=sumarVector(dados1,6);
                        puntos=suma+puntos;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (masde3>=3)
                    {
                        suma=maximo*10;
                        puntos=suma+puntos;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (escalera==6)
                    {
                        recuadro (1,1,110,8,15,0);
                        gotoxy(40,2);
                        cout<<"FELICITACIONES USTED GANO EL JUEGO"<<endl;
                        gotoxy(40,4);
                        cout<<"----------> ESCALERA!! <----------"<<endl;
                        gotoxy(31,6);
                        mostrarVector (dados1,6);
                        puntos=500;
                        quinientos=0;
                        gotoxy(40,8);
                        cout<<"AHORA SUS PUNTOS SON: "<<puntos<<endl;
                        gotoxy(1,10);
                        system ("pause");
                    }
                    if (puntos>500)
                    {
                        quinientos=0;
                    }
                    if (lanzamiento>=3)
                    {
                        lanzamiento=0;
                        ronda++;
                    }
                    lanzamiento++;
                    gotoxy(1,10);
                    system ("pause");
                    system ("cls");
                }///FOR RONDA JUGADOR 1
                recuadro (1,1,110,8,15,0);
                gotoxy(40,2);
                cout<<">>> RONDA N:   "<<ronda;
                gotoxy(40,4);
                cout<<">>> PROXIMO TURNO:  "<<nombre2;
                gotoxy(40,6);
                cout<<nombre1<<" SU PUNTAJE ES: "<<puntos;
                gotoxy(40,8);
                cout<<nombre2<<" SU PUNTAJE ES: "<<puntos1;
                gotoxy(1,10);
                system ("pause");

///LANZAMIENTO JUGADOR 2<-----------------------------------------------
                for (r=0; r<3; r++)
                {
                    int escalera=0,sexteto6=0,numrepetidos=0,sextetoX=0,menosde3=0,masde3=0;
                    recuadro (1,1,110,8,15,0);
                    gotoxy(20,2);
                    cout<<"JUGADOR: ",cout<<nombre2<<"\t",cout<<"LANZAMIENTO: "<<lanzamiento1<<"\t",cout<<"RONDA: "<<ronda1<<"\t",cout<<"SUS PUNTOS SON: ",cout<<puntos1;
                    cargarAleatorio (dados2, 6,6);
                    gotoxy(31,5);
                    mostrarVector (dados2,6);
                    for(i=0; i<6; i++)
                    {
                        numero=dados2[i];
                        numrepetidos=contarNumerosRepetidos (dados2,numero,6);
                        if (dados1[i]==i+1&&numrepetidos==1)
                        {
                            escalera++;
                        }
                        if (numrepetidos==6)
                        {
                            sexteto6++;
                        }
                        if (dados2[i]!=6&&numrepetidos==6)
                        {
                            sextetoX++;
                        }
                        if (numrepetidos<3&&escalera!=6)
                        {
                            menosde3++;
                        }
                        if (numrepetidos>=3&&numrepetidos<6)
                        {
                            masde3++;
                            maximo=dados2[i];
                        }
                    }///for de combinaciones
                    if (sexteto6==6)
                    {
                        gotoxy(40,7);
                        cout<<"PERDIO SUS PUNTOS";
                        suma=0;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (sextetoX==6)
                    {
                        suma=numero*50;
                        puntos1=suma+puntos;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (menosde3==6)
                    {
                        suma=sumarVector(dados1,6);
                        puntos1=suma+puntos1;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (masde3>=3)
                    {
                        suma=maximo*10;
                        puntos1=suma+puntos1;
                        gotoxy(40,8);
                        cout<<"USTED SUMA: "<<suma<<" PUNTOS";
                    }
                    if (escalera==6)
                    {
                        recuadro (1,1,110,8,15,0);
                        gotoxy(40,2);
                        cout<<"FELICITACIONES USTED GANO EL JUEGO"<<endl;
                        gotoxy(40,4);
                        cout<<"----------> ESCALERA!! <----------"<<endl;
                        gotoxy(31,6);
                        mostrarVector (dados1,6);
                        puntos=500;
                        quinientos=0;
                        gotoxy(40,8);
                        cout<<"AHORA SUS PUNTOS SON: "<<puntos1<<endl;
                        gotoxy(1,10);
                        system ("pause");
                        return 0;
                    }
                    if (puntos1>500)
                    {
                        quinientos=0;
                    }
                    if (lanzamiento1>=3)
                    {
                        lanzamiento1=0;
                        ronda1++;
                    }
                    lanzamiento1++;
                    gotoxy(1,10);
                    system ("pause");
                    system ("cls");
                }///FOR RONDA JUGADOR 2
                recuadro (1,1,110,8,15,0);
                gotoxy(40,2);
                cout<<">>> RONDA N:   "<<ronda;
                gotoxy(40,4);
                cout<<">>> PROXIMO TURNO:  "<<nombre1;
                gotoxy(40,6);
                cout<<nombre1<<" SU PUNTAJE ES: "<<puntos;
                gotoxy(40,8);
                cout<<nombre2<<" SU PUNTAJE ES: "<<puntos1;
                gotoxy(1,10);
                system ("pause");
            }///while
            if (puntos>=500)
            {
                recuadro (1,1,110,8,15,0);
                gotoxy(40,2);
                cout<<">>> JUGADOR: ",cout<<nombre1;
                gotoxy(40,4);
                cout<<">>> TERMINO SU RONDA:  "<<ronda;
                gotoxy(40,6);
                cout<<">>> GANO LA PARTIDA!! <<<";
                gotoxy(40,8);
                cout<<">>> SUS PUNTOS SON: "<<puntos;
            }
            else
            {
                recuadro (1,1,110,8,15,0);
                gotoxy(40,2);
                cout<<">>> JUGADOR: ",cout<<nombre2;
                gotoxy(40,4);
                cout<<">>> TERMINO SU RONDA:  "<<ronda1;
                gotoxy(40,6);
                cout<<">>> GANO LA PARTIDA!! <<<";
                gotoxy(40,8);
                cout<<">>> SUS PUNTOS SON: "<<puntos1;
            }
            ronda=1,puntos=0,quinientos=1,lanzamiento=1;
            ronda1=1,puntos1=0,quinientos=1,lanzamiento1=1;
            break;
        case 0:
            recuadro (1,1,110,8,15,0);
            gotoxy(40,2);
            cout<<"   -----> JUEGO FINALIZADO! <-----";
            gotoxy(40,4);
            cout<<"GRACIAS POR HABER UTILIZADO MI JUEGO";
            gotoxy(40,6);
            cout<<"    ESPERO QUE TE HAYA GUSTADO!";
            gotoxy(40,8);
            cout<<"<--------------------------------->";
            gotoxy(1,10);
            system ("pause");
            system ("cls");
            return 0;
            break;
        default:
            recuadro (1,1,110,8,15,0);
            gotoxy(40,4);
            cout<<"       -----> OPCION INCORRECTA <-----";
            gotoxy(40,6);
            cout<<"RETOME EL MENU Y VUELVA A INGRESAR UNA OPCION";
            break;

        }///switch
        gotoxy(1,10);
        system ("pause");
    }
    return 0;
}
