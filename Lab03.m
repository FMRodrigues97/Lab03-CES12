merge_iterativo_rand = csvread('MRG_I_MS_RAND_200_20000.csv');
merge_recursivo_rand = csvread('MRG_R_MS_RAND_200_20000.csv');
quick_1R_AO = csvread('QS_1R_MS_AO_200_20000.csv');
quick_1R_rand = csvread('QS_1R_MS_RAND_200_20000.csv');
quick_2R_AO = csvread('QS_2R_MS_AO_200_20000.csv');
quick_2R_rand = csvread('QS_2R_MS_RAND_200_20000.csv');
quick_FP_AO = csvread('QS_FP_MS_AO_200_20000.csv');
quick_FP_rand = csvread('QS_FP_MS_RAND_200_20000.csv');
radix_rand = csvread('RADIX_MS_RAND_200_20000.csv');
stl_AO = csvread('STL_SORT_MS_AO_200_20000.csv');
stl_rand = csvread('STL_SORT_MS_RAND_200_20000.csv');

% Figura 1
figure;
grid on;
hold on;
plot (quick_1R_rand(:, 3), quick_1R_rand(:, 1));
plot (merge_iterativo_rand(:, 3), merge_iterativo_rand(:, 1));
plot (radix_rand(:, 3), radix_rand(:, 1));
xlabel ('Tamanho do vetor');
ylabel ('Tempo (ms)');
title ('Tempo de execução QuickSort X MergeSort X RadixSort');
legend('QuickSort', 'MergeSort', 'RadixSort');

% Figura 2
figure;
grid on;
hold on;
plot (merge_recursivo_rand(:, 3), merge_recursivo_rand(:, 1));
plot (merge_iterativo_rand(:, 3), merge_iterativo_rand(:, 1));
xlabel ('Tamanho do vetor');
ylabel ('Tempo (ms)');
title ("MergeSort: Recursivo x Iterativo");
legend('Recursivo', 'Iterativo');

% Figura 3
figure;
grid on;
hold on;
plot (merge_recursivo_rand(:, 3), merge_recursivo_rand(:, 5));
plot (merge_iterativo_rand(:, 3), merge_iterativo_rand(:, 5));
xlabel ('Tamanho do vetor');
ylabel ('Profundidade da Árvore');
title ("MergeSort: Recursivo x Iterativo");
legend('Recursivo', 'Iterativo');

% Figura 4
figure;
grid on;
hold on;
plot (quick_1R_rand(:, 3), quick_1R_rand(:, 1));
plot (quick_2R_rand(:, 3), quick_2R_rand(:, 1));
xlabel ('Tamanho do vetor');
ylabel ('Tempo (ms)');
title ("QuickSort: 1 recursão x 2 recursões");
legend('1 Recursão', '2 Recursões');

% Figura 5
figure;
grid on;
hold on;
plot (quick_1R_rand(:, 3), quick_1R_rand(:, 5));
plot (quick_2R_rand(:, 3), quick_2R_rand(:, 5));
xlabel ('Tamanho do vetor');
ylabel ('Profundidade da Árvore');
title ("QuickSort: 1 recursão x 2 recursões");
legend('1 Recursão', '2 Recursões');

% Figura 6
figure;
grid on;
hold on;
plot (quick_1R_rand(:, 3), quick_1R_rand(:, 4));
plot (quick_2R_rand(:, 3), quick_2R_rand(:, 4));
xlabel ('Tamanho do vetor');
ylabel ('Chamadas Recursivas');
title ("QuickSort: 1 recursão x 2 recursões");
legend('1 Recursão', '2 Recursões');

% Figura 7
figure;
grid on;
hold on;
plot (quick_1R_AO(:, 3), quick_1R_AO(:, 1));
plot (quick_FP_AO(:, 3), quick_FP_AO(:, 1));
xlabel ('Tamanho do vetor');
ylabel ('Tempo (ms)');
title ("QuickSort: mediana de 3 x pivô fixo para vetores quase ordenados");
legend('Mediana de 3', 'Pivô Fixo');

% Figura 8
figure;
grid on;
hold on;
plot (quick_FP_AO(:, 3), quick_FP_AO(:, 5));
plot (quick_1R_AO(:, 3), quick_1R_AO(:, 5));
xlabel ('Tamanho do vetor');
ylabel ('Profundidade da Árvore');
title ("QuickSort: mediana de 3 x pivô fixo para vetores quase ordenados");
legend('Mediana de 3', 'Pivô Fixo');

% Figura 9
figure;
grid on;
hold on;
plot (quick_1R_AO(:, 3), quick_1R_AO(:, 4));
plot (quick_FP_AO(:, 3), quick_FP_AO(:, 4));
xlabel ('Tamanho do Vetor');
ylabel ('Chamadas Recursivas');
title ("QuickSort: mediana de 3 x pivô fixo para vetores quase ordenados");
legend('Mediana de 3', 'Pivô Fixo');