#!/bin/bash

gcc -O3 -o busca_binaria busca_binaria.c

./busca_binaria > resultado_busca.txt

./busca_binaria >> resultado_busca.txt

./busca_binaria >> resultado_busca.txt

./busca_binaria >> resultado_busca.txt

./busca_binaria >> resultado_busca.txt

gcc -O3 -o media media.c

./media resultado_busca.txt
