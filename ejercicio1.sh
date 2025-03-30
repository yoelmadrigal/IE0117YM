#!/bin/bash

#Verificar el usuario root
if [ "$(id -u)" -ne 0 ]; then
    echo "Error: Este script debe ejecutarse como root"
    exit 1

fi

#Recibir el nombre de usuario, grupo y ruta a un archivo
if [ "$#" -ne 3 ]; then
    echo "Error: Introduzca los datos así: ./ejercicio1 usuario grupo ruta"
    exit 1
fi

usuario=$1
grupo=$2
ruta=$3
log_file="registro.log"
log_mensaje() {
              echo "$(date '+%Y-%m-%d  %H:%M:%S') - $1"  >> "$log_file"
}

#Verificar si los datos existen, si no crearlos

if [ ! -e "$ruta" ]; then
    echo "La ruta no existe"
    log_mensaje "La ruta '$ruta' no existe"
    exit 1
fi

#-----------------------------------------------

if getent group "$grupo"; then
   log_mensaje "'$grupo' ya existe."
else
    echo "'$grupo' no existe, creando grupo."
    sudo groupadd "$grupo"
fi

#-----------------------------------------------

if id "$usuario"; then
    log_mensaje "'$usuario' ya existe, agregando al grupo '$grupo'."
    if groups "$usuario" | grep -w "$grupo"; then
        log_mensaje "El usuario ya pertenece al grupo '$grupo'."
    else
        sudo usermod -a -G "$grupo" "$usuario"
        log_mensaje "Usuario ´$usuario´ agregado a ´$grupo´"
    fi
else
    echo "´$usuario´ no existe, creando usuario."
    sudo useradd -m -g "$grupo" "$usuario"
fi

#Cambiar los permisos del usuario y el grupo
echo "Cambiando la propiedad del archivo '$ruta' a '$usuario' y '$grupo'."
sudo chown "$usuario":"$grupo" "$ruta"
log_mensaje "Se cambió la pripiedad del archvo a '$usuario' '$grupo'."

echo "Cambiando los permisos de '$usuario' y '$grupo'."
sudo chmod u=rwx,g=r,o= "$ruta"
log_mensaje "Se cambiaron los permisos del archivo '$ruta'"

