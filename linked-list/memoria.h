#ifndef MEMORIA_H
#define MEMORIA_H

#include "lista.h"

p_Lista aloca(p_Lista lista, int tamanho);

p_Lista desaloca(p_Lista lista, int endereco, int tamanho);

p_Lista realoca(p_Lista lista);

#endif