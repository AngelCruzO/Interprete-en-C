#ifndef _TOKEN_
#define _TOKEN_
#define LEXEMA 65

//tokens permitidos
enum tokens{P_I,P_D,PREGUNTA,ASIGNA,SUMA,RESTA,MULT,DIV,MOD,POT,BLANCO,NOMBRE,NUMERO,FIN,ERROR};

/*estructura para definir propiedades de un token*/
typedef struct token{
    unsigned long posicion;
    char lexema[LEXEMA];
    int token;
}token_t;

#endif