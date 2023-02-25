#include "lexer.h"

//declaracion de un automata en forma de matriz
unsigned int automata[][19] = {
   //(  )   ?   =   +   -   *   /   %    ^ ' ' \n   \t  \r  .   _  digit  alpha
    {1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	11,	11,	11,	13,	20,	12,18,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {15,15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	13,	15,	12,15,22},
    {16,16,	16,	16,	16,	16,	16,	16,	16,	16,	16,	16,	16,	16,	13,	16,	12,16,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {17,17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	13,	17,	12,17,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	14,22,22},
    {17,17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	14,17,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {19,19,	19,	19,	19,	19,	19,	19,	19,	19,	19,	19,	19,	19,	19,	18,	18,18,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,18,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22},
    {22,22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,22,22}
};

FILE *f;

int obtener_columna(char c){
    char alfabeto[] = {'(',')','?','=','+','-','*','/','%','^',' ','\n','\t','\r','.','_'};
    int i;

    //tokens que pertenecen al alfabeto
    for(i=0;i<16;i++){
        if(c == alfabeto[i])
            return i;
    }

    if(isdigit(c)){
        return i; //caracter numerico
    }else if (isalpha(c)){
        return i+1; //caracter alfabetico
    }else{
        return i+2; //cualquier otro caracter
    }
}

/*
lectura de un archivo identificando los tokens que aparacen
*/
token_t get_token(void){
    char c;
    token_t token;
    int i = 0;
    token.posicion = ftell(f);
    int estado = 0;

    //recorrido de posición del archivo dentro del automata
    while((c = getc(f)) != EOF){
        
        token.lexema[i++] = c;
        token.lexema[i] = '\0';

        int columna = obtener_columna(c);
        estado = automata[estado][columna];
        //evaluar estado
        switch (estado){

            case 1:
                token.token = P_I;
                return token;
            break;

            case 2:
                token.token = P_D;
                return token;
            break;

            case 3:
                token.token = PREGUNTA;
                return token;
            break;

            case 4:
                token.token = ASIGNA;
                return token;
            break;

            // case 5:

            // break;

            // case 6:
            // break;

            case 7:
                token.token = MULT;
                return token;
            break;

            case 8:
                token.token = DIV;
                return token;
            break;

            case 9:
                token.token = MOD;
                return token;
            break;

            case 10:
                token.token = POT;
                return token;
            break;

            case 11:
                //token.token = BLANCO;
                //return token;
                i = 0;
                token.lexema[i] = '\0';
                token.posicion = ftell(f);
                estado = 0;
            break;

            // case 12:

            // break;

            // case 13:
            // break;

            // case 14:
            // break;

            case 15:
                token.token = SUMA;
                token.lexema[--i] = '\0'; //se elimina del lexema
                fseek(f, ftell(f)-1, 0); //se la posición actual del archivo se regresa una
                return token;
            break;

            case 16:
                token.token = RESTA;
                token.lexema[--i] = '\0'; 
                fseek(f, ftell(f)-1, 0); 
                return token;
            break;

            case 17:
                token.token = NUMERO;
                token.lexema[--i] = '\0'; //se elimina del lexema
                fseek(f, ftell(f)-1, 0); //se la posición actual del archivo se regresa una
                return token;
            break;

            case 18:
            break;

            case 19:
                token.token = NOMBRE;
                token.lexema[--i] = '\0'; //se elimina del lexema
                fseek(f, ftell(f)-1, 0); //se la posición actual del archivo se regresa una
                return token;
            break;

            // case 20:
            // break;

            // case 21:
            // break;

            case 22:
                token.token = ERROR;
                return token;
            break;
        }//switch

    }//while

    token.lexema[0] = '\0';
    token.token = FIN;
    
    return token;
}

/*lectura de token no leidos*/
void unget_token(token_t token){
    fseek(f, token.posicion, 0);
}