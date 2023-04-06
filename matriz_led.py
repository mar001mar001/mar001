from PIL import Image, ImageDraw

from PIL import Image
#1-paso de lectura y creacion de la matriz a partir de una fot png con dimensiones 8x8, 16x16 o 16x32 segun el tamaño de los LED
#2-paso se copia y se pega la matriz creada y se cambian los corchetes y parentesis por llaves en el programa word y luego se copia y se pega en el IDE de Arduino.

# Abre el archivo PNG
imagen = Image.open("/home/mm/T_8x8.png")

# Convierte la imagen a escala de grises y a un tamaño de 8x8 píxeles
#imagen = imagen.convert('L').resize((8, 8))

# Convierte la imagen a una matriz de píxeles
matriz = list(imagen.getdata())

# Muestra la matriz resultante
print(matriz)
num_filas = len(matriz)
num_columnas = len(matriz[0])
print("El tamaño de la matriz es:", num_filas, "x", num_columnas)


#3-paso se verifca como se debe de organizar la matriz para generar la imajen deseada.


# Define la matriz de píxeles
matrix = [(255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 255), (255, 0, 0, 123), (255, 0, 0, 123), (255, 0, 0, 126), (254, 0, 0, 212), (254, 0, 0, 212), (255, 0, 0, 126), (255, 0, 0, 123), (255, 0, 0, 123), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (255, 0, 0, 5), (255, 0, 0, 171), (255, 0, 0, 171), (255, 0, 0, 5), (0, 0, 0, 0), (0, 0, 0, 0)]

# Convertir la matriz en una imagen
width = 8
height = 8
y=0
x=0
image = Image.new("RGBA", (width, height))
draw = ImageDraw.Draw(image)
for y in range(height):
    for x in range(width):
        index = x * width + y
        draw.point((y, x), fill=matrix[index])

# Guardar la imagen en un archivo
image.save("matriz.png")
num_filas = len(matrix)
num_columnas = len(matrix[0])
print("El tamaño de la matriz es:", num_filas, "x", num_columnas)
