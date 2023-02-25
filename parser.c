#include "parser.h"

int funciones(void);
int funcion(void);
int parametros(void);
int nombres(void);
int cuerpo(void);
int tuplas(void);
int tupla(void);
int operador(void);
int operandos(void);
int operando(void);

int s(void){
    return (funciones() && tuplas() ? 1 : 0);
}

int funciones(void){
    if(funcion()){
        return funciones();
    }
    return 1;
}

int funcion(void){
    token_t token = get_token();
    if(token.token == NOMBRE){
        if(parametros() && cuerpo()){
            return 1;
        }
    }
    unget_token(token);
    return 0;
}

int parametros(void){
    token_t token = get_token();
    if(token.token == P_I){
        if(nombres()){
            token_t token = get_token();
            if(token.token == P_D){
                return 1;
            }
            unget_token(token);
            return 0;
        }
    }
    unget_token(token);
    return 0;
}

int nombres(void){
    token_t token = get_token();
    if(token.token == NOMBRE){
        return nombres();
    }
    unget_token(token);
    return 1;
}

int cuerpo(void){
    token_t token = get_token();
    if(token.token == P_I){
        if(tuplas()){
            token_t token = get_token();
            if(token.token == P_D){
                return 1;
            }
            unget_token(token);
        }
    }
    unget_token(token);
    return 0;
}

int tuplas(void){    
    if(tupla()){
        token_t token = get_token();
        unget_token(token);
        if(token.token == P_I){
            return tuplas();
        }
        return 1;
    }
    return 0;
}

int tupla(void){
    token_t token = get_token();
    if(token.token == P_I){
        if(operador() & operandos()){
            token_t token = get_token();
            if(token.token == P_D){
                return 1;
            }
            unget_token(token);
            return 0;
        }
        return 0;
    }
    unget_token(token);
    return 0;
}

int operador(void){
    token_t token = get_token();
    if(token.token == PREGUNTA) return 1;
    if(token.token == ASIGNA) return 1;
    if(token.token == SUMA) return 1;
    if(token.token == RESTA) return 1;
    if(token.token == MULT) return 1;
    if(token.token == DIV) return 1;
    if(token.token == MOD) return 1;
    if(token.token == POT) return 1;
    if(token.token == NOMBRE) return 1;
    unget_token(token);
    return 0;
}

int operandos(void){
    if(operando()){
        token_t token = get_token();
        unget_token(token);
        if(token.token == NUMERO || token.token == NOMBRE || token.token == PREGUNTA || token.token == P_I){
            return operandos();
        }
        return 1;
    }
    return 0;
}

int operando(void){
    token_t token = get_token();
    if(token.token == P_I){
        unget_token(token);
        return tupla();
    }
    if(token.token == NUMERO) return 1;
    if(token.token == NOMBRE) return 1;
    if(token.token == PREGUNTA) return 1;
    unget_token(token);
    return 0;
}