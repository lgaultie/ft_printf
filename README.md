# ft_printf

Allan's notes on 19 of march :
actual work : add precis to %s (%.5s), working on ft_sc and accuracy and flag conv
To do :
 Add *. and '0' to precision d AND s

 p100 :
 // printf("Vrai : i = %5%\n");
 // ft_printf("Mine : i = %5%\n");


 Vous devez gérer les conversions suivantes : csp c : character s : strings p : pointer's address

 Vous devez gérer les conversions suivantes : diouxX avec les flags hh, h, l, ll : d = i : int (short, long, double) si l'argument est un float, il sera converti en double. o : convert the number to octal and print it u : display unsigned decimal x : unsigned hexa X : x UPPERCASE

 h : un entier de type short (d,i,o,u,x,X) hh : char ((d,i,o,u,x,X)?) l : un entier de type long (d,i,o,u,x,X) ll : un entier de type long long ((d,i,o,u,x,X)?)

 Precision : An optional precision, in the form of a period . followed by an optional digit string. If the digit string is omitted, the precision is taken as zero. This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the decimal-point for a, A, e, E, f, and F conversions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s conversions.

 FLAG ESPACE —> marche pour d, f, i ajoute un espace devant le nombre printf(“|% d|”, 10); | 10| printf(“|% d|”, -10); | -10| printf("|% 4d|", -10); | -10| printf("|% f|", 1000.20); | 1000.200000| marche pas sur : c, s, p, o, u, x, X

 FLAG + —> marche pour d, f, i ajoute un + devant le nombre, se fait ecraser si chiffre negatif printf("|%+d|", 10); |+10| printf("|%+d|", -10); |-10| marche pas sur : c, s, p, o, u, x, X

 FLAG - —> marche pour c, s, p, d, i, o, u, x, X, f suivi d’un nb aligne a gauche et complete avec “nb - taille arg” espace a droite printf(“|%-4c|", 'c'); |c | printf("|%-15s|", "sa"); |sa |

 FLAG 0 —> marche sur p, d, i, o, u, x, X, f ajoute len - nb zeros devant le nb printf("|%0d|", 34); |34| printf("|%06d|", 34); |000034| printf("|%08u|", 34); |00000034| marche pas sur: c, s

 FLAG # —> marche pour o, x, X pour o = un 0 est placé devant la valeur printf("|%#o|", 16); |020| pour x = un 0x est placé devant la valeur || pour X = un 0X est placé devant la valeur printf("|%#x|", 16); |0x10| pour f = le point décimal sera toujours affiché marche pas sur c, s, d, i, u
