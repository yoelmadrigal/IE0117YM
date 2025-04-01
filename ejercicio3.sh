#!/bin/bash

#Ruta a monitorear
ruta="/home/vboxuser/Documents/laboratorio2"
logs="/home/vboxuser/Documents/laboratorio2/mon.log"
chmod +r+x "ruta"

#Monitoreo del directorio
inotifywait -m -r -e create -e modify -e delete --format '%T %w %f %e' --timefmt '%F %T' "%ruta" | while read event 
do
    echo "$event" >> "$logs"
done
