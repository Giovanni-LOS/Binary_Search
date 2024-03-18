#!/bin/bash

gcc -O3 -o busca_sequencial busca_sequencial.c

./busca_sequencial > resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

./busca_sequencial >> resultado_busca.txt

gcc -O3 -o media media.c

./media resultado_busca.txt
