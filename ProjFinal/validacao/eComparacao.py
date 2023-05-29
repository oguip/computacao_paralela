def encontrar_divergencias(string1, string2):
    divergencias = []

    # Compara caractere por caractere
    for i in range(min(len(string1), len(string2))):
        if string1[i] != string2[i]:
            divergencias.append(f"Divergência na posição {i + 1}: {string1[i]} != {string2[i]}")

    return divergencias


# Exemplo de uso
with open('resultadoParalelo.txt') as f:
    string1 = f.readlines()[0]

with open('original.txt') as f:
    original = f.readlines()[0]

divergencias = encontrar_divergencias(string1, original)
if divergencias:
    print("Divergências encontradas:")
    for divergencia in divergencias:
        print(divergencia)
        break
else:
    print("Não foram encontradas divergências.")

