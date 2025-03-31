#!/bin/bash

archivo="datos.log"

#Verificar el argumento
if [ -z "$1" ]; then
    echo "Proporcione un argumento válido"
    exit 1
fi

#Ejecutar el argumento
$1 &

#Registro de consumo en el log
pid=$!

echo "Registrando el consumo y la memoria."
echo "Fecha, CPU (%), Memoria (%)" > $archivo

while ps -p $pid; do

    ps_out=$(ps -p $pid -o %cpu,%mem --no-header)
    cpu=$(echo $ps_out | awk '{print $1}')
    mem=$(echo $ps_out | awk '{print $2}')
    date=$(date '+%Y-%m-%d  %H:%M:%S')

    echo "$date,$cpu,$mem" >> $archivo
    sleep 1
done
#Archivo de gnuplot
echo "Generando gráfica"

gnu_gen="grafica.gp"
cat > $gnu_gen << EOL
set terminal png
set output 'consumo.png'
set title 'Consumo de CPU y Memoria en 2 minutos'
set xlabel 'Tiempo (Fecha)'
set ylabel 'Porcentaje (%)'
set xdata time
set timefmt '%Y-%m-%d  %H:%M:%S'
plot '$archivo' using 1:2 with lines title 'CPU (%)', '$archivo' using 1:3 with lines title 'Memoria (%)'
EOL
gnuplot $gnu_gen

echo "Gráfica: consumo.png"
