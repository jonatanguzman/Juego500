#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
}

void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
}

int contarNumerosRepetidos(int v[], int numero, int tam)
{
    int i, cant=0;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero) cant++;
    }
    return cant;
}

int sumarVector(int v[], int tam )
{
    int i, suma=0;
    for(i=0; i<tam; i++)
    {
        suma+=v[i];
    }
    return suma;
}

int maximoVector(int v[], int tam)
{
    int i, posMax=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]>v[posMax])
        {
            posMax=i;
        }
    }
    return posMax;
}

void gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void textcolor(short colorTexto, short colorFondo)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo)
{
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++)
    {
        for(j=iniY; j<=iniY+alto; j++)
        {
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY)
            {
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY)
            {
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto)
            {
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto)
            {
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto)
            {
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho)
            {
                cout << (char) 186;
            }
            //Dentro del recuadro
            else
            {
                cout << " ";
            }
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
