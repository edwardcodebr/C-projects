import random
import time
import matplotlib.pyplot as plt

from avl import AVLTree
from redblack import RBTree

valores_n = [1000, 10000, 100000]

resultados_avl = {
    "busca_existente": [],
    "busca_inexistente": [],
    "insercao": []
}

resultados_rb = {
    "busca_existente": [],
    "busca_inexistente": [],
    "insercao": []
}


for n in valores_n:

    tempos_busca_existente_avl = []
    tempos_busca_inexistente_avl = []
    tempos_insercao_avl = []

    tempos_busca_existente_rb = []
    tempos_busca_inexistente_rb = []
    tempos_insercao_rb = []

    for _ in range(50):

        valores = list(range(1, n + 1))
        random.shuffle(valores)

        # AVL
        avl = AVLTree()
        root = None

        inicio = time.perf_counter()

        for valor in valores:
            root = avl.insert(root, valor)

        fim = time.perf_counter()

        tempos_insercao_avl.append(fim - inicio)

        inicio = time.perf_counter()
        avl.search(root, 89)
        fim = time.perf_counter()

        tempos_busca_existente_avl.append(fim - inicio)

        inicio = time.perf_counter()
        avl.search(root, n + 1)
        fim = time.perf_counter()

        tempos_busca_inexistente_avl.append(fim - inicio)

        # RED BLACK
        rb = RBTree()

        inicio = time.perf_counter()

        for valor in valores:
            rb.insert(valor)

        fim = time.perf_counter()

        tempos_insercao_rb.append(fim - inicio)

        inicio = time.perf_counter()
        rb.search(rb.root, 89)
        fim = time.perf_counter()

        tempos_busca_existente_rb.append(fim - inicio)

        inicio = time.perf_counter()
        rb.search(rb.root, n + 1)
        fim = time.perf_counter()

        tempos_busca_inexistente_rb.append(fim - inicio)

    resultados_avl["busca_existente"].append(
        sum(tempos_busca_existente_avl) / 50
    )

    resultados_avl["busca_inexistente"].append(
        sum(tempos_busca_inexistente_avl) / 50
    )

    resultados_avl["insercao"].append(
        sum(tempos_insercao_avl) / 50
    )

    resultados_rb["busca_existente"].append(
        sum(tempos_busca_existente_rb) / 50
    )

    resultados_rb["busca_inexistente"].append(
        sum(tempos_busca_inexistente_rb) / 50
    )

    resultados_rb["insercao"].append(
        sum(tempos_insercao_rb) / 50
    )

print("RESULTADOS AVL")
print(resultados_avl)

print()

print("RESULTADOS RED BLACK")
print(resultados_rb)
