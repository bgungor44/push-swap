// int main(int ac, char **av)
// {
//     char **ptr;
//     int i;
//     int arg_idx;

//     if (ac < 2) // Eğer hiç argüman yoksa program bir şey yazmadan kapanmalı [cite: 270]
//         return (0);

//     arg_idx = 1; // 0 program adıdır, 1'den başlıyoruz
//     while (arg_idx < ac)
//     {
//         ptr = ft_split(av[arg_idx], '.'); // Her bir argümanı boşluğa göre böl
//         i = 0;
//         while (ptr && ptr[i])
//         {
//             printf("%s\n", ptr[i]); // Sayıları gör
//             // Burada sayıları stack yapına (struct) ekleme mantığını kurmalısın
//             free(ptr[i]); // İşin bitince temizle [cite: 35]
//             i++;
//         }
//         free(ptr);
//         arg_idx++;
//     }
//     return (0);
// }
