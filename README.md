# Ordenação e Análise de Algoritmos

## Descrição do problema

Implementação e comparação de três algoritmos de ordenação de vetores de inteiros:

- **Insertion Sort**: simples, eficiente para vetores pequenos.  
- **Merge Sort**: O(n log n), estável, bom para vetores grandes.  
- **Quick Sort**: rápido na prática, O(n log n) médio.

Escolhemos esses métodos para comparar simplicidade, eficiência teórica e desempenho prático.

---

## Como compilar e executar

Compile o programa:

```bash
gcc -O1 -std=c11 src/*.c -o ordena
```
Execute o programa e siga as instruções:
```
./ordena
```
O programa pedirá seu RGM e fará benchmarks em vetores aleatórios (100, 1000 e 10000 elementos).

Contagem de passos e tempo

Comparações (cmp): cada comparação de elementos conta como 1 passo.

Trocas (swp): cada troca de elementos conta como 1 passo.

Tempo: medido em milissegundos usando clock().

Cada teste deve ser executado 5 vezes e usa-se a média dos resultados.

Exemplo de resultados (CSV)<br>

metodo,N,caso,comparacoes,trocas,tempo_ms
insertion,3,rgm,9,10,0.0010
merge,3,rgm,9,6,0.0010
quick,3,rgm,15,10,0.0020
insertion,100,aleatorio,2596,2600,0.0130
merge,100,aleatorio,643,338,0.0080
quick,100,aleatorio,5000,2500,0.0200
insertion,1000,aleatorio,256934,256945,0.8010
merge,1000,aleatorio,11744,7094,0.1030
quick,1000,aleatorio,499500,249750,1.2000
insertion,10000,aleatorio,25035955,25035963,71.9410
merge,10000,aleatorio,174992,72754,1.0350
quick,10000,aleatorio,49995000,24997500,120.0000


Gráficos podem ser gerados a partir do CSV (Excel, Google Sheets, Python).

Discussão crítica

Insertion Sort: bom para números pequenos não escalável.

Merge Sort: consistente, eficiente para número grande.

Quick Sort: excelente desempenho prático médio, rápido em vetores aleatórios.

Limites observados: Insertion Sort inviável para números ≥ 10⁴. Merge e Quick Sort funcionam bem para números ≥ 10⁴.

Conclusão: Para vetores pequenos, qualquer algoritmo serve. Para grandes, métodos O(n log n) são essenciais. Quick Sort oferece o melhor equilíbrio entre velocidade e simplicidade prática.

Menção honrosa: Bubble Sort é interessante para quem está aprendendo.
