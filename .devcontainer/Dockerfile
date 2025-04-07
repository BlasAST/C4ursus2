# Usa una imagen base más ligera de Alpine
FROM ubuntu

# Instala las dependencias necesarias en una sola capa para mayor eficiencia
RUN apt update && apt upgrade -y
RUN apt install fish -y
RUN apt install gcc -y
RUN apt install g++ -y
RUN apt install make -y
RUN apt install libc-dev -y
RUN apt install git -y
RUN apt install curl -y

# Mantén el contenedor corriendo
CMD [ "fish" ]
