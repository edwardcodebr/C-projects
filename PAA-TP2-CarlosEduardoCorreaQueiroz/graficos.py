import matplotlib.pyplot as plt

valores_n = [1000, 10000, 100000]

avl_busca = [0.00001, 0.00002, 0.00003]
rb_busca = [0.00002, 0.00003, 0.00004]

plt.figure(figsize=(10, 5))

plt.plot(valores_n, avl_busca, marker='o')
plt.plot(valores_n, rb_busca, marker='o')

plt.xlabel("Valor de n")
plt.ylabel("Tempo Médio")
plt.title("Comparação AVL x Red Black")

plt.legend([
    "AVL",
    "Red Black"
])

plt.grid(True)
plt.show()
