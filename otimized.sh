#!/bin/bash

gcc -O3 -o busca_sequencial_otimizada busca_sequencial_otimizada.c

./busca_sequencial_otimizada > resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

./busca_sequencial_otimizada >> resultado_busca.txt

gcc -O2 -o media media.c

./media resultado_busca.txt
