#include <stdio.h>
//Prototipado
void mostrarTablero(char [][3]);
void InicializarVec (char [][3], int , int);
int ValidarPosicion (int ,int, char [][3] );
int validarCelda(char [][3], int, int);
void GuardarValor(char [][3], int , int , char );
int VerificarGanador (char [][3]);
int verificarEmpate(char [][3]);
char VolverAEmpezar_Fin(char mat[][3]);

//Principal
int main()
{
    char tateti [3][3];
    int pos,pos2,n=0,n2,Em,mov=0;
    char jugadorX,jugadorO,Finalizar;
        InicializarVec(tateti,3,3);
        mostrarTablero(tateti);

        do{//jugador X
            Finalizar=' ';
            do{
                n2 = 0;
                printf("\nJugador X, indique Fila:");
                pos = ValidarPosicion(0, 2, tateti);

                printf("\nJugador X, indique Columna:");
                pos2 = ValidarPosicion(0, 2, tateti);

                n2 = validarCelda(tateti, pos, pos2);
            }while(n2!=0);



            GuardarValor(tateti, pos, pos2,'X');
            printf("\n");

            mostrarTablero(tateti);
            mov++;
            //verificar X
            if(mov>=5){
                n = VerificarGanador(tateti);
                Em = verificarEmpate(tateti);
                if(n == 1 || Em == 1) {
                printf("El jugador X es el ganador!");
                Finalizar = VolverAEmpezar_Fin(tateti);
                if (Finalizar == 'R') {
                    InicializarVec(tateti, 3, 3);
                    printf("\n");
                    mostrarTablero(tateti);
                    mov=0;
                    }
                }
            }
            if(Finalizar==' '){
                //jugador O
                do{
                    n2 = 0;
                    printf("\nJugador O, indique Fila:");
                    pos = ValidarPosicion(0, 2, tateti);

                    printf("\nJugador O, indique Columna:");
                    pos2 = ValidarPosicion(0, 2, tateti);

                    n2 = validarCelda(tateti, pos, pos2);
                }while(n2!=0);


                GuardarValor(tateti, pos, pos2,'O');
                printf("\n");

                mostrarTablero(tateti);
                mov ++;
                //verificar O
                if(mov>=5){
                    n = VerificarGanador(tateti);
                    Em = verificarEmpate(tateti);
                    if(n == 1 || Em == 1) {
                    printf("El jugador O es el ganador!");
                    Finalizar = VolverAEmpezar_Fin(tateti);
                    if (Finalizar == 'R') {
                        InicializarVec(tateti, 3, 3);
                        printf("\n");
                        mostrarTablero(tateti);
                        Finalizar=' ';
                        mov=0;
                        }
                    }
                }
            }
        }while(Finalizar != 'N');

    return 0;
}
//Funciones
void mostrarTablero(char mat[3][3]) {
    printf(" %c | %c | %c \n", mat[0][0], mat[0][1], mat[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", mat[1][0], mat[1][1], mat[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", mat[2][0], mat[2][1], mat[2][2]);
}

void InicializarVec (char mat[][3], int fila, int columna){ //Todas las posicones del vector las rellena con un espacio.
    int i,j;
    for(i=0 ;i<fila ;i++){
        for(j=0 ;j<columna ;j++){
            mat[i][j] = ' ';
        }
    }
}

int ValidarPosicion (int limInfe,int limSup,char mat[][3]){ //Para que cada jugador pueda ingresar X o O
    int n1;
    do{
        scanf("%d",&n1);
        if(n1 < limInfe || n1 > limSup)
            printf("\nPosicion no valida...intente nuevamente:");
    }while(n1 < limInfe || n1 > limSup);
    return n1;
}
int validarCelda(char mat[][3],int posi1, int posi2){
    int num = 0;
    if (mat[posi1][posi2]!= ' '){
        printf("\nLa posicion seleccionada ya esta utilizada.Vuelva a ingresar los valores\n");
        num = 1;
    }
    return num;
}

void GuardarValor(char mat[][3], int n1, int n2, char let){ //Guardar una X o O en la posicion ingresada
    mat[n1][n2]=let;
}

int VerificarGanador (char mat[][3]){
    int num = 0;
    //filas
    if((mat[0][0]==mat[0][1])&&(mat[0][1]==mat[0][2]) ||
       (mat[1][0]==mat[1][1])&&(mat[1][1]==mat[1][2]) ||
       (mat[2][0]==mat[2][1])&&(mat[2][1]==mat[2][2])){
        num = 1;
    }
    //columnas
    if((mat[0][0]==mat[1][0])&&(mat[1][0]==mat[2][0]) ||
       (mat[0][1]==mat[1][1])&&(mat[1][1]==mat[2][1]) ||
       (mat[0][2]==mat[1][2])&&(mat[1][2]==mat[2][2])){
        num = 1;
    }
    //diagonalPrincipal
    if((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2])){
        num = 1;
    }
    //ContraDiagonal
    if((mat[0][2]==mat[1][1])&&(mat[1][1]==mat[2][0]))
        num = 1;

    //num = verificarEmpate(mat);

    return num;
}

int verificarEmpate(char mat[][3]){
    int n = 1, i, j;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == ' ') {
                return n = 0; // Hay al menos una celda vacía, no es empate
            }
        }
    }
    printf("\nEmpate!\n");
    return n;
}

char VolverAEmpezar_Fin(char mat[][3]){
    int n;
    char fin;
    n = VerificarGanador(mat);
    if(n==1){
           do{
            printf("\nIngresar R para volver a jugar o N para finalizar:");
            scanf(" %c",&fin);
            if(fin != 'R' && fin != 'N')
                printf("\nEl valor ingresado no es valido");
           }while(fin != 'R' && fin != 'N');
        }
    return fin;
}























