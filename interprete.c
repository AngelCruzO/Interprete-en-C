#include "parser.h"

/*
compilar en vscode
gcc interprete.c lexer.c -o interprete
./interprete nombre archivo
*/

void mostrar_token(token_t);

int main(int argc, char **args){

    if(argc != 2){
        fprintf(stderr, "USO: %s archivo\n", args[0]);
        return 1;
    }

    f = fopen(args[1], "r");
    /*token_t t;

    while((t = get_token(f)).token != FIN){
        mostrar_token(t);
    }

    fseek(f, 0, 0);*/

    if(s() && getc(f) == EOF){
        fprintf(stdout,"OK\n");
        return 0;
    }else{
        fprintf(stderr, "ERROR\n");
        return 1;
    }
}

void mostrar_token(token_t t){
    char *s_tokens[] = {"P_I","P_D","PREGUNTA","ASIGNA","SUMA","RESTA","MULT","DIV","MOD","POT","BLANCO","NOMBRE","NUMERO","FIN","ERROR"};
    printf("Tipo: %s\n", s_tokens[t.token]);
    printf("Lexema: %s\n", t.lexema);
    printf("----------\n");
}